#ifndef GAME
#define GAME

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include "ball.h"
#include "paddle.h"

class gameManager{
    private:
        int width, height;
        int score1, score2;
        char up1, up2, down1, down2;
        bool quit;
        Ball *ball;
        Paddle *player1;
        Paddle *player2;
    public:
        gameManager(int, int);
        ~gameManager();
        void scoreInc(Paddle *);
        void Draw();
        void Input();
        void Logic();
        void Run();
};

#endif