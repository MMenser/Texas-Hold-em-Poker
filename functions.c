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



//Function definitions 

void shuffle(int wDeck[][13])
{
	for (int i = 0; i < 4; i++) {
		for (int k = 0; k < 13; k++) {
			wDeck[i][k] = 0;
		}
	}


	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/* deal cards in deck */
void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], Hand *pHand, Hand *cHand, Hand *flop)
{	
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* deal each of the 52 cards */
	for (card = 1; card <= 11; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card && card <= 2)
				{
					pHand->cardArr[card - 1].faceIndex = column;
					pHand->cardArr[card - 1].suitIndex = row;

				}
				else if (wDeck[row][column] == card && card > 2 && card < 5) {
					cHand->cardArr[card - 3].faceIndex = column;
					cHand->cardArr[card - 3].suitIndex = row;
				}
				else if (wDeck[row][column] == card && card > 5 && card < 11) {
					flop->cardArr[card - 6].faceIndex = column;
					flop->cardArr[card - 6].suitIndex = row;
				}
			}
		}
	}
}



char suitToPicture(char* suit[4], int i) {
	char returnChar = '\0';
	if (suit[i] == "Hearts") {
		returnChar = 3;
	}
	else if (suit[i] == "Diamonds") {
		returnChar = 4;
	}
	else if (suit[i] == "Spades") {
		returnChar = 6;
	}
	else {
		returnChar = 5;
	}

	return returnChar;
}

void resetPlayerSpecs(int playerSpec[7]) {
	for (int i = 0; i < 7; i++) {
		playerSpec[i] = -1;
	}
}

