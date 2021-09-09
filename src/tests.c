/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"
#include "production.h"
#include "LinkedList.h"
#include "space.h"


bool tests()
{
	bool answer = false;

	//test the functions that get used
	//order the tests from simplest first -- this produces building blocks for use in more complex tests
	//check how functions are used in production code, this gives clues about how to provide the arguments for the invocation
	bool ok1 = testReadFile();
	bool ok3 = testMakeLList();
	bool ok4 = testEnqueue();
	bool ok5 = testPrintHistory();
	bool ok6 = testcallLetter();
	bool ok7 = testcallNumber();
	bool ok8 = testmakeLetterLowercase();
	bool ok9 = testWinRow();
	bool ok10 = testWinColumn();
	bool ok11 = testWinTopLeftDiag();
	bool ok12 = testWinTopRightDiag();

	answer = ok1 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10 && ok11 && ok12;
	//answer = true;
	return answer;
}

bool testReadFile()
{
	puts("starting testReadFile"); fflush(stdout);
	bool ok = true;

		cardCellContent** theSpaceP = (cardCellContent**) malloc(5*5*sizeof(cardCellContent*));
		cardCellContent** nextSpace = theSpaceP+1;
		printf("first is %x and second is %x \n", theSpaceP, nextSpace);

		cardCellContent* where = (cardCellContent*) theSpaceP;
		cardCellContent* whereNext = where+1;
		printf("first is %x and second is %x\n", where, whereNext);






	return ok;
}


