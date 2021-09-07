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
			x->row = 0;
			x->col = 0;
			//call rand
			x->letter = 'A';
			x->digit = '0';
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
