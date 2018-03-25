#include "main.h"
#include "timer.h"
//#include "ball.h"
#include "boat.h"
#include "water.h"
#include "rocks.h"
#include "cannon.h"
#include "flag.h"
#include "monster.h"
#include "missile.h"
#include "barrel.h"
#include "controls.hpp"
#include "gifts.h"
#include "boss.h"
#include "land.h"
#include "booster.h"
#include "treasure.h"
#include "link.h"
#include "twister.h"
#include "shark.h"

#include<stdlib.h>

using namespace std;


GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

// #######GLOBAL VARIABLES HERE...########
float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0, screen_zoom2 = 1;//for zooming
float side = 0;//for panning
int health = 100;
int no_of_missiles=0;
int deployed[10] = {0};
int fire_up=0;
int monsters_killed = 0;
int disp_booster=0;
int boost_adv = 0;
int hit_land = 0;
int jackpot = 0;
float eye_x,eye_y,eye_z;
float tar_x,tar_y,tar_z;
/**************************
* Customizable functions *
**************************/

//Ball ball1;
Water pond1;
Boat boat1;
Rocks rocks1[20];
Cannon cannon1;
Barrel barrels1[20];
Flag flag1;
Gift gifts1[10];
Monster monsters1[5];
Missile missile1;
Boss boss1;
Land land1,land2,land3;
Booster boost1;
Treasure treasure1;
Link link1;
Twister twister1[10];
Shark shark1;
Shark shark2;
////float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 90;
Timer t60(1.0 / 60);
Timer t10(1.0 / 2);
Timer t20(1.0 / 5);
/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw(GLFWwindow *window, int no) {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);

    // Eye - Location of camera. Don't change unless you are sure!!
    // glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f) + side, 0, 5*sin(camera_rotation_angle*M_PI/180.0f) );
    // // Target - Where is the camera looking at.  Don't change unless you are sure!!
    // glm::vec3 target (side, 0, 0);
    // // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    // glm::vec3 up (0, 1, 0);

    computeMatricesFromInputs(window, boat1.position);
		glm::mat4 ProjectionMatrix = getProjectionMatrix(window);
		glm::mat4 ViewMatrix = getViewMatrix(window);
		glm::mat4 ModelMatrix = glm::mat4(1.0);
		glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

    glm::vec3 eye ( eye_x,eye_y,eye_z);
    // Target - Where ais the camera looking at.  Don't change unless you are sure!!
    glm::vec3 target (tar_x,tar_y,tar_z);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    glm::vec3 up (0, 1, 0);
    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!

    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!

    //glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    //ball1.draw(MVP);
     if(no==1)
     {
       missile1.draw(VP);
     }
    for(int i = 0;i<20;i++)
    {
      rocks1[i].draw(VP);
    }
    for(int i = 0;i<20;i++)
    {
      barrels1[i].draw(VP);
    }

    for(int i = 0;i<10;i++)
    {
      gifts1[i].draw(VP);
    }

    for(int i = 0;i<5;i++)
    {
      monsters1[i].draw(VP);
    }
    if(monsters_killed>=3)
      boss1.draw(VP);
    if(hit_land==0)
      boat1.draw(VP,0);
    else
      boat1.draw(VP,1);
    pond1.draw(VP);
    land1.draw(VP);
    land2.draw(VP);
    shark1.draw(VP);
    shark2.draw(VP);
//    land3.draw(VP);
    if(hit_land==1)
    {
      treasure1.draw(VP);
    }
    if(hit_land==1)
    {
      link1.draw(VP);
    }
    if(hit_land==0)
      flag1.draw(VP);
    if(disp_booster==1)
      boost1.draw(VP);
    if(hit_land==0)
      cannon1.draw(VP,0);
    else
      cannon1.draw(VP,1);
    for(int i=0;i<10;i++)
    if(hit_land==1)
    {
      twister1[i].draw(VP);
    }
}

