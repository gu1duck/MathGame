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
int successFromPlayerInput (int firstNumber, int secondNumber);
void succeed ();

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
    printf("PLAYER %d PLAYS FIRST\n\n", activePlayer);
    
    /* define RNG seed based on time */
    srand((unsigned)time(NULL));
    
     while (playerOneLives > 0 && playerTwoLives > 0)
     {
         int firstNumber = randomNumber(20);
         int secondNumber= randomNumber(20);
         
         prompt(activePlayer, firstNumber, secondNumber);
         
         if (successFromPlayerInput(firstNumber, secondNumber))
         {
             succeed();
         }
         else
         {
             printf("FAILURE\n");
             if (activePlayer == 1)
             {
                 playerOneLives--;
             }
             else
             {
                 playerTwoLives--;
             }
             if (playerTwoLives > 0 && playerOneLives > 0)
             {
             printf("The current score is:\nPlayer 1: %d\nPlayer 2: %d\n\n",playerOneLives, playerTwoLives);
             }
         }
         if (activePlayer == 1)
         {
             activePlayer = 2;
         }
         else
         {
             activePlayer = 1;
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
     }
    printf("GAME OVER\nThe final score is:\nPlayer 1: %d\nPlayer 2: %d\n",playerOneLives, playerTwoLives);
    
    
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

int successFromPlayerInput(int firstNumber, int secondNumber){
    int input;
    scanf("%d", &input);
    if (input == firstNumber + secondNumber)
    {
        return 1;
    }
    return 0;
}

void succeed (){
    printf("You did it!!\n");
}

