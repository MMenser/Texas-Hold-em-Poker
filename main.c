/*************************************************************************
* Programmer: Mason Menser	                                            *
* Class: CptS 121				                                        *
* Programming Assignment:   PA7							                *
*												                        *
* Date:   12/4/2022                                                     *
*                                                                       *
* Description:	I created a two player Texas Hold'em Poker game.		*
************************************************************************/

#include "header.h"



int main(void) {
	srand((unsigned)time(NULL));
	char* flopNames[3] = { "Flop", "Turn", "River" };
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	const char* face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };
	int deck[4][13] = { 0 };
	int player1HandSpecs[7] = { -1, -1, -1, -1, -1, -1, -1 };		//Highest pair, highest three of a kind, highest straight, highest card, full house card, quads card, two pair card
	int computerHandSpecs[7] = { -1, -1, -1, -1, -1, -1, -1 };
	int cardArray[13] = { 0 };
	Hand playerHand;
	Hand computerHand;
	Hand flop;
	int strengthPlayer = 10, strengthComputer = 10,  count = 0, bet = 0, computerBet = 0, winCondition = 0, playerBalance = 100, computerBalance = 100, pot = 0, option = -1;
	int* potP, flushCount, straightCount;
	potP = &pot;
		
	

	
	while (option != 3) {
		printf("Enter 1 to view rules. Enter 2 to start playing. Enter 3 to exit.\n");
		scanf("%d", &option);

		switch (option) {
			case 1: printf("To see the rules, visit this website: https://en.wikipedia.org/wiki/Texas_hold_%%27em#Rules");
					printf("\nEnter 1 to view rules. Enter 2 to start playing. Enter 3 to exit.");
					scanf("%d", &option);
					break;

			case 2: while (winCondition == 0) {		//-1 if computer wins, 0 if still playing, 1 if player wins
						resetPot(potP);
						shuffle(deck);
						deal(deck, face, suit, &playerHand, &computerHand, &flop);
						for (int i = -1; i < 3; i++) {
							system("cls");
							if (i == -1) {
							printf("Bet -1 to fold.\nEnter your anti to play. Minimum Anti is $5\n");
							printf("\t\t\t\t\t\t\t\t\t\t\t\tComputers hand is currently hidden.");
							printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Your Hand:\n\n");
							printSet(playerHand, suit, face, 2);
							}
							else {
								printf("\t\t\t\t\t\t\t\t\t\t\t\tComputers hand is currently hidden.");
								printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t%s:\n\n", flopNames[i]);
								printSet(flop, suit, face, i + 3);
								printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Pot: %d", pot);
								printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Your Hand:\n\n");
								printSet(playerHand, suit, face, 2);

								strengthPlayer = parseHand(playerHand, flop, suit, face, i + 3, player1HandSpecs, &flushCount, &straightCount, cardArray);
								resetCardArray(cardArray);
								strengthComputer = parseHand(computerHand, flop, suit, face, i + 3, computerHandSpecs, &flushCount, &straightCount, cardArray);
								resetCardArray(cardArray);
								printf("What is your bet on the %s?", flopNames[i]);
							}	

							scanf("%d", &bet);
							if (bet == -1) {
								printf("You folded.\n");
								winCondition = -1;
								break;
							}
							increasePot(bet, potP);
							computerBet = computerDecision(strengthComputer, pot, bet, computerHand, flop, i + 3, &flushCount, &straightCount, computerHandSpecs, cardArray);
							
							if (checkBet(computerBet, bet) == -1) {
								printf("The computer folds.");
								winCondition = 1;
								break;
							}
							else if (checkBet(computerBet, bet) == 0) {
								printf("Computer raised by %d. Bet $%d to call or fold (enter -1 to fold).\n", computerBet - bet, computerBet - bet);
								scanf("%d", &bet);
								if (bet == -1) {
									winCondition = -1;
									break;
								}
								else {
									increasePot(bet, potP);
								}
							}
							else {
								printf("Computer calls.\n");
							}
							increasePot(computerBet, potP);
							Sleep(2000);
						}
						printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\tComputers hand. \n");
						printSet(computerHand, suit, face, 2);
						printf("\n\n");
						printSet(flop, suit, face, 5);
						printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t    Pot: %d\n\n", pot);
						printSet(playerHand, suit, face, 2);
						strengthPlayer = parseHand(playerHand, flop, suit, face, 5, player1HandSpecs, &flushCount, &straightCount, cardArray);
						resetCardArray(cardArray);
						strengthComputer = parseHand(computerHand, flop, suit, face, 5, computerHandSpecs, &flushCount, &straightCount, cardArray);
						resetCardArray(cardArray);
						printf("After all the cards were dealt - Player Strength: %d, Computer Strength: %d\n", strengthPlayer, strengthComputer);

						if (winCondition == -1) {
							computerBalance += pot;
							printf("The computer has won.");
						}
						else if (winCondition = 1) {
							playerBalance += pot;
							printf("You have won!");
						}
						else {
							if (strengthPlayer < strengthComputer) {
								playerBalance += pot;
								printf("You have won!");
							}
							else if (strengthPlayer > strengthComputer) {
								computerBalance += pot;
								printf("The computer has won. Bottom if");
							}
							else {
								printf("Tie!");
							}
						}		
				}
				  printf("\nEnter 1 to view rules. Enter 2 to start playing. Enter 3 to exit.");
				  scanf("%d", &option);
				  winCondition = 0;
				  break;
			case 3: break;
		}
	}

	return 0;
}

/*
	playerHand.cardArr[0].faceIndex = 0;
	playerHand.cardArr[0].suitIndex = 0;
	playerHand.cardArr[1].faceIndex = 10;
	playerHand.cardArr[1].suitIndex = 0;
	flop.cardArr[0].faceIndex = 11;
	flop.cardArr[0].suitIndex = 0;
	flop.cardArr[1].faceIndex = 12;
	flop.cardArr[1].suitIndex = 0;
	flop.cardArr[2].faceIndex = 9;
	flop.cardArr[2].suitIndex = 0;
*/
