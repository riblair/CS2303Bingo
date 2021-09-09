/*
 * production.c
 *
 *  Created on: Feb 6, 2021
 *      Author: theresesmith
 */

#include "production.h"

bool production(int argc, char* argv[])
{
	bool answer = true;
	int nCalls = 250;

		if(argc <=1) //no interesting information
		{
			puts("Didn't find any arguments.");
			fflush(stdout);
			answer = false;
		}
		else //there is interesting information
		{
			printf("Found %d arguments.\n", argc);
			fflush(stdout);
			long aL=-1L;


			for(int i = 1; i<argc; i++) //don't want to read argv[0]
			{//argv[i] is a string
				//in this program our arguments are a filename followed by the max of rooms, followed by max of treasure
				switch(i)
				{
				case 1:

					//this is the number of calls

					aL= strtol(argv[i], NULL, 10);
					nCalls = (int) aL;
					if(nCalls <0)
					{
						answer = false;
					}
					printf("Number of calls is %d\n",nCalls);fflush(stdout);
					break;

				default:
					puts("Unexpected argument count."); fflush(stdout);
					answer = false;
					break;
				}//end of switch
			}//end of for loop on argument count
			puts("after reading arguments"); fflush(stdout);

		}//end of command line arguments


		//initialize a linked list
		LLNode* theListP = makeEmptyLinkedList();

		//obtain space for bingo card

		cardCellContent** theSpaceP = (cardCellContent**) malloc(5*5*sizeof(cardCellContent*));
	    initSpace(theSpaceP, 5);

	   // displayCard
        displaySpace(theSpaceP, 5);
        //the caller is going call some random values
	    for(int i = 0; i<nCalls; i++)
	    {
	    	//get what caller calls
	    	char callL = callLetter();
	    	char callN = callNumber();

	    	//add call to linked list
				// allocate space for cardCellContent
				cardCellContent* currCall = (cardCellContent*)malloc(sizeof(cardCellContent));

				// add save callL and callN
				currCall->letter = callL;
				currCall->digit = callN;

				// savePayload(LinkedList, cardCellContent*)
				savePayload(theListP, currCall);

	    	//is it a match?
	    	makeLetterLowercase(theSpaceP,callL,callN,5);
	    	//check for a win here?
	    	if(win(theSpaceP)){
	    		puts("Congratulations, You Win!");
	    		displaySpace(theSpaceP,5);
	    		return true;
	    	}
	    	//show/display the board
	    	puts("-----------------");
	    	displaySpace(theSpaceP,5);
	    	//save result on linked list
	    	//did we win?
	    }

	    //printHistory
	    puts("\nPrinting call history...");
	    printHistory(theListP);

		return answer;
}
bool getYesNo(char* query)
{
   bool answer = true; //so far
   char said = 'x';
   do
   {
	 printf("%s (y/n):",query);
     fflush(stdout);
     fflush(stdin);
     scanf("%c",&said);
   }while((said!= 'y')&&(said!='n'));
   if(said=='n')
   {
	   answer=false;
   }


   return answer;
}