void printSet(Hand hand, char* suit[4], char* face[13], int numOfCards) {
	int count = 0;
	if (numOfCards == 2) {
		for (int k = 0; k <= 8; k++) {
			printf("\t\t\t\t\t\t\t\t\t");
			for (int i = 6; i <= 18; i += 2) {
				count = 0;
				printf("\t");
				if ((i == 10 || i == 14) && k == 0) {
					printf("- - - - -");
				}
				else if ((i == 10 || i == 14) && k == 1) {
					if (i == 10) {
						printf("|%c     %c|", suitToPicture(suit, hand.cardArr[0].suitIndex), suitToPicture(suit, hand.cardArr[0].suitIndex));
					}
					else if (i == 14) {
						printf("|%c     %c|", suitToPicture(suit, hand.cardArr[1].suitIndex), suitToPicture(suit, hand.cardArr[1].suitIndex));
					}
				}
				else if ((i == 10 || i == 14) && k == 2) {
					printf("|       |");
				}
				else if ((i == 10 || i == 14) && k == 3) {
					printf("|       |");
				}
				else if ((i == 10 || i == 14) && k == 4) {
					printf("|");
					if (i == 10) {
						for (int i = 1; i < (9 - strlen(face[hand.cardArr[0].faceIndex])) / 2; i++) {
							printf(" ");
							count++;
						}
						printf("%s", face[hand.cardArr[0].faceIndex]);
						count += strlen(face[hand.cardArr[0].faceIndex]);
						for (int i = count; i < 7; i++) {
							printf(" ");
						}
					}
					else if (i == 14) {
						for (int i = 1; i < (9 - strlen(face[hand.cardArr[1].faceIndex])) / 2; i++) {
							printf(" ");
							count++;
						}
						printf("%s", face[hand.cardArr[1].faceIndex]);
						count += strlen(face[hand.cardArr[1].faceIndex]);
						for (int i = count; i < 7; i++) {
							printf(" ");
						}
					}
					printf("|");
				}
				else if ((i == 10 || i == 14) && k == 5) {
					printf("|       |");
				}
				else if ((i == 10 || i == 14) && k == 6) {
					printf("|       |");
				}
				else if ((i == 10 || i == 14) && k == 7) {
					if (i == 10) {
						printf("|%c     %c|", suitToPicture(suit, hand.cardArr[0].suitIndex), suitToPicture(suit, hand.cardArr[0].suitIndex));
					}
					else if (i == 14) {
						printf("|%c     %c|", suitToPicture(suit, hand.cardArr[1].suitIndex), suitToPicture(suit, hand.cardArr[1].suitIndex));
					}
				}
				else if ((i == 10 || i == 14) && k == 8) {
					printf("- - - - -");
				}
			}
			printf("\n");
		}
	}
	else if (numOfCards == 3) {
		for (int k = 0; k <= 8; k++) {
			printf("\t\t\t\t\t\t\t\t\t");
			for (int i = 6; i <= 18; i += 2) {
				count = 0;
				printf("\t");
				if ((i == 10 || i == 14 || i == 18) && k == 0) {
					printf("- - - - -");
				}
				else if ((i == 10 || i == 14 || i == 18) && k == 1) {
					if (i == 10) {
						printf("|%c     %c|", suitToPicture(suit, hand.cardArr[0].suitIndex), suitToPicture(suit, hand.cardArr[0].suitIndex));
					}
					else if (i == 14) {
						printf("|%c     %c|", suitToPicture(suit, hand.cardArr[1].suitIndex), suitToPicture(suit, hand.cardArr[1].suitIndex));
					}
					else if (i == 18) {
						printf("|%c     %c|", suitToPicture(suit, hand.cardArr[2].suitIndex), suitToPicture(suit, hand.cardArr[2].suitIndex));
					}
				}
				else if ((i == 10 || i == 14 || i == 18) && k == 2) {
					printf("|       |");
				}
				else if ((i == 10 || i == 14 || i == 18) && k == 3) {
					printf("|       |");
				}
				else if ((i == 10 || i == 14 || i == 18) && k == 4) {
					printf("|");
					if (i == 10) {
						for (int i = 1; i < (9 - strlen(face[hand.cardArr[0].faceIndex])) / 2; i++) {
							printf(" ");
							count++;
						}
						printf("%s", face[hand.cardArr[0].faceIndex]);
						count += strlen(face[hand.cardArr[0].faceIndex]);
						for (int i = count; i < 7; i++) {
							printf(" ");
						}
					}
					else if (i == 14) {
						for (int i = 1; i < (9 - strlen(face[hand.cardArr[1].faceIndex])) / 2; i++) {
							printf(" ");
							count++;
						}
						printf("%s", face[hand.cardArr[1].faceIndex]);
						count += strlen(face[hand.cardArr[1].faceIndex]);
						for (int i = count; i < 7; i++) {
							printf(" ");
						}
					}
					else if (i == 18) {
						for (int i = 1; i < (9 - strlen(face[hand.cardArr[2].faceIndex])) / 2; i++) {
							printf(" ");
							count++;
						}
						printf("%s", face[hand.cardArr[2].faceIndex]);
						count += strlen(face[hand.cardArr[2].faceIndex]);
						for (int i = count; i < 7; i++) {
							printf(" ");
						}
					}
					printf("|");
				}
				else if ((i == 10 || i == 14 || i == 18) && k == 5) {
					printf("|       |");
				}
				else if ((i == 10 || i == 14 || i == 18) && k == 6) {
					printf("|       |");
				}
				else if ((i == 10 || i == 14 || i == 18) && k == 7) {
					if (i == 10) {
						printf("|%c     %c|", suitToPicture(suit, hand.cardArr[0].suitIndex), suitToPicture(suit, hand.cardArr[0].suitIndex));
					}
					else if (i == 14) {
						printf("|%c     %c|", suitToPicture(suit, hand.cardArr[1].suitIndex), suitToPicture(suit, hand.cardArr[1].suitIndex));
					}
					else if (i == 18) {
						printf("|%c     %c|", suitToPicture(suit, hand.cardArr[2].suitIndex), suitToPicture(suit, hand.cardArr[2].suitIndex));
					}
				}
				else if ((i == 10 || i == 14 || i == 18) && k == 8) {
					printf("- - - - -");
				}
			}
			printf("\n");
		}
	}
	else if (numOfCards == 4) {
		for (int k = 0; k <= 8; k++) {
			printf("\t\t\t\t\t\t\t\t");
			for (int i = 6; i <= 18; i += 2) {
				count = 0;
				printf("\t");
				if ((i == 6 || i == 10 || i == 14 || i == 18) && k == 0) {
					printf("- - - - -");
				}
				else if ((i == 6 || i == 10 || i == 14 || i == 18) && k == 1) {
					if (i == 6) {
						printf("|%c     %c|", suitToPicture(suit, hand.cardArr[0].suitIndex), suitToPicture(suit, hand.cardArr[0].suitIndex));
					}
					else if (i == 10) {
						printf("|%c     %c|", suitToPicture(suit, hand.cardArr[1].suitIndex), suitToPicture(suit, hand.cardArr[1].suitIndex));
					}
					else if (i == 14) {
						printf("|%c     %c|", suitToPicture(suit, hand.cardArr[2].suitIndex), suitToPicture(suit, hand.cardArr[2].suitIndex));
					}
					else if (i == 18) {
						printf("|%c     %c|", suitToPicture(suit, hand.cardArr[3].suitIndex), suitToPicture(suit, hand.cardArr[3].suitIndex));
					}
				}
				else if ((i == 6 || i == 10 || i == 14 || i == 18) && k == 2) {
					printf("|       |");
				}
				else if ((i == 6 || i == 10 || i == 14 || i == 18) && k == 3) {
					printf("|       |");
				}
				else if ((i == 6 || i == 10 || i == 14 || i == 18) && k == 4) {
					printf("|");
					if (i == 6) {
						for (int i = 1; i < (9 - strlen(face[hand.cardArr[0].faceIndex])) / 2; i++) {
							printf(" ");
							count++;
						}
						printf("%s", face[hand.cardArr[0].faceIndex]);
						count += strlen(face[hand.cardArr[0].faceIndex]);
						for (int i = count; i < 7; i++) {
							printf(" ");
						}
					}
					else if (i == 10) {
						for (int i = 1; i < (9 - strlen(face[hand.cardArr[1].faceIndex])) / 2; i++) {
							printf(" ");
							count++;
						}
						printf("%s", face[hand.cardArr[1].faceIndex]);
						count += strlen(face[hand.cardArr[1].faceIndex]);
						for (int i = count; i < 7; i++) {
							printf(" ");
						}
					}
					else if (i == 14) {
						for (int i = 1; i < (9 - strlen(face[hand.cardArr[2].faceIndex])) / 2; i++) {
							printf(" ");
							count++;
						}
						printf("%s", face[hand.cardArr[2].faceIndex]);
						count += strlen(face[hand.cardArr[2].faceIndex]);
						for (int i = count; i < 7; i++) {
							printf(" ");
						}
					}
					else if (i == 18) {
						for (int i = 1; i < (9 - strlen(face[hand.cardArr[3].faceIndex])) / 2; i++) {
							printf(" ");
							count++;
						}
						printf("%s", face[hand.cardArr[3].faceIndex]);
						count += strlen(face[hand.cardArr[3].faceIndex]);
						for (int i = count; i < 7; i++) {
							printf(" ");
						}
					}
					printf("|");
				}
				else if ((i == 6 || i == 10 || i == 14 || i == 18) && k == 5) {
					printf("|       |");
				}
				else if ((i == 6 || i == 10 || i == 14 || i == 18) && k == 6) {
					printf("|       |");
				}
				else if ((i == 6 || i == 10 || i == 14 || i == 18) && k == 7) {
					if (i == 6) {
						printf("|%c     %c|", suitToPicture(suit, hand.cardArr[0].suitIndex), suitToPicture(suit, hand.cardArr[0].suitIndex));
					}
					else if (i == 10) {
						printf("|%c     %c|", suitToPicture(suit, hand.cardArr[1].suitIndex), suitToPicture(suit, hand.cardArr[1].suitIndex));
					}
					else if (i == 14) {
						printf("|%c     %c|", suitToPicture(suit, hand.cardArr[2].suitIndex), suitToPicture(suit, hand.cardArr[2].suitIndex));
					}
					else if (i == 18) {
						printf("|%c     %c|", suitToPicture(suit, hand.cardArr[3].suitIndex), suitToPicture(suit, hand.cardArr[3].suitIndex));
					}
				}
				else if ((i == 6 || i == 10 || i == 14 || i == 18) && k == 8) {
					printf("- - - - -");
				}
			}
			printf("\n");
		}
	}
	else if (numOfCards == 5) {
	for (int k = 0; k <= 8; k++) {
		printf("\t\t\t\t\t\t\t\t");
		for (int i = 2; i <= 18; i += 2) {
			count = 0;
			printf("\t");
			if (( i == 2 || i == 6 || i == 10 || i == 14 || i == 18) && k == 0) {
				printf("- - - - -");
			}
			else if ((i == 2 || i == 6 || i == 10 || i == 14 || i == 18) && k == 1) {
				if (i == 2) {
					printf("|%c     %c|", suitToPicture(suit, hand.cardArr[0].suitIndex), suitToPicture(suit, hand.cardArr[0].suitIndex));
				}
				else if (i == 6) {
					printf("|%c     %c|", suitToPicture(suit, hand.cardArr[1].suitIndex), suitToPicture(suit, hand.cardArr[1].suitIndex));
				}
				else if (i == 10) {
					printf("|%c     %c|", suitToPicture(suit, hand.cardArr[2].suitIndex), suitToPicture(suit, hand.cardArr[2].suitIndex));
				}
				else if (i == 14) {
					printf("|%c     %c|", suitToPicture(suit, hand.cardArr[3].suitIndex), suitToPicture(suit, hand.cardArr[3].suitIndex));
				}
				else if (i == 18) {
					printf("|%c     %c|", suitToPicture(suit, hand.cardArr[4].suitIndex), suitToPicture(suit, hand.cardArr[4].suitIndex));
				}
			}
			else if ((i == 2 || i == 6 || i == 10 || i == 14 || i == 18) && k == 2) {
				printf("|       |");
			}
			else if ((i == 2 || i == 6 || i == 10 || i == 14 || i == 18) && k == 3) {
				printf("|       |");
			}
			else if ((i == 2 || i == 6 || i == 10 || i == 14 || i == 18) && k == 4) {
				printf("|");
				if (i == 2) {
					for (int i = 1; i < (9 - strlen(face[hand.cardArr[0].faceIndex])) / 2; i++) {
						printf(" ");
						count++;
					}
					printf("%s", face[hand.cardArr[0].faceIndex]);
					count += strlen(face[hand.cardArr[0].faceIndex]);
					for (int i = count; i < 7; i++) {
						printf(" ");
					}
				}
				else if (i == 6) {
					for (int i = 1; i < (9 - strlen(face[hand.cardArr[1].faceIndex])) / 2; i++) {
						printf(" ");
						count++;
					}
					printf("%s", face[hand.cardArr[1].faceIndex]);
					count += strlen(face[hand.cardArr[1].faceIndex]);
					for (int i = count; i < 7; i++) {
						printf(" ");
					}
				}
				else if (i == 10) {
					for (int i = 1; i < (9 - strlen(face[hand.cardArr[2].faceIndex])) / 2; i++) {
						printf(" ");
						count++;
					}
					printf("%s", face[hand.cardArr[2].faceIndex]);
					count += strlen(face[hand.cardArr[2].faceIndex]);
					for (int i = count; i < 7; i++) {
						printf(" ");
					}
				}
				else if (i == 14) {
					for (int i = 1; i < (9 - strlen(face[hand.cardArr[3].faceIndex])) / 2; i++) {
						printf(" ");
						count++;
					}
					printf("%s", face[hand.cardArr[3].faceIndex]);
					count += strlen(face[hand.cardArr[3].faceIndex]);
					for (int i = count; i < 7; i++) {
						printf(" ");
					}
				}
				else if (i == 18) {
					for (int i = 1; i < (9 - strlen(face[hand.cardArr[4].faceIndex])) / 2; i++) {
						printf(" ");
						count++;
					}
					printf("%s", face[hand.cardArr[4].faceIndex]);
					count += strlen(face[hand.cardArr[4].faceIndex]);
					for (int i = count; i < 7; i++) {
						printf(" ");
					}
				}
				printf("|");
			}
			else if ((i == 2 || i == 6 || i == 10 || i == 14 || i == 18) && k == 5) {
				printf("|       |");
			}
			else if ((i == 2 || i == 6 || i == 10 || i == 14 || i == 18) && k == 6) {
				printf("|       |");
			}
			else if ((i == 2 || i == 6 || i == 10 || i == 14 || i == 18) && k == 7) {
				if (i == 2) {
					printf("|%c     %c|", suitToPicture(suit, hand.cardArr[0].suitIndex), suitToPicture(suit, hand.cardArr[0].suitIndex));
				}
				else if (i == 6) {
					printf("|%c     %c|", suitToPicture(suit, hand.cardArr[1].suitIndex), suitToPicture(suit, hand.cardArr[1].suitIndex));
				}
				else if (i == 10) {
					printf("|%c     %c|", suitToPicture(suit, hand.cardArr[2].suitIndex), suitToPicture(suit, hand.cardArr[2].suitIndex));
				}
				else if (i == 14) {
					printf("|%c     %c|", suitToPicture(suit, hand.cardArr[3].suitIndex), suitToPicture(suit, hand.cardArr[3].suitIndex));
				}
				else if (i == 18) {
					printf("|%c     %c|", suitToPicture(suit, hand.cardArr[4].suitIndex), suitToPicture(suit, hand.cardArr[4].suitIndex));
				}
			}
			else if ((i == 2 || i == 6 || i == 10 || i == 14 || i == 18) && k == 8) {
				printf("- - - - -");
			}
		}
		printf("\n");
	}
}
}

