#include<stdio.h>
#include<stdlib.h>
#include <conio.h>

const int WIDTH = 50;
const int HEIGHT = 20;
int game_over = 1;
enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT 
};
struct Position {
    int x;
    int y;
};
enum Direction current_direction = UP;
struct Position snake_head_position = {25, 10};
void detect_move();
void draw_full_row();
void draw_first_last_item_row(int h);
void build();
void update_head_position();


int main(){
    while(game_over){
        build();
    }
    return 0;
};


void detect_move(){
    if(kbhit()){
        char key = getch();
        switch(key){
            case 'w':
                current_direction = UP;
                break;
            case 's':
                current_direction = DOWN;
                break;
            case 'a':
                current_direction = RIGHT;
                break;
            case 'd':
                current_direction = LEFT;
                break;
            case 'q':
                game_over = 0;
            default:
                break;
        }
    }
    
}

void build(){
    update_head_position();
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

    //build row by height
    for(int h = 0; h <= HEIGHT; h++){
        if(h == 0 || h == HEIGHT){
            draw_full_row();
        } else {
             draw_first_last_item_row(h);
        }
    }

    printf("\n \n \n position x: %d", snake_head_position.x);
    printf("\n position y: %d", snake_head_position.y);
    printf("\n DIRECTION: %d", current_direction);

    detect_move();

};


void update_head_position(){
    switch(current_direction){
        case UP:
            snake_head_position.y --;
            break;
        case DOWN:
            snake_head_position.y ++;
            break;
        case RIGHT:
            snake_head_position.x --;
            break;
        case LEFT:
            snake_head_position.x ++;
            break;
        default:
        break;
    }
}
