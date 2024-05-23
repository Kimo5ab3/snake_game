#include<stdio.h>
#include<stdlib.h>
#include <conio.h>

const int WIDTH = 50;
const int HEIGHT = 20;

//build environment
void build_environment(){
    // clear screen every loop
    system("cls");

    //draw full row
    void full_row(){
    for (int i = 0; i <= WIDTH; i++){
        if(i == WIDTH){
                printf("\n");
            } else {
                printf("0");
            }
        }  
    };
    //draw first and last sign in a row
    void draw_first_last_row(){
    for (int i = 0; i < WIDTH; i++){
            if(i == 0){
                printf("0");
            } else if(i == WIDTH -1){
                printf("0 \n");
            } else {
                printf(" ");
            }
        } 
    };

    //draw row by height
    for(int h = 0; h <= HEIGHT; h++){
        if(h == 0 || h == HEIGHT){
            full_row();
        } else {
             draw_first_last_row();
        }
    }
};

void detect_move(){
    char key = getch();
    switch(key){
        case 'w':
            printf("UP");
            break;
        case 's':
            printf("DOWN");
            break;
        case 'a':
            printf("LEFT");
            break;
        case 'd':
            printf("RIGHT");
            break;
        default:
            break;
    }
}




int main(){
    while(1){
        build_environment();
        detect_move();
    }
    
    return 0;
};