bool testMakeLList()
{
	bool ok = true;
	puts("starting testMakeLList");fflush(stdout);
	//what are the criteria for success for make LList?
	//should be able to make one, add data to it, get the data back
	//test case 1:
	LLNode* theListP = makeEmptyLinkedList();
	if(theListP == NULL)
	{
		ok = false;
	}
	bool rightAnswer = true;
	bool answer = isEmpty(theListP);
	if(answer!=rightAnswer)
	{
		ok = false;
	}
	//test case 2:
	//TODO more test cases here
	if(ok)
	{
		puts("test make LList did pass.");
	}
	else
	{
		puts("test make LList did not pass.");
	}

	return ok;
}
bool testEnqueue()
{
	bool ok = true;
	if(ok)
	{
		puts("testEnqueue did pass.");
	}
	else
	{
		puts("testEnqueue did not pass.");
	}
	return ok;
}
bool testRemoveFromList()
{
	bool ok = true;
	//cases:
	//1 list is empty:return same list
	//2 list is of length one, and item is present: return empty list
	//3 list is of length one, and item is not present: return same list
	//4 list is longer than one, item is present, at first location: return list starting at second element
	//5 list is longer than one, item is present, not at first location: return list with item removed
	//6 list is longer than one, item is not present: return same list
	LLNode* case1 = makeEmptyLinkedList();
	//	Payload* pay1 = (Payload*) malloc(sizeof(Room));
	//	pay1->roomNumber = 1;
	//	LLNode* ans = removeFromList(case1, pay1);
	//	if((ans != case1) || (ans->payP != (Payload*)0))
	//	{
	//		ok = false;
	//
	//	}
	//	printf("testRemove case 1 with %d\n", ok); fflush(stdout);
	//	savePayload(case1, pay1);
	//	//this is case2
	//	ans = removeFromList(case1, pay1);
	//	if((ans != case1) || (ans->payP != (Payload*)0))
	//	{
	//		ok = false;
	//
	//	}
	//	printf("testRemove case 2 with %d\n", ok); fflush(stdout);
	//	//now case 3
	//	Payload* pay3 = (Payload*) malloc(sizeof(Room));
	//	pay3->roomNumber = 3;
	//	ans = removeFromList(case1, pay3);
	//	if(ans != case1)//this is only a partial check for list unchanged
	//	{
	//		ok = false;
	//
	//	}
	//	printf("testRemove case 3 with %d\n", ok); fflush(stdout);
	//	//now case 4
	//	case1 = makeEmptyLinkedList();
	//	pay1 = (Payload*) malloc(sizeof(Room));
	//	pay1->roomNumber = 1;
	//	savePayload(case1, pay1);
	//	pay3 = (Payload*) malloc(sizeof(Room));
	//	pay3->roomNumber = 3;
	//	savePayload(case1, pay3);
	//	ans = removeFromList(case1, pay1);
	//
	//	if(ans == case1)
	//	{
	//		ok = false;
	//
	//	}
	//	printf("testRemove case 4 with %d\n", ok); fflush(stdout);
	//	//now case 5
	//	case1 = makeEmptyLinkedList();
	//	pay1 = (Payload*) malloc(sizeof(Room));
	//	pay1->roomNumber = 1;
	//	savePayload(case1, pay1);
	//	pay3 = (Payload*) malloc(sizeof(Room));
	//	pay3->roomNumber = 3;
	//	savePayload(case1, pay3);
	//	//puts("trying case 5");fflush(stdout);
	//	ans = removeFromList(case1, pay3);//ans should be equal to case1
	//	LLNode* theNext = (LLNode*) ans->next; //this is element where pay3 got attached
	//	Payload* check = (Payload*) 0;
	//	if (theNext)
	//	{
	//		check = theNext->payP; //this should be pay3, which should have been removed
	//	}
	//	//printf("testRemove returned from case 5\n"); fflush(stdout);
	//	if((ans != case1) || (check != (Payload*)0))//disquiet
	//	{
	//		ok = false;
	//
	//	}
	//	//printf("ans == case1 is %d\n", ans==case1);
	//	//printf("check != 0 is %d\n", check != (Payload*)0);
	//	printf("testRemove case 5 with %d\n", ok); fflush(stdout);
	//	//now case 6
	//	case1 = makeEmptyLinkedList();
	//	pay1 = (Payload*) malloc(sizeof(Room));
	//	pay1->roomNumber = 1;
	//	savePayload(case1, pay1);
	//	pay3 = (Payload*) malloc(sizeof(Room));
	//	pay3->roomNumber = 3;
	//	savePayload(case1, pay3);
	//	Payload* another = (Payload*) malloc(sizeof(Room));
	//	another->roomNumber=2;
	//	ans = removeFromList(case1, another);
	//	if((ans != case1))
	//	{
	//		ok = false;
	//
	//	}
	//	printf("testRemove case 6 with %d\n", ok); fflush(stdout);
	return ok;
}
bool testPrintHistory()
{
	bool ok = true;
	LLNode* testList = makeEmptyLinkedList();

	//test empty list
		if(printHistoryTest(testList) != 0){
			ok = false;
		}

	//test 1-element list

		//create element and add to list
			cardCellContent* aCall = (cardCellContent*)malloc(sizeof(cardCellContent));
			aCall->letter = 'A';
			aCall->digit = 0;
			savePayload(testList, aCall);

		//test
			if(printHistoryTest(testList) != 1){
				ok = false;
			}

	//test 50-element list
		//add element to list 49 more times
			for(int i = 0; i < 49; i++){
				savePayload(testList, aCall);
			}

		//test
			if(printHistoryTest(testList) != 50){
				ok = false;
			}

	if(ok)
	{
		puts("testprintHistory did pass.");
	}
	else
	{
		puts("testprintHistory did not pass.");
	}
	return ok;
}

bool testcallLetter()
{
	bool ok = true;
	puts("starting testcallLetter");

	char letter = callLetter();
	int letterI = (int)letter;
	if(letterI == NULL)
	{
		ok = false;
	}
	if(letterI < 65 || letterI > 90)
	{
		ok = false;
	}
	if(ok)
	{
		puts("test callLetter did work");
	}
	else
	{
		puts("test callLetter didn't work");
	}
	return ok;
}

bool testcallNumber()
{
	bool ok = true;
	puts("starting testcallLetter");
	char number = callNumber();
	int numberI = (int)number;
	if(numberI == NULL)
	{
		ok = false;
	}
	if(numberI < 48 || numberI > 57)
	{
		ok = false;
	}
	if(ok)
	{
		puts("test callNumber did work");
	}
	else
	{
		puts("test callNumber didn't work");
	}
	return ok;
}

