#ifndef PONG_GAME
#define PONG_GAME

#define BOARD_HEIGHT 8
#define BOARD_WIDTH 8

#define X_CENTER 4
#define Y_CENTER 4

#define PADDLE_HEIGHT 3
#define PADELE_WIDTH 1

#define BALL_HEIGHT 1
#define BALL_WIDTH 1

#define X_RIGHT_PADDLE 7
#define Y_RIGHT_PADDLE 2

#define X_LEFT_PADDLE 0
#define Y_LEFT_PADDLE 2


enum Direction {stay, left_up, left_down, right_up, right_down};


inline int GameBoard[BOARD_HEIGHT][BOARD_WIDTH];

class Regtangle{
    protected:
        int width, height;
        int i, j;

    public:
        Regtangle(int width, int height, int i, int j);

        int getWidth() { return width; }
        int getHeight() { return height; }

        int getI() { return i; }
        int getJ() { return j; }

        void setWidth(int x);
        void setHeight(int y);

        void setI(int i);
        void setJ(int j);

};


class Paddle: public Regtangle{
    private:
        bool is_right;
    public:
        Paddle(bool is_right);
        void initPaddle();
        void goUp();
        void goDown();

};


class Ball: public Regtangle{
    private:
        Direction direction;
    public:
        Ball();
        void initBall();
        void correctPaddleLight(Paddle right_paddle, Paddle left_paddle);
        bool goUpRight();
        bool goUpLeft();
        bool goDownRight();
        bool goDownLeft();
        void moving(Paddle right_paddle, Paddle left_paddle);

};

#endif