int type_1=0, type_2=0, type_3=0, type_4=0, type_5=0, type_6 = 0;
int pre=0;
int send_once = 0;
int turn1 = 0;
int turn2 = 0;
void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int up  = glfwGetKey(window, GLFW_KEY_UP);
    int down = glfwGetKey(window, GLFW_KEY_DOWN);
    int jump  = glfwGetKey(window, GLFW_KEY_SPACE);
    int fire = glfwGetKey(window, GLFW_KEY_F);
    int speed_up = glfwGetKey(window, GLFW_KEY_V);
    int zoom_in = glfwGetKey(window, GLFW_KEY_W);
    int zoom_out = glfwGetKey(window, GLFW_KEY_S);
    type_1 = glfwGetKey(window, GLFW_KEY_1);
    type_2 = glfwGetKey(window, GLFW_KEY_2);
    type_3 = glfwGetKey(window, GLFW_KEY_3);
    type_4 = glfwGetKey(window, GLFW_KEY_4);
    type_5 = glfwGetKey(window, GLFW_KEY_5);
    type_6 = glfwGetKey(window, GLFW_KEY_6);
    if(type_1==0 && type_2==0 && type_3==0 && type_4==0 && type_5==0 && type_6==0)
    {
      if(pre==1)type_1=1;
      if(pre==2)type_2=1;
      if(pre==3)type_3=1;
      if(pre==4)type_4=1;
      if(pre==5)type_5=1;
      if(pre==6)type_6=1;
    }
    if(type_1)
    {
      pre=1;
    }
    if(type_2)
    {
      pre=2;
    }
    if(type_3)
    {
      pre=3;
    }
    if(type_4)
    {
      pre=4;
    }
    if(type_5)
    {
      pre=5;
    }
    if(type_6)
    {
      pre=6;
    }

     int cannon_right = glfwGetKey(window, GLFW_KEY_KP_ADD);
     int cannon_left = glfwGetKey(window, GLFW_KEY_KP_SUBTRACT);
    // int zoom_normal = glfwGetKey(window, GLFW_KEY_KP_MULTIPLY);
    // int pan_right = glfwGetKey(window, GLFW_KEY_6);
    // int pan_left = glfwGetKey(window, GLFW_KEY_4);
    //if(boat1.rotation == 360)boat1.rotation = 0;

    boat1.rotation = fmod(boat1.rotation,360.0);
    if((boat1.rotation > 90.0 && boat1.rotation < 270.0)||(boat1.rotation < -90.0 && boat1.rotation > -270.0))
    {
      boat1.head = 1;
    }
    else
    {
      boat1.head = 0;
    }
  //  printf("%lf     %d \n",boat1.rotation, boat1.head);
    if(jump &&  boat1.in_air == 0)
    {
      boat1.in_air = 1;
      boat1.speed_z -= 0.001;
    }
    if (left) {
      if(hit_land==0)
      {
      //  boat1.speed_x -= 0.0005;
        boat1.rotation += 2;
        flag1.rotation -= 2;
        //boat1.speed_y += 0.2;
        cannon1.rotation += 2;
      }
      else
      {
        link1.rotation += 2;
        //boat1.speed_y += 0.2;
        cannon1.rotation += 2;
      }
    }
    if(right) {
      if(hit_land==0)
      {
      //  boat1.speed_x += 0.0005;
        boat1.rotation -= 2;
        flag1.rotation += 2;
        cannon1.rotation -= 2;
    }
    else
    {
      link1.rotation -= 2;
      cannon1.rotation -= 2;
    }
  }
    if(speed_up)
    {
      if(hit_land==0)
      {
        if(boost_adv==1)
        {
          system(" canberra-gtk-play -f  ../music/jump.wav --volume=\"15\"   &");
          if(boat1.speed_z > 0)
           boat1.speed_z += 0.05;
          else
           boat1.speed_z -= 0.05;
          boost_adv=0;
        }
      }
      else
      {
        if(boost_adv==1)
        {
          system(" canberra-gtk-play -f  ../music/jump.wav --volume=\"15\"   &");
          if(link1.speed_z > 0)
           link1.speed_z += 0.05;
          else
           link1.speed_z -= 0.05;
          boost_adv=0;
        }
      }
    }
    if (up) {
      if(hit_land==0)
      {
        if(boat1.speed_z >= -0.07)
          boat1.speed_z -= 0.001;
      }
      else
      {
        if(link1.speed_z >= -0.07)
          link1.speed_z -= 0.0005;
      }
    }
    if(down) {
      if(hit_land==0)
      {
        if(boat1.speed_z <= 0.07)
          boat1.speed_z += 0.001;
      }
      else
      {
        if(link1.speed_z <= 0.07)
        link1.speed_z += 0.0005;
      }
     }
     if (cannon_left) {
       cannon1.rotation -= 2;
     }
     if(cannon_right) {
       cannon1.rotation += 2;
      }
      if(fire && fire_up==0)
      {
        system(" canberra-gtk-play -f  ../music/cannon.wav --volume=\"15\"   &");
        send_once=1;
        missile1.position.x = cannon1.position.x;//*sin((cannon1.rotation)*M_PI/180.0);
        missile1.position.z = cannon1.position.z;//*cos((cannon1.rotation)*M_PI/180.0);
        fire_up=1;
        draw(window,fire_up);
        printf("FIRE_UP %d",fire_up);
        //cannon1     = Cannon(0, 1, 3, COLOR_CANON);
      }
      if(fire && fire_up==1)
      {
        system(" canberra-gtk-play -f  ../music/cannon.wav --volume=\"15\"   &");
        send_once=1;
          missile1.position.x = cannon1.position.x;//*sin((cannon1.rotation)*M_PI/180.0);
          missile1.position.z = cannon1.position.z;//*cos((cannon1.rotation)*M_PI/180.0);
        // missile1.position.x = boat1.position.x;
        // missile1.position.z = boat1.position.z;
        draw(window,fire_up);
        printf("FIRE_UP %d",fire_up);
        //cannon1     = Cannon(0, 1, 3, COLOR_CANON);
      }
      if(health<=0)
      {
        string Result;
        stringstream convert;
        const char *one = "Game Over";
        const char *two = Result.c_str();
        string total( string(one) + two);
        glfwSetWindowTitle(window, total.c_str());
        printf("GAME OVER\n");
        sleep_for(10ns);
        sleep_until(system_clock::now() + 1s);
        quit(window);
      }
}

