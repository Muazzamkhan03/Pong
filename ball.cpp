#include "ball.h"

Ball::Ball(int x, int y){
    origX = x;
    origY = y;
    this -> x = x;
    this -> y = y;
    direction = STOP;
}

void Ball::reset(){
    this-> x = origX;
    this-> y = origY;
    direction = STOP;
}

void Ball::changeDir(Dir newDir){
    direction = newDir;
}

void Ball::randomDirection(){
    int n;
    srand(time(NULL));
    n = (rand()%6) + 1;
    direction = (Dir)n;
}

int Ball::getX(){ 
    return x; 
}

int Ball::getY(){ 
    return y; 
}

Dir Ball::getDir(){ 
    return direction; 
}

void Ball::Move(){
    switch(direction){
        case STOP:
            break;
        case LEFT:
            x--;
            break;
        case UPLEFT:
            x--;
            y--;
            break;
        case DOWNLEFT:
            x--;
            y++;
            break;
        case RIGHT:
            x++;
            break;
        case UPRIGHT:
            x++;
            y--;
            break;
        case DOWNRIGHT:
            x++;
            y++;
            break;
        default:
            break;
    }
}
