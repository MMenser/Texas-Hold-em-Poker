/*************************************************************************
* Programmer: Mason Menser	                                            *
* Class: CptS 121				                                        *
* Programming Assignment:   PA7							                *
*												                        *
* Date:   12/4/2022                                                     *
*                                                                       *
* Description:	I created a two player Texas Hold'em Poker game.		*
************************************************************************/

#ifndef header_h
#define header_h


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <wchar.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

typedef struct card {
	int faceIndex;
	int suitIndex;
} Card;

typedef struct hand {
	Card cardArr[5];
} Hand;

enum Suit { Hearts, Diamonds, Clubs, Spades };

//This function takes two Hands, two arrays of strings, two ints, one int pointer, one Card array, and one int array as parameters. It returns the number of cards in a consecutive row.
int checkStraight(Hand hand, Hand flop, char* suit[4], char* face[13], int flopTurnRiver, Card cardStraightArr[7], int flushCardArr[5], int flushIn, int* highCardStraight);

//This function takes two arrays of strings and one 2d array of ints, and three Hands. It deals 2 cards to player and computer hand, and 5 cards to flop hand
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand *pHand, Hand *cHand, Hand *flop);

//This function takes a 2d array of ints as a parameter and shuffules the order of the elements of the array
void shuffle(int wDeck[][13]);

//This function takes one array of ints as a parameter and resets all elements to 0
void resetCardArray(int cardArray[13]);

//This function takes one array of ints as a parameter and resets all elements to 0
void resetPlayerSpecs(int playerSpec[7]);

//This function takes four ints, two Hands, two int pointers, and two arrays of ints as parmaters. It returns the bet size of the computer
int computerDecision(int handStrength, int pot, int playerIncreasePot, Hand hand, Hand flop, int flopTurnRiver, int* flushCount, int* straightCount, int handSpecs[7], int cardArray[13]);

//This function checks whether a bet is valid, and whether it raises, folds, or calls the previous bet
int checkBet(int bet, int minBetNeeded);

//This functino takes an array of strings and an int as parameters. It returns a char of the suit of the card
char suitToPicture(char* suit[4], int i);

//This function takes a Hand, two arrays of strings, and an int as parameters. It returns the picture of a specific number of cards visually
void printSet(Hand hand, char* suit[4], char* face[13], int numOfCards);

//This function takes two Hands, two arrays of strings, one int, two int arrays, and two int pointers as parameters. It returns the hand strength of a hand, 1 being the best and 10 being the worst (high card)
int parseHand(Hand hand, Hand flop, char* suit[4], char* face[13], int flopTurnRiver, int handSpecs[7], int* flushCount, int* straightCount, int cardArray[13]);

//This function takes three ints, two int arrays, and one Hand as parameters. It figures out high cards for specific hands to determine who wins in the event of a tie and sets elements in the handSpecs array 
void tieBreaker(int handStrength, int strongestPair, int strongestThrees, int cardArray[13], Hand hand, int handSpecs[7]);

//This function takes a int poitner as a parameter and returns void. It resets the pot to 0.
void resetPot(int* pot);

//This function takes an int pointer and an int as parameters. Its void and increase the pot by a specific value
void increasePot(int increase, int* pot);

//This function takes two ints as parameters and returns an int. If the new hand strength is lower (better) than the old hand strength, it returns the new hand strength.
int updateHandStrength(int newHandStrength, int oldHandStrength);


#endif header_h
