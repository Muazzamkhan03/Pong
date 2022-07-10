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
        inline int getX();
        inline int getY();
        inline void moveUp();
        inline void moveDown();
};

#endif