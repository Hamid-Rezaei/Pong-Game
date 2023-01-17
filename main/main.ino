#include "src/ponggame.h"

// Rows
#define col1 12
#define col2 13
#define col3 A0
#define col4 A1
#define col5 A2
#define col6 A3
#define col7 A4
#define col8 A5

// Columns
#define row1 4
#define row2 5
#define row3 6
#define row4 7
#define row5 8
#define row6 9
#define row7 10
#define row8 11

// keys
#define RightUp 3
#define RightDown 2
#define leftUp 1
#define leftDown 0



void setup() {
  pinMode(row1, OUTPUT);
  pinMode(row2, OUTPUT);
  pinMode(row3, OUTPUT);
  pinMode(row4, OUTPUT);
  pinMode(row5, OUTPUT);
  pinMode(row6, OUTPUT);
  pinMode(row7, OUTPUT);
  pinMode(row8, OUTPUT);

  pinMode(col1, OUTPUT);
  pinMode(col2, OUTPUT);
  pinMode(col3, OUTPUT);
  pinMode(col4, OUTPUT);
  pinMode(col5, OUTPUT);
  pinMode(col6, OUTPUT);
  pinMode(col7, OUTPUT);
  pinMode(col8, OUTPUT);

  digitalWrite(row1, HIGH);
  digitalWrite(row2, HIGH);
  digitalWrite(row3, HIGH);
  digitalWrite(row4, HIGH);
  digitalWrite(row5, HIGH);
  digitalWrite(row6, HIGH);
  digitalWrite(row7, HIGH);
  digitalWrite(row8, HIGH);

  digitalWrite(col1, LOW);
  digitalWrite(col2, LOW);
  digitalWrite(col3, LOW);
  digitalWrite(col4, LOW);
  digitalWrite(col5, LOW);
  digitalWrite(col6, LOW);
  digitalWrite(col7, LOW);
  digitalWrite(col8, LOW);

  pinMode(RightUp, INPUT_PULLUP);
  pinMode(RightDown, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(RightUp), rightUp, RISING);
  attachInterrupt(digitalPinToInterrupt(RightDown), rightDown, RISING);

}

Ball ball = Ball();
Paddle left_paddle = Paddle(false); 
Paddle right_paddle = Paddle(true); 


void rightUp(){
  right_paddle.goUp();
}

void rightDown(){
  right_paddle.goDown();
}

void select_row(int row){
  if (row == 1) digitalWrite(row1, LOW); else digitalWrite(row1, HIGH);
  if (row == 2) digitalWrite(row2, LOW); else digitalWrite(row2, HIGH);
  if (row == 3) digitalWrite(row3, LOW); else digitalWrite(row3, HIGH);
  if (row == 4) digitalWrite(row4, LOW); else digitalWrite(row4, HIGH);
  if (row == 5) digitalWrite(row5, LOW); else digitalWrite(row5, HIGH);
  if (row == 6) digitalWrite(row6, LOW); else digitalWrite(row6, HIGH);
  if (row == 7) digitalWrite(row7, LOW); else digitalWrite(row7, HIGH);
  if (row == 8) digitalWrite(row8, LOW); else digitalWrite(row8, HIGH);
}

void set_LED_in_active_row(int column, int state){
  if(column == 1) digitalWrite(col1, state);
  if(column == 2) digitalWrite(col2, state);
  if(column == 3) digitalWrite(col3, state);
  if(column == 4) digitalWrite(col4, state);
  if(column == 5) digitalWrite(col5, state);
  if(column == 6) digitalWrite(col6, state);
  if(column == 7) digitalWrite(col7, state);
  if(column == 8) digitalWrite(col8, state);
}


void tick(){
  for(int i = 0; i < 9; i++){
    select_row(i+1);
    for(int j = 0; j < 9; j++){
        set_LED_in_active_row(j+1, GameBoard[i][j]);
    }
    delay(2);    
 }
}

int ball_speed = 50;
int i = 0;

void loop() {
  tick();
  i++;
  if(i % ball_speed == 0)
    ball.moving(right_paddle, left_paddle);

}
