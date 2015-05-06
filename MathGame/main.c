//
//  main.c
//  MathGame
//
//  Created by Jeremy Petter on 2015-05-05.
//  Copyright (c) 2015 Jeremy Petter. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int randomNumber(int max);
void prompt(int activePlayer, int firstNumber, int secondNumber);

int playerOneLives;
int playerTwoLives;
int activePlayer;

int main(int argc, const char * argv[]) {
    
    /* 
     set lives of players to 3
     */
    playerOneLives = 3;
    playerTwoLives = 3;
    activePlayer = randomNumber(2);
    printf("Player %d plays first", activePlayer);
    
    /* define RNG seed based on time */
    srand((unsigned)time(NULL));
    
     while (playerOneLives > 0 && playerTwoLives > 0)
     {
    /*
        define  numbers randomly between 1 and 20;
     */
         
         int firstNumber = randomNumber(20);
         int secondNumber= randomNumber(20);
         
         prompt(activePlayer, firstNumber, secondNumber);
         
         if (playerInput == firstNumber + secondNumber){
             //success
         }
         
         
         
         
                  /*
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

int randomNumber(int max){
    return (1 + rand() % max);
}

void prompt(int activePlayer, int firstNumber, int secondNumber){
    printf("Player %d, what is %d + %d?\n>", activePlayer, firstNumber, secondNumber);
}

int playerInput(){
    int input;
    scanf("%d", &input);
    return input;
}