int parseHand(Hand hand, Hand flop, char* suit[4], char* face[13], int flopTurnRiver, int handSpecs[7], int *flushCountP, int* straightCount, int cardArray[13]) {
	int flushCardArr[8] = { -1, -1 , -1, -1, -1, -1, -1, -1 };
	int handStrength = 10, straight = 0, flushIn = -1, straightRoyalF = 0, numOfPair = 0, strongerPairIn = -1, strongerThreeKind = -1, maxFlush = 0;
	int* highCardStraight;
	int flushCount[4] = { 0, 0, 0, 0 };
	bool flush = false, threeOfKind = false, quads = false;
	Card cardStraightArr[8];
	


	cardArray[hand.cardArr[0].faceIndex]++;
	cardArray[hand.cardArr[1].faceIndex]++;
	for (int i = 0; i < flopTurnRiver; i++) {		//Adds one to array of cards for each dealt card
		cardArray[flop.cardArr[i].faceIndex]++;
	}



	for (int i = 0; i < 12; i++) {
		if (cardArray[i] == 2) {
			numOfPair++;
			strongerPairIn = i;
		}
		else if (cardArray[i] == 3) {
			threeOfKind = true;
			strongerThreeKind = i;
			handStrength = updateHandStrength(7, handStrength);		//Three of Kind
			handSpecs[1] = strongerThreeKind;
		}
		else if (cardArray[i] == 4) {
			quads = true;
			handStrength = updateHandStrength(3, handStrength);		//Quads
		}
	}

	if (threeOfKind && numOfPair > 0) {
		handStrength = updateHandStrength(4, handStrength);		//Full house 
	}

	if (numOfPair == 1) {
		handStrength = updateHandStrength(9, handStrength);		//One Pair
		handSpecs[0] = strongerPairIn;
	}
	else if (numOfPair > 1) {
		handStrength = updateHandStrength(8, handStrength);		//Two Pair (Not == 2 because you could have three pairs on the board and hand strength is still two pair)
		handSpecs[0] = strongerPairIn;
	}

	 
	for (int i = -2; i < flopTurnRiver; i++) {
		enum Suit suit;
		if (i == -2) {
			suit = hand.cardArr[0].suitIndex;
		}
		else if (i == -1) {
			suit = hand.cardArr[1].suitIndex;			//Increments flush array based on suit of card
		}
		else {
			suit = flop.cardArr[i].suitIndex;
		}
		flushCount[suit]++;
	}

	
	for (int i = 0; i < 4; i++) {
		if (flushCount[i] > 4) {
			flushIn = i;
			handStrength = updateHandStrength(5, handStrength);
			if (hand.cardArr[0].suitIndex == flushIn) {				//Set high card for flush
				handSpecs[3] = hand.cardArr[0].faceIndex;

			}
			if (hand.cardArr[1].suitIndex == flushIn && hand.cardArr[1].faceIndex > hand.cardArr[0].faceIndex) {
				handSpecs[3] = hand.cardArr[1].faceIndex;
			}
			flush = true;
		}
		if (flushCount[i] > maxFlush) {
			maxFlush = flushCount[i];
		}
	}

	*flushCountP = maxFlush;		

	straight = checkStraight(hand, flop, suit, face, flopTurnRiver, cardStraightArr, flushCardArr, flushIn, &highCardStraight);
	*straightCount = straight;
	

	for (int i = 1; i < 8; i++) {
		if (flushCardArr[i] == flushIn) {			//Checks whether the cards in the straight are same suit
			straightRoyalF++;
		}
	}

	if (straight > 4 && flush && cardArray[0] != 0 && cardArray[12] != 0 && cardArray[11] != 0 && straightRoyalF > 3) {	//Royal Flush
		handStrength = updateHandStrength(1, handStrength);
	}
	else if (straight > 4 && flush && straightRoyalF > 3) {			//Straight Flush
		handStrength = updateHandStrength(2, handStrength);
		handSpecs[2] = highCardStraight;
	}
	else if (straight > 4) {				//Straight
		handStrength = updateHandStrength(6, handStrength);
		handSpecs[2] = highCardStraight;
	}

	tieBreaker(handStrength, strongerPairIn, strongerThreeKind, cardArray, hand, handSpecs);

	return handStrength;

}

