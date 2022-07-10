# include <iostream>
# include <time.h>

#ifdef _WIN32
    # include <conio.h>
#else
    # include <unistd.h>
#endif

enum Dir {STOP = 0, LEFT = 1, UPLEFT = 2, DOWNLEFT = 3, RIGHT = 4, UPRIGHT = 5, DOWNRIGHT = 6};

class Ball{
    private:
        int x,y;
        int origX, origY;
        Dir direction;
    public:
        Ball(int x, int y){
            origX = x;
            origY = y;
            this -> x = x;
            this -> y = y;
            direction = STOP;
        }
        void reset(){
            this-> x = origX;
            this-> y = origY;
            direction = STOP;
        }
        void changeDir(Dir newDir){
            direction = newDir;
        }
        void randomDirection(){
            int n;
            srand(time(NULL));
            n = (rand()%6) + 1;
            direction = (Dir)n;
        }
        inline int getX(){ return x; }
        inline int getY(){ return y; }
        inline Dir getDir(){ return direction; }
        void Move(){
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
        friend std::ostream& operator<<(std::ostream& out, Ball b){
            out<<"Ball ["<<b.x<<","<<b.y<<"]"<<"["<<b.direction<<"]"<<std::endl;
            return out;
        }
};

class Paddle{
    private:
        int x,y;
        int origX, origY;
    public:
        Paddle(){
            x = 0;
            y =0;
        }
        Paddle(int x, int y){
            origX = x;
            origY = y;
            this->x = x;
            this->y = y;
        }
        void reset(){
            x = origX;
            y = origY;
        }
        inline int getX(){ return x;}
        inline int getY(){ return y;}
        inline void moveUp(){ y--; }
        inline void moveDown(){ y++; }
        friend std::ostream& operator<<(std::ostream& out, Paddle b){
            out<<"Paddle ["<<b.x<<","<<b.y<<"]"<<std::endl;
            return out;
        }
};

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
        gameManager(int w, int h){
            srand(time(NULL));
            quit = 0;
            up1 = 'w';
            up2 = 'o';
            down1 = 's';
            down2 = 'l';
            score1 = score2 = 0;
            width = w;
            height = h;
            ball = new Ball(w/2, h/2);
            player1 = new Paddle(1, (h/2)-3);
            player2 = new Paddle(w-2, (h/2)-3);
        }

        ~gameManager(){
            delete ball;
            delete player1;
            delete player2;
        }

        void scoreInc(Paddle *p){
            if(p == player1){
                score1++;
            }
            else if(p == player2){
                score2++;
            }
            ball->reset();
            player1->reset();
            player2->reset();
        }

        void Draw(){
            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif

            for(int i=0; i<width+2; i++){
                std::cout<<"#";
            }

            std::cout<<'\n';
            for(int i=0; i<height;i++){
                for(int j=0; j<width;j++){
                    int ballX = ball->getX();
                    int ballY = ball->getY();
                    int player1X = player1 -> getX();
                    int player2X = player2 -> getX();
                    int player1Y = player1 -> getY();
                    int player2Y = player2 -> getY();

                    if(j==0){
                        std::cout<<"#";
                    }

                    if(ballX==j && ballY == i){
                        std::cout<<"O";
                    }
                    else if(player1X == j && player1Y == i){
                        std::cout<<"|";
                    }
                    else if(player2X == j && player2Y == i){
                        std::cout<<"|";
                    }

                    else if(player1X == j && player1Y +1  == i){
                        std::cout<<"|";
                    }
                    else if(player1X == j && player1Y +2  == i){
                        std::cout<<"|";
                    }
                    else if(player1X == j && player1Y +3  == i){
                        std::cout<<"|";
                    }
                    else if(player2X == j && player2Y +1  == i){
                        std::cout<<"|";
                    }
                    else if(player2X == j && player2Y +2  == i){
                        std::cout<<"|";
                    }
                    else if(player2X == j && player2Y +3  == i){
                        std::cout<<"|";
                    }

                    else{
                        std::cout<<" ";
                    }

                    if(j==(width-1)){
                        std::cout<<"#";
                        std::cout<<'\n';
                    }
                    
                }

            }

            for(int i=0; i<width+2; i++){
                std::cout<<"#";
            }
            std::cout<<'\n';

            std::cout<<"    SCORES "<<std::endl;
            std::cout<<"Player 1: "<<score1<<std::endl;
            std::cout<<"Player 2: "<<score2<<std::endl;
        }

        void Input(){
            ball->Move();
            int ballX = ball->getX();
            int ballY = ball->getY();
            int player1X = player1 -> getX();
            int player2X = player2 -> getX();
            int player1Y = player1 -> getY();
            int player2Y = player2 -> getY();
            
            

            if(_kbhit){
                char current = _getch();
                
                if(ball->getDir()==STOP){
                    ball->randomDirection();
                }
                if(current==up1){
                    if(player1Y>0){
                        player1->moveUp();
                    }
                }
                if(current==up2){
                    if(player2Y>0){
                        player2->moveUp();
                    }
                }
                if(current==down1){
                    if(player1Y+4 <height){
                        player1->moveDown();
                    }
                }
                if(current==down2){
                    if(player2Y +4 <height){
                        player2->moveDown();
                    }
                }
                
                if(current=='q'){
                    quit = 1;
                }
            }
            
        }

        void Logic(){
            int ballX = ball->getX();
            int ballY = ball->getY();
            int player1X = player1 -> getX();
            int player2X = player2 -> getX();
            int player1Y = player1 -> getY();
            int player2Y = player2 -> getY();

            //Collision on Left Paddle
            for(int i=0; i<4; i++){
                if(ballX==player1X+1){
                    if(ballY == player1Y + i){
                        ball->changeDir((Dir)((rand()%3)+4));
                    }
                }
            }

            //Collision on Right Paddle
            for(int i=0; i<4; i++){
                if(ballX==player2X-1){
                    if(ballY == player2Y + i){
                        ball->changeDir((Dir)((rand()%3)+1));
                    }
                }
            }

            //Collision on bottom wall
            if(ballY==height-1){
                ball->changeDir(ball->getDir()==DOWNRIGHT?UPRIGHT:UPLEFT);
            }
            //Collision on top wall
            if(ballY==0){
                ball->changeDir(ball->getDir()==UPRIGHT?DOWNRIGHT:DOWNLEFT);
            }
            //Collision on right wall
            if(ballX==width-1){
                scoreInc(player1);
            }
            //Collision on left wall
            if(ballX==0){
                scoreInc(player2);
            }
        }

        void Run(){
            while(!quit){
                Draw();
                Input();
                Logic();
            }
        }
};

int main(){
    gameManager game(40, 20);
    game.Run();


}