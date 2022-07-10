#ifndef BALL
#define BALL
# include <time.h>
# include <stdlib.h>

enum Dir {STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};

class Ball{
    private:
        int x,y;
        int origX, origY;
        Dir direction;
    public:
        Ball(int, int);
        void reset();
        void changeDir(Dir);
        void randomDirection();
        inline int getX();
        inline int getY();
        inline Dir getDir();
        void Move();
        
};

#endif