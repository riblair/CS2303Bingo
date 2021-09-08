/*
 * space.c
 *
 *  Created on: Jan 27, 2020
 *      Author: Therese
 */
#include "space.h"

void initSpace(cardCellContent** corner, int howManyCols)
{
	for(int row = 0; row< howManyCols; row++)
	{
		for(int col = 0; col < howManyCols; col++)
		{
			cardCellContent* x = (cardCellContent*) malloc (sizeof(cardCellContent)); //reserve a cardCell on heap
			x->row = row;
			x->col = col;
			//call rand
			int randomLet = rand() % 26 + 65;
			x->letter = (char)randomLet;
			int randomNum = rand() % 10 + 48;
			x->digit = (char)randomNum;
			x->matched = false;
			cardCellContent**  thatCellP = corner + row*howManyCols + col;
			*thatCellP = x; //put its address into bingo card space
		}
	}
}
void displaySpace(cardCellContent** corner, int howManyCols)
{
	for(int row = 0; row< howManyCols; row++)
	{
		for(int col = 0; col < howManyCols; col++)
		{
			cardCellContent**  thatCellP = corner + row*howManyCols + col;
			char let = (*thatCellP)->letter;
			char digit = (*thatCellP)->digit;
			printf("|%c%c", let, digit);
		}
		printf("|\n");
	}
}

void makeLetterLowercase(cardCellContent** corner, char letter, char number, int howManyCols)
{
	for(int row = 0; row< howManyCols; row++)
		{
			for(int col = 0; col < howManyCols; col++)
			{
				cardCellContent**  thatCellP = corner + row*howManyCols + col;
				if((*thatCellP)->letter == letter && (*thatCellP)->digit == number)
				{
					int lowerCase = (int)(*thatCellP)->letter + 32;
					(*thatCellP)->letter = (char)lowerCase;
					(*thatCellP)->matched = true;
				}
			}
		}
}
bool win(cardCellContent** corner) {
	bool hasWin = true; // initalizes checker variable and sets it to true.

	//first check, checks if there is a bingo in any column
	for(int i = 0; i < 5; i++) { // checks every row
		hasWin = true; //reset variable
		for(int j = 0; j < 5;j++) { // checks every value in the column
			cardCellContent** aCellPointer = corner+i+j*5;
			if(!(*aCellPointer)->matched) {
				hasWin = false;
			}
		}
		if(hasWin) {
			return true;
		}
	}

	hasWin = true;
	//second check, checks if there is a bingo in any row
	for(int i = 0; i < 5; i++) { // checks every column
		hasWin = true;
		for(int j = 0; j < 5;j++) { // checks every value in row
			cardCellContent** aCellPointer = corner+i*5+j;
			if(!(*aCellPointer)->matched) {
				hasWin = false;
			}
		}
		if(hasWin) {
			return true;
		}
	}

	hasWin = true;
	//third check, checks the top left to bottom right diag.
	for(int i = 0; i < 5;i++) { // checks every value in diag
		cardCellContent** aCellPointer = corner+i*6;
		if(!(*aCellPointer)->matched) {
			hasWin = false;
		}
	}
	if(hasWin) {
		return true;
	}

	hasWin = true;
		//third check, checks the top left to bottom right diag.
		for(int i = 0; i < 5;i++) { // checks every value in diag
			cardCellContent** aCellPointer = 4+corner+i*4;
			if(!(*aCellPointer)->matched) {
				hasWin = false;
			}
		}
		if(hasWin) {
			return true;
		}
		return false;
}
