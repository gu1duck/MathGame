//
//  main.c
//  MathGame
//
//  Created by Jeremy Petter on 2015-05-05.
//  Copyright (c) 2015 Jeremy Petter. All rights reserved.
//

#include <stdio.h>

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