int h1[20]={0};
int h2[5]={0};
int h3[20]={0};
int h4 = 0;
int h5[5]={0};
int h6[10]={0};
int boss_hit = 0;
int hit_land_once = 0;
float stor_rot=0.0;
void tick_elements() {
  if(hit_land==1)
    missile1.position.y = cannon1.position.y + 0.42;
  if(type_1){
    if(hit_land==0)
    {
      eye_x = boat1.position.x+5*sin(boat1.rotation*3.14f/180.0f);
      eye_y = boat1.position.y+1;
      //eye_y = 0.03 * cos(no_of_ticks2 * 0.5 * M_PI + M_PI) + 1 + boat1.position.y;
      eye_z = boat1.position.z+5*cos(boat1.rotation*3.14f/180.0f);
      tar_x = boat1.position.x+1;
      tar_y = boat1.position.y+0.5;
      tar_z = boat1.position.z+1;
    }
    else
    if(hit_land==1)
    {
      eye_x = link1.position.x+5*sin(link1.rotation*3.14f/180.0f);
      eye_y = link1.position.y+1;
      eye_z = link1.position.z+5*cos(link1.rotation*3.14f/180.0f);
      tar_x = link1.position.x+1;
      tar_y = link1.position.y+0.5;
      tar_z = link1.position.z+1;
    }
      type_1=1;
      type_2=0;
      type_3=0;
      type_4=0;
      type_5=0;
  }
  if(type_6){
    if(hit_land==0)
    {
      eye_x = boat1.position.x+4;
      eye_y = boat1.position.y +1;
      eye_z = boat1.position.z;
      tar_x = boat1.position.x;
      tar_y = boat1.position.y;
      tar_z = boat1.position.z;
    }
    else
    if(hit_land==1)
    {
      eye_x = link1.position.x+4;
      eye_y = link1.position.y+1;
      eye_z = link1.position.z;
      tar_x = link1.position.x;
      tar_y = link1.position.y;
      tar_z = link1.position.z;
    }
      type_6=1;
      type_1=0;
      type_2=0;
      type_3=0;
      type_4=0;
      type_5=0;
  }

  if(type_4){
    if(hit_land==0)
    {
      eye_x = boat1.position.x+1*sin(boat1.rotation*3.14f/180.0f);
      eye_y = boat1.position.y+0.5;
      eye_z = -(boat1.position.z+1*cos(boat1.rotation*3.14f/180.0f));
      tar_x = 10000*sin(boat1.rotation*3.14f/180.0f);
      tar_y = boat1.position.y+0.5;
      tar_z = 10000*cos(boat1.rotation*3.14f/180.0f);
    }
    else
    {
      eye_x = link1.position.x+1*sin(link1.rotation*3.14f/180.0f);
      eye_y = link1.position.y+0.5;
      eye_z = -(link1.position.z+1*cos(link1.rotation*3.14f/180.0f));
      tar_x = 10000*sin(link1.rotation*3.14f/180.0f);
      tar_y = link1.position.y+0.5;
      tar_z = 10000*cos(link1.rotation*3.14f/180.0f);
    }
      type_1=0;
      type_2=0;
      type_3=0;
      type_5=0;
  }
  if(type_5){
    if(hit_land==0)
    {
      eye_x = 0;
      eye_y = 5;
      eye_z = 5;
      tar_x = boat1.position.x;
      tar_y = boat1.position.y;
      tar_z = boat1.position.z;
    }
    else
    {
      eye_x = 0;
      eye_y = 5;
      eye_z = 5;
      tar_x = link1.position.x;
      tar_y = link1.position.y;
      tar_z = link1.position.z;
    }
      type_1=0;
      type_2=0;
      type_3=0;
      type_4=0;

  }
  if(type_3){
    if(hit_land==0)
    {
      eye_x = boat1.position.x;
      eye_y = boat1.position.y+10;
      eye_z = boat1.position.z+1;
      tar_x = boat1.position.x;
      tar_y = boat1.position.y;
      tar_z = boat1.position.z;
    }
    else
    {
      eye_x = link1.position.x;
      eye_y = link1.position.y+10;
      eye_z = link1.position.z+1;
      tar_x = link1.position.x;
      tar_y = link1.position.y;
      tar_z = link1.position.z;
    }
      type_1=0;
      type_2=0;
      type_5=0;
      type_4=0;
  }
  if(type_2)
  {
    if(hit_land==0)
    {
        tar_x = boat1.position.x - 10000*(3*sin(boat1.rotation*M_PI/180.0));
        tar_y=boat1.position.y;
        tar_z=boat1.position.z - 10000*(3*cos(boat1.rotation*M_PI/180.0));
        eye_x = boat1.position.x;
        eye_y =boat1.position.y + 1;
        eye_z = boat1.position.z;
    }
    else
    {
      tar_x = link1.position.x - 10000*(3*sin(boat1.rotation*M_PI/180.0));
      tar_y=link1.position.y;
      tar_z=link1.position.z - 10000*(3*cos(boat1.rotation*M_PI/180.0));
      eye_x = link1.position.x;
      eye_y =link1.position.y + 1;
      eye_z = link1.position.z;
    }

  }
    boat1.tick();
    link1.tick();
    for(int i = 0;i<10;i++)
      twister1[i].tick();
    boost1.rotation += 5;
    if(fire_up==1)
    {
      //printf("%f %f \n",missile1.position.x, missile1.position.z);
      if(send_once==1)
      {
      stor_rot=cannon1.rotation;
       missile1.tick(cannon1.rotation);
       send_once=0;
     }
     else
     {
       missile1.tick(stor_rot);
     }
    }
    if((detect_collision(boat1.bounding_box(), land1.bounding_box())))
    {///REQUIRE CHANGES IN DETECT_COLLISIO
      if(hit_land_once==0)
      {
        link1.position.x = boat1.position.x;
        link1.position.z = boat1.position.z - 1;
      }
      boat1.speed_z=0;
      hit_land =1;
      hit_land_once =1;
    }
    if((detect_collision(boat1.bounding_box(), land2.bounding_box())))
    {///REQUIRE CHANGES IN DETECT_COLLISIO
      if(hit_land_once==0)
      {
        link1.position.x = boat1.position.x;
        link1.position.z = boat1.position.z - 1;
      }
      boat1.speed_z=0;
      hit_land=1;
      hit_land_once =1;
    }
    // if((detect_collision(boat1.bounding_box(), land3.bounding_box())))
    // {///REQUIRE CHANGES IN DETECT_COLLISIO
    //   if(hit_land_once==0)
    //   {
    //     link1.position.x = boat1.position.x;
    //     link1.position.z = boat1.position.z - 1;
    //   }
    //   boat1.speed_z=0;
    //   hit_land =1;
    //   hit_land_once =1;
    // }
    if(detect_collision(link1.bounding_box(), treasure1.bounding_box()))
    {///REQUIRE CHANGES IN DETECT_COLLISIO
      //treasure1.rotation += 90;

      string Result;
      stringstream convert;
      const char *one = "YOU WON!!!";
      const char *two = Result.c_str();
      string total( string(one) + two);
      glfwSetWindowTitle(window, total.c_str());
      printf("GAME OVER, YOU WON!!!\n");
      sleep_for(10ns);
      sleep_until(system_clock::now() + 1s);
      quit(window);
    }

    if((detect_collision(boat1.bounding_box(), boost1.bounding_box()))&&disp_booster==1)
    {///REQUIRE CHANGES IN DETECT_COLLISIO
      system(" canberra-gtk-play -f  ../music/gift.wav --volume=\"15\"   &");
      disp_booster=0;
      boost_adv = 1;
    }
        if((detect_collision(boost1.bounding_box(), link1.bounding_box()))&&disp_booster==1)
        {///REQUIRE CHANGES IN DETECT_COLLISIO
          system(" canberra-gtk-play -f  ../music/gift.wav --volume=\"15\"   &");
          disp_booster=0;
          boost_adv = 1;
        }

    if((detect_collision(missile1.bounding_box(), boss1.bounding_box()))&&monsters_killed>=3)
    {///REQUIRE CHANGES IN DETECT_COLLISIO
      system(" canberra-gtk-play -f  ../music/boss.wav --volume=\"15\"   &");
      boss_hit++;
      if(boss_hit==3)
      {
        boss1.position.x = 200;
        boss1.position.z = 200;
        missile1.position.x = cannon1.position.x;
        missile1.position.z = cannon1.position.z;
        fire_up=0;
      }
      else
      {
          missile1.position.x = cannon1.position.x;
          missile1.position.z = cannon1.position.z;
          fire_up=0;
        //  boss.position.x = -rand()%40 + rand()%40;
        //  boss.position.z = -rand()%40 + rand()%40;
      }
    }
    if((detect_collision(boat1.bounding_box(), boss1.bounding_box()))&&monsters_killed>=3)
    {///REQUIRE CHANGES IN DETECT_COLLISION
      if(h4==0)
      {
        health -= 50;
        h4=1;
      }
      //boat1.speed_z = -boat1.speed_z;
    }
    else
    {
      h4=0;
    }

    for(int i=0;i<5;i++)
    {
      if(detect_collision(missile1.bounding_box(), monsters1[i].bounding_box()))
      {
        //system(" canberra-gtk-play -f  ../music/monster_boat.wav --volume=\"15\"   &");
        ///REQUIRE CHANGES IN DETECT_COLLISIO
        disp_booster=1;
        boost1.position.x = monsters1[i].position.x;
        boost1.position.z = monsters1[i].position.z;
        monsters_killed++;
        missile1.position.x = cannon1.position.x;
        missile1.position.z = cannon1.position.z;
        fire_up=0;
          monsters1[i].position.x = -rand()%30 + rand()%30;
          monsters1[i].position.z = -rand()%30 + rand()%30;
      }
    }

        for(int i=0;i<10;i++)
        {
          if(detect_collision(missile1.bounding_box(), twister1[i].bounding_box()))
          {
            //system(" canberra-gtk-play -f  ../music/monster_boat.wav --volume=\"15\"   &");
            ///REQUIRE CHANGES IN DETECT_COLLISIO
            disp_booster=1;
            boost1.position.x = twister1[i].position.x;
            boost1.position.z = twister1[i].position.z;
            monsters_killed++;
            missile1.position.x = cannon1.position.x;
            missile1.position.z = cannon1.position.z;
            fire_up=0;
              twister1[i].position.x = -rand()%10 + rand()%10 + 100;
              twister1[i].position.z = -rand()%10 + rand()%10 + 100;
          }
        }


    flag1.position.x = boat1.position.x;
    flag1.position.y = boat1.position.y;
    flag1.position.z = boat1.position.z;
    flag1.rotation = boat1.rotation;
    if(hit_land==0)
    {
     cannon1.position.x = boat1.position.x;
     cannon1.position.y = boat1.position.y;
     cannon1.position.z = boat1.position.z;
}
else
{
  cannon1.position.x = link1.position.x;
  cannon1.position.y = link1.position.y;
  cannon1.position.z = link1.position.z;

}
     //cannon1.rotation = boat1.rotation;
    for(int i = 0; i<20;i++)
     {
       if(detect_collision(boat1.bounding_box(), rocks1[i].bounding_box()))
       {///REQUIRE CHANGES IN DETECT_COLLISION
         if(h1[i]==0)
         {
           health -= 5;h1[i]=1;
         }
         boat1.speed_z = 0;
       }
       else
       {
         h1[i]=0;
       }
     }
     for(int i = 0; i<10;i++)
      {
        gifts1[i].tick();
      }

      for(int i = 0; i<10;i++)
       {
         if(detect_collision(boat1.bounding_box(), gifts1[i].bounding_box()))
         {///REQUIRE CHANGES IN DETECT_COLLISIO
           system(" canberra-gtk-play -f  ../music/jump.wav --volume=\"15\"   &");
           if(boat1.speed_z > 0)
            boat1.speed_z += 0.05;
           else
            boat1.speed_z -= 0.05;
             gifts1[i].position.x = -rand()%30 + rand()%30;
             gifts1[i].position.z = -rand()%30 + rand()%30;
         }
       }
       for(int i = 0; i<10;i++)
        {
          if(detect_collision(link1.bounding_box(), gifts1[i].bounding_box()))
          {///REQUIRE CHANGES IN DETECT_COLLISIO
            system(" canberra-gtk-play -f  ../music/jump.wav --volume=\"15\"   &");
            if(link1.speed_z > 0)
             link1.speed_z += 0.05;
            else
             link1.speed_z -= 0.05;
              gifts1[i].position.x = -rand()%30 + rand()%30;
              gifts1[i].position.z = -rand()%30 + rand()%30;
          }
        }
      for(int i = 0; i<5;i++)
      {
        if(detect_collision(boat1.bounding_box(), monsters1[i].bounding_box()))
        {///REQUIRE CHANGES IN DETECT_COLLISION
          if(h2[i]==0)
          {
            health -= 25;h2[i]=1;
          }
          //boat1.speed_z = -boat1.speed_z;
        }
        else
        {
          h2[i]=0;
        }
      }

      for(int i = 0; i<5;i++)
      {
        if(detect_collision(link1.bounding_box(), monsters1[i].bounding_box()))
        {///REQUIRE CHANGES IN DETECT_COLLISION
          if(h5[i]==0)
          {
            health -= 25;h5[i]=1;
          }
          //boat1.speed_z = -boat1.speed_z;
        }
        else
        {
          h5[i]=0;
        }
      }
      shark1.tick();
      shark2.tick();
      for(int i = 0; i<10;i++)
      {
        if(detect_collision(link1.bounding_box(), twister1[i].bounding_box()))
        {///REQUIRE CHANGES IN DETECT_COLLISION
          if(h6[i]==0)
          {
            health -= 15;h6[i]=1;
          }
          //boat1.speed_z = -boat1.speed_z;
        }
        else
        {
          h6[i]=0;
        }
      }

      for(int i = 0; i<20;i++)
      {
        if(detect_collision(boat1.bounding_box(), barrels1[i].bounding_box()))
        {///REQUIRE CHANGES IN DETECT_COLLISION
          if(h3[i]==0)
          {
            system(" canberra-gtk-play -f  ../music/gift.wav --volume=\"15\"   &");
            health += 10;h3[i]=1;
            //boat1.speed_z = 0;
            barrels1[i].position.x = -rand()%30 + rand()%30;
            barrels1[i].position.z = -rand()%30 + rand()%30;
          }
          //boat1.speed_z = -boat1.speed_z;
        }
        else
        {
          h3[i]=0;
        }
      }

      for(int i = 0; i<20;i++)
      {
        if(detect_collision(link1.bounding_box(), barrels1[i].bounding_box()))
        {///REQUIRE CHANGES IN DETECT_COLLISION
          if(h3[i]==0)
          {
            system(" canberra-gtk-play -f  ../music/gift.wav --volume=\"15\"   &");

            health += 10;h3[i]=1;
            //boat1.speed_z = 0;
            barrels1[i].position.x = -rand()%30 + rand()%30;
            barrels1[i].position.z = -rand()%30 + rand()%30;
          }
          //boat1.speed_z = -boat1.speed_z;
        }
        else
        {
          h3[i]=0;
        }
      }
    //  treasure1.rotation=90;
    // // //camera_rotation_angle += 0.1;
}


