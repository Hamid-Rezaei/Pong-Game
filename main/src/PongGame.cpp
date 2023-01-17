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

    GameBoard[i][j] = 1;
    GameBoard[i][j + 1] = 1;
    GameBoard[i][j + 2] = 1;
}

void Paddle::goUp(){
    int upper_bound = j + 3;
    if(upper_bound < BOARD_HEIGHT){
        GameBoard[i][j] = 0;
        GameBoard[i][j + 3] = 1;
        j += 1;
    }
}

void Paddle::goDown(){
    int lower_bound = j - 1;
    if(lower_bound >= 0){
        GameBoard[i][j + 2] = 0;
        GameBoard[i][j - 1] = 1;
        j -= 1;
    }
}
    
//Ball construnctor
Ball::Ball(): Regtangle(BALL_WIDTH, BALL_HEIGHT, X_CENTER, Y_CENTER){
    initBall();
}

void Ball::initBall(){
    GameBoard[i][j] = 0;
    i = X_CENTER;
    j = Y_CENTER;
    GameBoard[i][j] = 1;
    direction = right_up;
}

void Ball::correctPaddleLight(Paddle right_paddle, Paddle left_paddle){
    int j_left = left_paddle.getJ();
    GameBoard[left_paddle.getI()][j_left] = 1;
    GameBoard[left_paddle.getI()][j_left+1] = 1;
    GameBoard[left_paddle.getI()][j_left+2] = 1;

    int j_right = right_paddle.getJ();
    GameBoard[right_paddle.getI()][j_right] = 1;
    GameBoard[right_paddle.getI()][j_right+1] = 1;
    GameBoard[right_paddle.getI()][j_right+2] = 1;
}

bool Ball::goUpRight(){
    if(j + 1 < BOARD_HEIGHT && i + 1 < BOARD_WIDTH){
        GameBoard[i][j] = 0;
        j++;
        i++;
        GameBoard[i][j] = 1;
        return true;
    }
    else {
        return false;
    }
}

bool Ball::goUpLeft(){
    if(j + 1 < BOARD_HEIGHT && i > 0){
        GameBoard[i][j] = 0;
        j++;
        i--;
        GameBoard[i][j] = 1;
        return true;
    }
    else {
        return false;
    }
}

bool Ball::goDownRight(){
    if(j > 0 && i + 1 < BOARD_WIDTH){
        GameBoard[i][j] = 0;
        j--;
        i++;
        GameBoard[i][j] = 1;
        return true;
    }
    else {
        return false;
    }
}

bool Ball::goDownLeft(){
    if(j > 0 && i > 0){
        GameBoard[i][j] = 0;
        j--;
        i--;
        GameBoard[i][j] = 1;
        return true;
    }
    else {
        return false;
    }
}


void Ball::moving(Paddle right_paddle, Paddle left_paddle){
    switch (direction)
    {
    case left_up:{
        int i_after = i - 1;
        int j_after = j + 1;
        if(i_after == left_paddle.getI() && j_after > left_paddle.getJ() && j_after <= left_paddle.getJ() + 3){
            direction = right_up;
            return;
        }
        if(i_after < left_paddle.getI()){
            initBall();
            correctPaddleLight(right_paddle, left_paddle);
        }

        if(goUpLeft()){
            direction = left_up;
        }
        else{
            direction = left_down;
        }
    }
        break;
    case left_down:{
        int i_after = i - 1;
        int j_after = j - 1;
        if(i_after == left_paddle.getI() && j_after >= left_paddle.getJ() - 1 && j_after < left_paddle.getJ() + 2){
            direction = right_down;
            return;
        }
        if(i_after < left_paddle.getI()){
            initBall();
            correctPaddleLight(right_paddle, left_paddle);
        }

        if(goDownLeft()){
            direction = left_down;
        }
        else{
            direction = left_up;
        }
    }
        break;    
    case right_up:{
        int i_after = i + 1;
        int j_after = j + 1;
        if(i_after == right_paddle.getI() && j_after > right_paddle.getJ() && j_after <= right_paddle.getJ() + 3){
            direction = left_up;
            return;
        }
        if(i_after > right_paddle.getI()){
            initBall();
            correctPaddleLight(right_paddle, left_paddle);
        }

        if(goUpRight()){
            direction = right_up;
        }
        else{
            direction = right_down;
        }
    }
        break;

    case right_down:{
        int i_after = i + 1;
        int j_after = j - 1;
        if(i_after == right_paddle.getI() && j_after >= right_paddle.getJ() - 1 && j_after < right_paddle.getJ() + 2){
            direction = left_down;
            return;
        }
        if(i_after > right_paddle.getI()){
            initBall();
            correctPaddleLight(right_paddle, left_paddle);
        }

        if(goDownRight()){
            direction = right_down;
        }
        else{
            direction = right_up;
        }
    }
        break;
        
    default:
        direction = stay;
        break;
    }
}