void tieBreaker(int handStrength, int strongestPair, int strongestThrees, int cardArray[13], Hand hand, int handSpecs[7]) {
	int card1 = hand.cardArr[0].faceIndex;
	int card2 = hand.cardArr[1].faceIndex;
	int highCard = -1;


	if (handStrength == 9) {				//One Pair
		cardArray[strongestPair] = -1;

	}
	else if (handStrength == 8) {			//Two Pair
		cardArray[strongestPair] = -1;
		for (int i = 12; i > -1; i--) {
			if (cardArray[i] == 2) {		//Go from highest card to lowest, and remove the 2nd best pair to find high card
				cardArray[i] = -1;
				handSpecs[6] = i;
			}
		}
	}
	else if (handStrength == 7) {			//Thre of Kind
		cardArray[strongestThrees] = -1;
	}
	else if (handStrength == 4) {			//Full House
		for (int i = 12; i >= 0; i--) {
			if (cardArray[i] == 3) {
				handSpecs[4] = i;
			}
			else if (cardArray[i] == 2) {
				handSpecs[3] = i;
			}
		}
	}
	else if (handStrength == 3) {			//Quads
		for (int i = 0; i < 12; i++) {
			if (cardArray[i] == 4) {
				handSpecs[5] = i;
			}
		}
	}



	if (cardArray[card1] != -1 && handStrength != 5) {		//Flush high card is already determined
		highCard = card1;
		handSpecs[3] = highCard;
	}
	if (cardArray[card2] != -1 && card2 > highCard && handStrength != 5) {
		highCard = card2;
		handSpecs[3] = highCard;
	}
	

}

