#include "ponggame.h"


//Regtangle constructor
Regtangle::Regtangle(int width, int height, int i, int j){
    this->width = width;
    this->height = height;
    this->i = i;
    this->j = j;
}

void Regtangle::setWidth(int x){
    this->width = x;
} 

void Regtangle::setHeight(int y){
    this->height = y;
} 

void Regtangle::setI(int i){
    this->i = i;
}

void Regtangle::setJ(int j){
    this->j = j;
}

void Regtangle::tick(int x_size, int y_size, int i, int j){
    setI(i);
    setJ(j);
}


// Padlle constructor
Paddle::Paddle(bool is_right): Regtangle(PADELE_WIDTH, PADDLE_HEIGHT, X_RIGHT_PADDLE, Y_RIGHT_PADDLE){
    this->is_right = is_right;
    initPaddle();
}

void Paddle::initPaddle(){
    if(is_right){
        i = X_RIGHT_PADDLE;
        j = Y_RIGHT_PADDLE;
    }
    else {
        i = X_LEFT_PADDLE;
        j = Y_LEFT_PADDLE;
    }

    Board[i][j] = 1;
    Board[i][j + 1] = 1;
    Board[i][j + 2] = 1;
}

void Paddle::goUp(){
    int upper_bound = j + 3;
    if(upper_bound < BOARD_HEIGHT){
        Board[i][j] = 0;
        Board[i][j + 3] = 1;
        j += 1;
    }
}

void Paddle::goDown(){
    int lower_bound = j - 1;
    if(lower_bound >= 0){
        Board[i][j + 2] = 0;
        Board[i][j - 1] = 1;
        j -= 1;
    }
}

//Ball construnctor
Ball::Ball(): Regtangle(BALL_WIDTH, BALL_HEIGHT, X_CENTER, Y_CENTER){
    initBall();
}

void Ball::initBall(){
    Board[i][j] = 0;
    i = X_CENTER;
    j = Y_CENTER;
    Board[i][j] = 1;
    direction = right_up;
}

bool Ball::goUpRight(){
    if(j + 1 < BOARD_HEIGHT && i + 1 < BOARD_WIDTH){
        Board[i][j] = 0;
        j++;
        i++;
        Board[i][j] = 1;
        return true;
    }
    else {
        return false;
    }
}

bool Ball::goUpLeft(){
    if(j + 1 < BOARD_HEIGHT && i > 0){
        Board[i][j] = 0;
        j++;
        i--;
        Board[i][j] = 1;
        return true;
    }
    else {
        return false;
    }
}

bool Ball::goDownRight(){
    if(j > 0 && i + 1 < BOARD_WIDTH){
        Board[i][j] = 0;
        j--;
        i++;
        Board[i][j] = 1;
        return true;
    }
    else {
        return false;
    }
}

bool Ball::goDownLeft(){
    if(j > 0 && i > 0){
        Board[i][j] = 0;
        j--;
        i--;
        Board[i][j] = 1;
        return true;
    }
    else {
        return false;
    }
}

