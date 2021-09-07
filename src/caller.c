/*
 * caller.c
 *
 *  Created on: Sept 6, 2021
 *      Author: Cole Parks
 */

#include "caller.h"
char callLetter()
{
	int randomLet = rand() % 26 + 65;
	char x = (char)randomLet;
	return x;
}
char callNumber()
{
	int randomNum = rand() % 10 + 48;
	char x = (char)randomNum;
	return x;
	return 'a';
}
// Calls a letter and number combination and marks the board



