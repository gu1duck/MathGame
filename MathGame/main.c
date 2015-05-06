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
void fail();
void switchActivePlayer();
void defineStartingState(int setPlayerOneLives, int setPlayerTwoLives, int setStartingPlayer);

int playerOneLives;
int playerTwoLives;
int activePlayer;

int main(int argc, const char * argv[]) {
    
    defineStartingState(3,3,randomNumber(2));
    
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
             fail();
         }
         
         switchActivePlayer();
    
    }
    printf("GAME OVER\n\nThe final score is:\nPlayer 1: %d\nPlayer 2: %d\n",playerOneLives, playerTwoLives);
    
    return 0;
}

void defineStartingState(int setPlayerOneLives, int setPlayerTwoLives, int setStartingPlayer){
    playerOneLives = setPlayerOneLives;
    playerTwoLives = setPlayerTwoLives;
    activePlayer = setStartingPlayer;
    printf("PLAYER %d PLAYS FIRST\n\n", activePlayer);
    
    /* define RNG seed based on time */
    srand((unsigned)time(NULL));
}

int randomNumber(int max)
{
    return (1 + rand() % max);
}

void prompt(int activePlayer, int firstNumber, int secondNumber)
{
    printf("Player %d, what is %d + %d?\n>", activePlayer, firstNumber, secondNumber);
}

int successFromPlayerInput(int firstNumber, int secondNumber)
{
    int input;
    scanf("%d", &input);
    if (input == firstNumber + secondNumber)
    {
        return 1;
    }
    return 0;
}

void succeed ()
{
    printf("You did it!!\n\n");
}

void fail()
{
    printf("FAILURE\n\n");
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

void switchActivePlayer(){
    if (activePlayer == 1)
    {
        activePlayer = 2;
    }
    else
    {
        activePlayer = 1;
    }
    
}

