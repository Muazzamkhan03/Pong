#ifndef PADDLE 
#define PADDLE

class Paddle{
    private:
        int x,y;
        int origX, origY;
    public:
        Paddle();
        Paddle(int, int);
        void reset();
        int getX();
        int getY();
        void moveUp();
        void moveDown();
};

#endif