bool testmakeLetterLowercase()
{
	bool ok = true;
	cardCellContent** theBoardTest = (cardCellContent**) malloc(5*5*sizeof(cardCellContent*));

	initSpace(theBoardTest, 5);

	//Making a consistent board
	cardCellContent* answer1 = (cardCellContent*) malloc(sizeof(cardCellContent));
	answer1->col = 0;
	answer1->row = 0;
	answer1->letter = 'A';
	answer1->digit = '0';
	*theBoardTest = answer1;
	cardCellContent* answer2 = (cardCellContent*) malloc(sizeof(cardCellContent));
	answer2->col = 2;
	answer2->row = 2;
	answer2->letter = 'E';
	answer2->digit = '3';
	cardCellContent** thatCellP = theBoardTest + 12;
	*thatCellP = answer2;

	makeLetterLowercase(theBoardTest,'A','0',5);
	int a1 = (int) (*theBoardTest)->letter;
	if(a1 != 97)
	{
		ok = false;

	}
	makeLetterLowercase(theBoardTest,'E','3',5);
	int a2 = (int) (*thatCellP)->letter;
	if(a2 != 101)
	{
		ok = false;
	}

	if(ok)
	{
		puts("test makeLetterLowercase did work");
	}
	else
	{
		puts("test makeLetterLowercase didn't work");
	}

	return ok;
}

bool testWinRow() { //tests the win of the top row.
	bool ok = false;

	cardCellContent** theBoardTest = (cardCellContent**) malloc(5*5*sizeof(cardCellContent*));

	initSpace(theBoardTest, 5);

	cardCellContent** first = theBoardTest;
	cardCellContent** second = theBoardTest+1;
	cardCellContent** third = theBoardTest+2;
	cardCellContent** fourth = theBoardTest+3;
	cardCellContent** fifth = theBoardTest+4;

	(*first)->matched = true;
	(*second)->matched = true;
	(*third)->matched = true;
	(*fourth)->matched = true;
	(*fifth)->matched = true;

	ok = win(theBoardTest);
	if(ok) {
		puts("testWinRow passed!");
		ok = true;
	}
	else {
		puts("testWinRow failed!");
	}

	return ok;
}

bool testWinColumn() { //tests the win of the leftMost column.
	bool ok = false;

	cardCellContent** theBoardTest = (cardCellContent**) malloc(5*5*sizeof(cardCellContent*));

	initSpace(theBoardTest, 5);

	cardCellContent** first = theBoardTest;
	cardCellContent** second = theBoardTest+5;
	cardCellContent** third = theBoardTest+10;
	cardCellContent** fourth = theBoardTest+15;
	cardCellContent** fifth = theBoardTest+20;

	(*first)->matched = true;
	(*second)->matched = true;
	(*third)->matched = true;
	(*fourth)->matched = true;
	(*fifth)->matched = true;

	if(win(theBoardTest)) {
		puts("testWinColumn passed!");
		ok = true;
	}
	else {
		puts("testWinColumn failed!");
	}

	return ok;
}

bool testWinTopLeftDiag() { //tests the win of the top left Diagonal.
	bool ok = false;
	cardCellContent** theBoardTest = (cardCellContent**) malloc(5*5*sizeof(cardCellContent*));

	initSpace(theBoardTest, 5);

	cardCellContent** first = theBoardTest;
	cardCellContent** second = theBoardTest+6;
	cardCellContent** third = theBoardTest+12;
	cardCellContent** fourth = theBoardTest+18;
	cardCellContent** fifth = theBoardTest+24;

	(*first)->matched = true;
	(*second)->matched = true;
	(*third)->matched = true;
	(*fourth)->matched = true;
	(*fifth)->matched = true;

	if(win(theBoardTest)) {
		puts("testWinTopLeftDiag passed!");
		ok = true;
	}
	else {
		puts("testWinTopLeftDiag failed!");
	}

	return ok;
}

bool testWinTopRightDiag() { //tests the win of the top right Diagonal.
	bool ok = false;
	cardCellContent** theBoardTest = (cardCellContent**) malloc(5*5*sizeof(cardCellContent*));

	initSpace(theBoardTest, 5);

	cardCellContent** first = theBoardTest+4;
	cardCellContent** second = theBoardTest+8;
	cardCellContent** third = theBoardTest+12;
	cardCellContent** fourth = theBoardTest+16;
	cardCellContent** fifth = theBoardTest+20;

	(*first)->matched = true;
	(*second)->matched = true;
	(*third)->matched = true;
	(*fourth)->matched = true;
	(*fifth)->matched = true;

	if(win(theBoardTest)) {
		puts("testWinTopRightDiag passed!");
		ok = true;
	}
	else {
		puts("testWinTopRightDiag failed!");
	}

	return ok;
}

