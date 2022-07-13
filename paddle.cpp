#include "paddle.h"

Paddle::Paddle(){
    x = 0;
    y =0;
}

Paddle::Paddle(int x, int y){
    origX = x;
    origY = y;
    this->x = x;
    this->y = y;
}

void Paddle::reset(){
    x = origX;
    y = origY;
}

inline int Paddle::getX(){ 
    return x;
}

inline int Paddle::getY(){ 
    return y;
}

void Paddle::moveUp(){
    y--; 
}

void Paddle::moveDown(){
    y++; 
}