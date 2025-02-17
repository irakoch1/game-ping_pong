#include <stdio.h>

void printField(int leftRacket, int rightRacket, int ball, int onePlayerScore,
                int twoPlayerScore) {
  for (int height = 0; height < 25; height++) {
    for (int width = 0; width < 80; width++) {
      if (height == 0 || height == 24) {
        printf("-");
      } else if (((height == leftRacket || height == leftRacket + 1 ||
                   height == leftRacket - 1) &&
                  width == 0) ||
                 ((height == rightRacket || height == rightRacket + 1 ||
                   height == rightRacket - 1) &&
                  width == 79)) {
        printf("|");
      } else if (height == 12 && width == ball) {
        printf("o");
      } else if (height == 22 && width == 30) {
        printf("Player 1 score: %d", onePlayerScore);
      } else if (height == 23 && width == 30) {
        printf("Player 2 score: %d", twoPlayerScore);
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}
int playerOneMove(char key, int curPosition) {
  if (key == 'a') {
    if (curPosition > 2) {
      curPosition--;
    }
  } else if (key == 'z') {
    if (curPosition < 22) {
      curPosition++;
    }
  }
  return curPosition;
}
int playerTwoMove(char key, int curPosition) {
  if (key == 'k') {
    if (curPosition > 2) {
      curPosition--;
    }
  } else if (key == 'm') {
    if (curPosition < 22) {
      curPosition++;
    }
  }
  return curPosition;
}

int main() {
  int leftRacket = 12;
  int rightRacket = 12;
  int ball = 1;
  int prevBall;
  int onePlayerScore = 0;
  int twoPlayerScore = 0;

  while (onePlayerScore <= 21 || twoPlayerScore <= 21) {
    if (onePlayerScore == 21) {
      printf("Player 1 Win!!!");
      break;
    } else if (twoPlayerScore == 21) {
      printf("Player 2 Win!!!");
      break;
    }

    char key;
    key = getchar();

    if (key == 'a' || key == 'z') {
      leftRacket = playerOneMove(key, leftRacket);
      if (ball == 1 &&
          (leftRacket == 11 || leftRacket == 12 || leftRacket == 13)) {
        prevBall = ball;
        ball++;
        printField(leftRacket, rightRacket, ball, onePlayerScore,
                   twoPlayerScore);
      } else if (ball == 78 && (rightRacket == 11 || rightRacket == 12 ||
                                rightRacket == 13)) {
        prevBall = ball;
        ball--;
        printField(leftRacket, rightRacket, ball, onePlayerScore,
                   twoPlayerScore);
      } else if (ball == 1 &&
                 (leftRacket != 11 && leftRacket != 12 && leftRacket != 13)) {
        twoPlayerScore++;
        printf("Player 1: %d\nPlayer 2: %d\n", onePlayerScore, twoPlayerScore);
        ball = 1;
        prevBall = 0;
        leftRacket = 12;
        rightRacket = 12;
      } else if (ball == 78 && (rightRacket != 11 && rightRacket != 12 &&
                                rightRacket != 13)) {
        onePlayerScore++;
        printf("Player 1: %d\nPlayer 2: %d\n", onePlayerScore, twoPlayerScore);
        ball = 78;
        prevBall = 0;
        leftRacket = 12;
        rightRacket = 12;
      } else if (ball > 1 && ball < 78) {
        if (prevBall < ball) {
          prevBall = ball;
          ball++;
          printField(leftRacket, rightRacket, ball, onePlayerScore,
                     twoPlayerScore);
        } else if (prevBall > ball) {
          prevBall = ball;
          ball--;
          printField(leftRacket, rightRacket, ball, onePlayerScore,
                     twoPlayerScore);
        }
      }
    } else if (key == 'k' || key == 'm') {
      rightRacket = playerTwoMove(key, rightRacket);
      if (ball == 1 &&
          (leftRacket == 11 || leftRacket == 12 || leftRacket == 13)) {
        prevBall = ball;
        ball++;
        printField(leftRacket, rightRacket, ball, onePlayerScore,
                   twoPlayerScore);
      } else if (ball == 78 && (rightRacket == 11 || rightRacket == 12 ||
                                rightRacket == 13)) {
        prevBall = ball;
        ball--;
        printField(leftRacket, rightRacket, ball, onePlayerScore,
                   twoPlayerScore);
      } else if (ball == 1 &&
                 (leftRacket != 11 && leftRacket != 12 && leftRacket != 13)) {
        twoPlayerScore++;
        printf("Player 1: %d\nPlayer 2: %d\n", onePlayerScore, twoPlayerScore);
        ball = 1;
        prevBall = 0;
        leftRacket = 12;
        rightRacket = 12;
      } else if (ball == 78 && (rightRacket != 11 && rightRacket != 12 &&
                                rightRacket != 13)) {
        onePlayerScore++;
        printf("Player 1: %d\nPlayer 2: %d\n", onePlayerScore, twoPlayerScore);
        ball = 78;
        prevBall = 0;
        leftRacket = 12;
        rightRacket = 12;
      } else if (ball > 1 && ball < 78) {
        if (prevBall < ball) {
          prevBall = ball;
          ball++;
          printField(leftRacket, rightRacket, ball, onePlayerScore,
                     twoPlayerScore);
        } else if (prevBall > ball) {
          prevBall = ball;
          ball--;
          printField(leftRacket, rightRacket, ball, onePlayerScore,
                     twoPlayerScore);
        }
      }
    } else if (key == ' ') {
      if (ball == 1 &&
          (leftRacket == 11 || leftRacket == 12 || leftRacket == 13)) {
        prevBall = ball;
        ball++;
        printField(leftRacket, rightRacket, ball, onePlayerScore,
                   twoPlayerScore);
      } else if (ball == 78 && (rightRacket == 11 || rightRacket == 12 ||
                                rightRacket == 13)) {
        prevBall = ball;
        ball--;
        printField(leftRacket, rightRacket, ball, onePlayerScore,
                   twoPlayerScore);
      } else if (ball == 1 &&
                 (leftRacket != 11 && leftRacket != 12 && leftRacket != 13)) {
        twoPlayerScore++;
        printf("Player 1: %d\nPlayer 2: %d\n", onePlayerScore, twoPlayerScore);
        ball = 1;
        prevBall = 0;
        leftRacket = 12;
        rightRacket = 12;
      } else if (ball == 78 && (rightRacket != 11 && rightRacket != 12 &&
                                rightRacket != 13)) {
        onePlayerScore++;
        printf("Player 1: %d\nPlayer 2: %d\n", onePlayerScore, twoPlayerScore);
        ball = 78;
        prevBall = 0;
        leftRacket = 12;
        rightRacket = 12;
      } else if (ball > 1 && ball < 78) {
        if (prevBall < ball) {
          prevBall = ball;
          ball++;
          printField(leftRacket, rightRacket, ball, onePlayerScore,
                     twoPlayerScore);
        } else if (prevBall > ball) {
          prevBall = ball;
          ball--;
          printField(leftRacket, rightRacket, ball, onePlayerScore,
                     twoPlayerScore);
        }
      }
    } else if (key == 'q') {
      printf("Player 1: %d\nPlayer 2: %d\n", onePlayerScore, twoPlayerScore);
      break;
    }
  }
}