void wind(float wind_x, float wind_z)
{
  int x = rand()%1000;
  if(x<1001 && x >= 0 && hit_land==0)
  {
    printf("WIND!!!!!  WIND!!!!!\n");printf("WIND!!!!!  WIND!!!!!\n");printf("WIND!!!!!  WIND!!!!!\n");printf("WIND!!!!!  WIND!!!!!\n");
    if(wind_x < 0 && wind_z < 0)
    {
      printf("FROM NW\n");
      boat1.position.x += 0.02;
      boat1.position.z += 0.02;
      flag1.rotation = 45;
    //  boat1.object[4]->rotation =  90;
    }
    if(wind_x < 0 && wind_z > 0)
    {
      printf("FROM SW\n");
      boat1.position.x += 0.02;
      boat1.position.z -= 0.02;
      flag1.rotation = 135;
    }
    if(wind_x > 0 && wind_z < 0)
    {
      printf("FROM NE\n");
      boat1.position.x -= 0.02;
      boat1.position.z += 0.02;
      flag1.rotation = 315;
    }
    if(wind_x > 0 && wind_z > 0)
    {
      printf("FROM SE\n");
      boat1.position.x -= 0.02;
      boat1.position.z -= 0.02;
      flag1.rotation = 225;
    }
  }
}
/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models
    //ball1       = Ball(0, 0, COLOR_RED);
    boat1       = Boat(0, 1, 3, COLOR_RED);
    flag1       = Flag(0, 1, 3, COLOR_FLAG);
    pond1       = Water(0, 0, COLOR_WATERBLUE);
    cannon1     = Cannon(0, 1, 3, COLOR_CANON);
    boss1       = Boss(0, 1, -10, COLOR_BLACK);
    land1       = Land(10,10, -50, COLOR_LAND);
    land2       = Land(-10,10, -40, COLOR_LAND);
    shark1      = Shark(-2,1, -9, COLOR_LAND);
    shark2      = Shark(2,1, -7, COLOR_LAND);
    boost1      = Booster(0, 2, -100, COLOR_BOOST);
    treasure1   = Treasure(0.6,0.7,-32, COLOR_GOLD);
    for(int i =0;i<10;i++)
    {
      twister1[i]   = Twister((-rand()%15 + rand()%15)+0.6,1.1,(-rand()%15 + rand()%15)-27, COLOR_GOLD);
    }
    link1       = Link(10,1.1,-50,COLOR_BOOST);

    for(int i=0;i<20;i++)
    {
      rocks1[i] = Rocks((-rand()%40) + (rand()%40),0.90,(-rand()%30)+(rand()%30), COLOR_ROCKS);
    }
    missile1 = Missile(0,1.19,2, COLOR_BLACK2);
    for(int i=0;i<20;i++)
    {
      barrels1[i] = Barrel((-rand()%40) + (rand()%40),1,(-rand()%30)+(rand()%30), COLOR_GOLD);
    }

    for(int i=0;i<10;i++)
    {
      gifts1[i] = Gift((-rand()%30) + (rand()%30),1,(-rand()%30)+(rand()%30), COLOR_RED2);
    }
    // for(int i=0;i<5;i++)
    // {
    //  gifts1[i] = Gift((-rand()%30) + (rand()%30), 2, (-rand()%30) + (rand()%30), COLOR_CANON);
    // }
    for(int i=0;i<5;i++)
    {
      int no = rand()%2;
      monsters1[i] = Monster((-rand()%30) + (rand()%30),1,(-rand()%20)+(rand()%20), COLOR_BLACK,no);
    }
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 1200;
    int height = 600;

    window = initGLFW(width, height);

    initGL (window, width, height);
    int wobble = 0;
    int winder = 0;
    int generate_wind = 0;
    float wind_x, wind_z;
    /* Draw in loop */
    int no_of_ticks = 0;
    while (!glfwWindowShouldClose(window)) {
        // // Process timers
        if (t10.processTick())
        {

          land1.position.x = 10;
          land1.position.z = -30;
          land2.position.x = -10;
          land2.position.z = -30;
          if(monsters_killed>=3)
            boss1.tick(boat1.position);
          for(int i = 0;i<5;i++)
          {
            monsters1[i].tick();
          }
          for(int i = 0;i<20;i++)
          {
            barrels1[i].tick();
          }
          //
          // if(wobble==0 && boat1.in_air == 0)
          // {
          //   wobble =1;
          //   boat1.position.y = 1.01;
          // }
          // else if(wobble == 1 && boat1.in_air == 0)
          // {
          //   boat1.position.y = 0.98;
          //   wobble = 0;
          // }
        }
        if(t20.processTick())
        {
          no_of_ticks++;
          boat1.position.y = 0.03 * sin(no_of_ticks * 0.5 * M_PI) + 1;
          for(int i = 0;i<20;i++)
          {
            barrels1[i].position.y = 0.02 * sin(no_of_ticks*0.5*M_PI) + 1;
          }
        }
         if (t60.processTick()) {

             land1.position.x = 10;
             land1.position.z = -40;
           winder++;
           if(winder > 600 && winder < 700)
           {
             if(generate_wind==0)
             {
               wind_x = -rand()%100 + rand()%100;
               wind_z = -rand()%100 + rand()%100;
               generate_wind=1;
             }
             wind(wind_x, wind_z);
           }
           else
           {
             printf("\n");
           }
           if(winder == 700){
             generate_wind = 0;
             winder = 0;
           }

            // 60 fps
            // OpenGL Draw commands
            draw(window,fire_up);
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);
            tick_elements();
            tick_input(window);
            printf("Monsters Killed %d\n",monsters_killed);
            string Result;
            stringstream convert;
            //cout << "nonedit score:" << score << endl;
            convert << health;
            Result = convert.str();
              const char *one = "Health: ";
              const char *two = Result.c_str();
              string total( string(one) + two);
              glfwSetWindowTitle(window, total.c_str());
        }
        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }
    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x)*2 < (a.width + b.width)) &&
           (abs(a.z - b.z)*2 < (a.height + b.height));
}

void reset_screen() {
    float top    = screen_center_y + 8 / screen_zoom;
    float bottom = screen_center_y - 8 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}

void zoom(float scale)
{
      float top    = screen_center_y + 4 / screen_zoom2;
      float bottom = screen_center_y - 4 / screen_zoom2;
      float left   = screen_center_x - 4 / screen_zoom2;
      float right  = screen_center_x + 4 / screen_zoom2;
      Matrices.projection = glm::ortho(left*scale, right*scale, bottom*scale, top*scale, 0.1f, 500.0f);
}