int updateHandStrength(int newHandStrength, int oldHandStrength) {		//Function to update hand strength if strength is better than previous
	if (newHandStrength < oldHandStrength) {
		oldHandStrength = newHandStrength;
	}
	return oldHandStrength;
}

void orderStraightArray(Card cardStraightArr[7], char* face[13], int flopTurnRiver) {
	Card temp;
	for (int i = 0; i < flopTurnRiver + 2; i++) {
		for (int k = i + 1; k < flopTurnRiver + 2; k++) {								//For loop to set cards in order 
			if (cardStraightArr[k].faceIndex <= cardStraightArr[i].faceIndex) {
				temp = cardStraightArr[i];
				cardStraightArr[i] = cardStraightArr[k];
				cardStraightArr[k] = temp;
			}
		}
	}
}

int checkStraight(Hand hand, Hand flop, char* suit[4], char* face[13], int flopTurnRiver, Card cardStraightArr[7], int flushCardArr[5], int flushIn, int* highCardStraight) {
	int cardArray[14] = { 0 };		//Sort cards in order, check whether there exists a string of 5 cards in a row
	cardStraightArr[0] = hand.cardArr[0], cardStraightArr[1] = hand.cardArr[1], cardStraightArr[2] = flop.cardArr[0], cardStraightArr[3] = flop.cardArr[1], cardStraightArr[4] = flop.cardArr[2], cardStraightArr[5] = flop.cardArr[3], cardStraightArr[6] = flop.cardArr[4];
	bool ace = false;
	int count = 1, countCard = 0;

	orderStraightArray(cardStraightArr, face, flopTurnRiver);
	if (cardStraightArr[0].faceIndex == 0) {								//If there is an ace, make it useable for highest and lowest card
		cardStraightArr[7].faceIndex = 13;								
		cardStraightArr[7].suitIndex = cardStraightArr[0].suitIndex;
	}

	for (int i = 0; i < flopTurnRiver + 2; i++) {
		for (int k = i + 1; k < flopTurnRiver + 2; k++) {
			if (cardStraightArr[i].faceIndex == cardStraightArr[k].faceIndex) {			//Removes duplicates
				if (cardStraightArr[k].suitIndex != flushIn) {					//If the duplicate has the same suit as the flush index, don't remove becaue you could destroy a straight/royal
					cardStraightArr[k].faceIndex = -5;
				}
				else {
					cardStraightArr[i].faceIndex = -5;
				}
			}
		}
	}

	orderStraightArray(cardStraightArr, face, flopTurnRiver);		

	for (int i = 0; i < flopTurnRiver + 3; i++) {
		for (int k = i + 1; k < flopTurnRiver + 3; k++) {
			countCard++;
			if ((cardStraightArr[k].faceIndex - countCard) == cardStraightArr[i].faceIndex) {
				flushCardArr[k] = cardStraightArr[k].suitIndex;
				count++;
				if (count > 4) {
					*highCardStraight = cardStraightArr[k].faceIndex;
					return count;
				}
				
			}
			else {
				k = 100;
			}
		}
		for (int i = 0; i < 8; i++) {
			flushCardArr[i] = -1;
		}
		count = 1;
		countCard = 0;
	}
	return count;

}


