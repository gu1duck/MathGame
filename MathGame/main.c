//
//  main.c
//  MathGame
//
//  Created by Jeremy Petter on 2015-05-05.
//  Copyright (c) 2015 Jeremy Petter. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int playerOneLives;
int playerTwoLives;
int activePlayer;

int main(int argc, const char * argv[]) {
    
    /* 
     set lives of players to 3
     */
    playerOneLives = 3;
    playerTwoLives = 3;
    
     while (playerOneLives > 0 && playerTwoLives > 0)
     {
    /*
        define first number randomly between 1 and 20;
     */
         int firstNumber;
         int secondNumber;
         
         for (int i = 0; i < 5; i++){
             firstNumber = (1 + rand() % 20);
             secondNumber = (1 + rand() % 20);
             printf("First number is %d. Second number is %d\n", firstNumber, secondNumber);
         }
         /*
        define second number randomly between 1 and 20;
     
        prompt active player;
        take input from active player;
        evaluate input vs actual result;
        if result is correct
            display affirming message about life
        if result is incorrect
            display disparaging message
            decrement lives
            display scores
        switch active player
          */
         printf("%d",playerOneLives--);
     }
    /* announce winner
     display scores */

    
    return 0;
}
