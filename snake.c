#include<stdio.h>
#include<stdlib.h>
#include <conio.h>

const int WIDTH = 50;
const int HEIGHT = 20;
struct Position {
    int x;
    int y;
};
enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT 
};
struct Position snake_head_position = {25, 10}; 
void detect_move();
void draw_full_row();
void draw_first_last_item_row(int h);
void build();


int main(){
    build();
    return 0;
};


void detect_move(){
    char key = getch();
    switch(key){
        case 'w':
            snake_head_position.y --;
            build();
            break;
        case 's':
            snake_head_position.y ++;
            build();
            break;
        case 'a':
            snake_head_position.x --;
            build();
            break;
        case 'd':
            snake_head_position.x ++;
            build();
            break;
        default:
            break;
    }
}

void build(){
    system("cls");
    void draw_full_row(){
    for (int i = 0; i <= WIDTH; i++){
        if(i == WIDTH){
                printf("\n");
            } else {
                printf("0");
            }
        }  
    };
    void draw_first_last_item_row(int h){
    for (int i = 0; i < WIDTH; i++){
            if(i == 0){
                printf("0");
            } else if(i == WIDTH -1){
                printf("0 \n");
            } else {
                if(snake_head_position.y == h && snake_head_position.x == i){
                    printf("@");
                } else {
                    printf(" ");
                }
            }
        } 
    };

    //build environment
    for(int h = 0; h <= HEIGHT; h++){
        if(h == 0 || h == HEIGHT){
            draw_full_row();
        } else {
             draw_first_last_item_row(h);
        }
    }
    detect_move();
};