void increasePot(int increase, int *pot) {
	*pot = *pot + increase;
}

void resetPot(int* pot) {
	*pot = 0;
}

void resetCardArray(int cardArray[13]) {
	for (int i = 0; i < 13; i++) {
		cardArray[i] = 0;
	}
}

int checkBet(int bet, int minBetNeeded) {
	if (bet == -1) {						//Fold
		return -1;
	}
	else if (bet == minBetNeeded) {			//Check
		return 1;
	}
	else if (bet > minBetNeeded) {			//Raise
		return 0;
	}

		return -1;

}

int computerDecision(int handStrength, int pot, int playerIncreasePot, Hand hand, Hand flop, int flopTurnRiver, int* flushCount, int* straightCount, int handSpecs[7], int cardArray[13]) {			//Should add the possiblity of improving hand? Drawing for flush/straight
	double play = .5;
	int flushCountArr[4] = { 0 };
	int straightFlop = 0, maxFlushCount = 0;
	Hand deadHand;
	enum Suit suit;
	deadHand.cardArr[0].faceIndex = -5;
	deadHand.cardArr[1].faceIndex = -5;

	if (hand.cardArr[0].faceIndex > 10 && hand.cardArr[1].faceIndex > 10) {			//Dealt two face cards
		play += .2;
	}
	else {
		if (hand.cardArr[0].faceIndex > 10) {		//Dealt a face cards
			play += .1;
		}
		else if (hand.cardArr[1].faceIndex > 10) {
			play += .1;
		}
		else {					//No face cards
			play -= .3;	
		}
	}
	
	if (handStrength > 8) {
		play -= (playerIncreasePot * .01);			//Based on size of bet, decrease odds of playing only if have a bad hand (dont get scared off a good hand)
	}

	if (hand.cardArr[0].faceIndex == hand.cardArr[1].faceIndex) {		//Dealt a pocket pair
		play += 1.0;
	}

	for (int i = 0; i < flopTurnRiver; i++) {
		suit = flop.cardArr[i].suitIndex;
		flushCountArr[suit]++;
		if (flushCountArr[suit] > maxFlushCount) {
			maxFlushCount = flushCountArr[suit];			//Max number of suited cards on the board, not including the player hand
		}
	}

	
	if (*flushCount == 4 && flopTurnRiver == 4) {			//Need one more card for flush after turn
		play += .1;
	}
			
	if (*straightCount == 4 && flopTurnRiver == 4) {		//Need one more card for straight after turn
		play += .05;
	}

	

	if (flopTurnRiver == 5) {
		if (handStrength < 9) {
			play += .2;
		}
		else {
			play -= .1;
		}

		if (handStrength < 5) {		//Hand is full house or better, almost always want to play that
			play += 1.0;
		}

		if (maxFlushCount == 4 && handStrength > 5) {		//Opponent needs one card for flush, and we don't have a flush
			play -= .3;
		}

	}
	else if (flopTurnRiver == 4) {
		if (handStrength < 8) {			//Three of a kind or better off the flop
			play += 1.0;
		}
		if (*flushCount == 4 || *straightCount == 4) {		//Need one more card to draw a straight/flush after the flop
			play += .3;
		}
		if (maxFlushCount == 3) {		//Three suited cards on the board off the flop
			play -= .1;
		}
	}
	else {
		if (handStrength < 8) {			//Three of a kind or better off the flop
			play += 1.0;
		}
		if (*flushCount == 4 || *straightCount == 4) {		//Need one more card to draw a straight/flush after the flop
			play += .3;
		}
		if (maxFlushCount == 3) {		//Three suited cards on the board off the flop
			play -= .1;
		}
	}

	if (flopTurnRiver == 2) {		//Always limp/call 
		return playerIncreasePot;
	}

	if (playerIncreasePot == 0) {
		return 0;
	}

	if (play < .5) {
		return -1;
	}
	else if (play > .5 && play < 1.0) {
		return playerIncreasePot;
	}

	return playerIncreasePot + (pot * .5);
}	