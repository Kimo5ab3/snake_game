#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

const int WIDTH = 50;
const int HEIGHT = 20;
int game_over = 0;
enum Direction { UP, DOWN, LEFT, RIGHT };
struct Position {
  int x;
  int y;
};
struct BodyTail{
  int left;
  int right;
  int top;
  int bottom;
};
enum Direction current_direction = UP;
struct Position snake_head = {25, 10};
struct Position fruit = {25, 10};
int body_counter = 5;
void detect_move();
void draw_full_row();
void draw_first_last_item_row(int h);
void detect_end_of_field();
void set_new_direction();
void set_head_new_position(int coordinate);
void build();
void makeNewFruit();

int main() {
  struct BodyTail bodyTail = {0, 0, 0, 0};
  while (!game_over) {
    build();
    Sleep(10000 / 120);
  }
  return 0;
};

void detect_move_debug() {
  char key = _getch();
  switch (key) {
  case 'w':
    current_direction = UP;
    build();
    break;
  case 's':
    current_direction = DOWN;
    build();
    break;
  case 'a':
    current_direction = RIGHT;
    build();
    break;
  case 'd':
    current_direction = LEFT;
    build();
    break;
  case 'q':
    game_over = 1;
  default:
    break;
  }
}

void detect_move() {
  if (_kbhit()) {
    char key = _getch();
    switch (key) {
    case 'w':
      if (current_direction != DOWN) {
        current_direction = UP;
      }
      break;
    case 's':
      if (current_direction != UP) {
        current_direction = DOWN;
      }
      break;
    case 'a':
      if (current_direction != LEFT) {
        current_direction = RIGHT;
      }

      break;
    case 'd':
      if (current_direction != RIGHT) {
        current_direction = LEFT;
      }

      break;
    case 'q':
      game_over = 1;
    default:
      break;
    }
  }
}

void build() {
  set_new_direction();
  
  system("cls");

  // build rows by height
  for (int h = 0; h < HEIGHT; h++) {
    if (h == 0 || h == HEIGHT - 1) {
      draw_full_row();
    } else {
      draw_first_last_item_row(h);
    }
  }

  printf("\n \n \n position x: %d", snake_head.x);
  printf("\n position y: %d", snake_head.y);
  printf("\n DIRECTION: %d", current_direction);
  printf("\n FRUIT X: %d", fruit.x);
  printf("\n FRUIT Y: %d", fruit.y);

  // detect_move();
  detect_move_debug();

};

void draw_full_row() {
  for (int i = 0; i <= WIDTH; i++) {
    if (i == WIDTH) {
      printf("\n");
    } else {
      printf("0");
    }
  }
};

void draw_first_last_item_row(int h) {
  for (int i = 0; i <= WIDTH; i++) {
    if (i == 0 || i == WIDTH - 1) {
      detect_end_of_field();
      printf("0");
    } else if (i == WIDTH) {
      printf("\n");
    } else {
      if (snake_head.y == h && snake_head.x == i) {
        if(snake_head.x == fruit.x && snake_head.y == fruit.y){
        makeNewFruit();
        printf("X");
      } else {
        printf("o");
      }
      } else if(fruit.y == h && fruit.y == i){
        printf("@");
      } else {
        printf(" ");
      }
    }
  }
};

void set_new_direction() {
  switch (current_direction) {
  case UP:
    snake_head.y--;
    break;
  case DOWN:
    snake_head.y++;
    break;
  case RIGHT:
    snake_head.x--;
    break;
  case LEFT:
    snake_head.x++;
    break;
  default:
    break;
  }
}

void detect_end_of_field() {
  int end_right = snake_head.x == WIDTH - 1;
  int end_left = snake_head.x == 0;
  int end_top = snake_head.y == 0;
  int end_bottom = snake_head.y == HEIGHT - 1;
  if (end_right || end_bottom) {
    set_head_new_position(1);
  } else if (end_left) {
    set_head_new_position(WIDTH - 2);
  } else if (end_top) {
    set_head_new_position(HEIGHT - 2);
  }
}

void set_head_new_position(int coordinate) {
  switch (current_direction) {
  case UP:
    snake_head.y = coordinate;
    break;
  case DOWN:
    snake_head.y = coordinate;
    break;
  case RIGHT:
    snake_head.x = coordinate;
    break;
  case LEFT:
    snake_head.x = coordinate;
    break;
  default:
    break;
  }
}

void makeNewFruit(){
    fruit.x = rand() % WIDTH;
    fruit.y = rand() % HEIGHT;
}
