#include <iostream>

#include <simple2d.h>

#include "Location.hpp"
#include "Snake.hpp"

using namespace std;

Snake* snake = NULL;

void update() {

    queue<Location> temp_q = snake->joint_q;

    while(temp_q.size()>0)
    {
        Location loc = temp_q.front();
        temp_q.pop();
        //cout<<"loc.x = "<<loc.x<<endl;
        //cout<<"loc.y = "<<loc.y<<endl;
        S2D_DrawCircle(loc.x, loc.y, snake->size, 16,   1,   1,   1, 0.6);
    }
    snake->update();
}

void render() {
}

void print_mouse_button(int e) {
  switch (e) {
    case S2D_MOUSE_LEFT:
      puts("Button left");
      break;
    case S2D_MOUSE_MIDDLE:
      puts("Button middle");
      break;
    case S2D_MOUSE_RIGHT:
      puts("Button right");
      break;
    case S2D_MOUSE_X1:
      puts("Button X1");
      break;
    case S2D_MOUSE_X2:
      puts("Button X2");
      break;
  }
}

void on_key(S2D_Event e) {
  switch (e.type) {
    case S2D_KEY_DOWN:
      printf("Key down: %s\n", e.key);
      //if (strcmp(e.key, "Escape") == 0) S2D_Close(window);
      if (strcmp(e.key, "W") == 0) snake->direction = 0;
      if (strcmp(e.key, "D") == 0) snake->direction = 1;
      if (strcmp(e.key, "S") == 0) snake->direction = 2;
      if (strcmp(e.key, "A") == 0) snake->direction = 3;
      break;

    case S2D_KEY_HELD:
      printf("Key held: %s\n", e.key);
      break;

    case S2D_KEY_UP:
      printf("Key up: %s\n", e.key);
      break;
  }
}


void on_mouse(S2D_Event e) {
  puts("=== Mouse Event ===");

  switch (e.type) {
    case S2D_MOUSE_DOWN:
      puts("Mouse down");
      print_mouse_button(e.button);
      snake->eat();
      if (e.dblclick)
        puts("Double click");
      break;

    case S2D_MOUSE_UP:
      puts("Mouse up");
      print_mouse_button(e.button);
      if (e.dblclick) 
        puts("Double click");
      break;

    case S2D_MOUSE_SCROLL:
      puts("Mouse scroll");
      if (e.direction == S2D_MOUSE_SCROLL_NORMAL) {
        puts("Direction normal");
      } else if (e.direction == S2D_MOUSE_SCROLL_INVERTED) {
        puts("Direction inverted");
      }
      printf("delta x: %i\ndelta y: %i\n", e.delta_x, e.delta_y);
      break;

    case S2D_MOUSE_MOVE:
      puts("Mouse movement");
      printf("delta x: %i\ndelta y: %i\n", e.delta_x, e.delta_y);
      break;
  }

  if (e.type != S2D_MOUSE_SCROLL) printf("x: %i, y: %i\n", e.x, e.y);
}


int main(int iArgc, char** cppArgv)
{

    snake = new Snake(500,500);

    S2D_Diagnostics(true);

    S2D_Window *window;


    window = S2D_CreateWindow("Simple 2D — Test Card", 600, 500, update, render, S2D_RESIZABLE);

window->on_key        = on_key;

    window->on_mouse      = on_mouse;

    window->fps_cap = 15;

    S2D_Show(window);

    S2D_FreeWindow(window);

    return 0;
}

