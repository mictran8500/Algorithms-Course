//Created by Michael Tran, CS350, 2/14/2020

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Find the location of the first occurrence of pattern in text
// or say that it does not occur if that is the case.
// If you find the pattern in the text, output the index of the
// first letter in text where the pattern first occurs.

// You must also print the total number of character comparisons that
// the program made.

// If the number of unchecked characters in the text is ever less than
// the length of the pattern the algorithm must stop.

// NOTE:  All test texts and patterns should not contain any white space
//        (e.g. blank space character, newline, tab, etc.) as scanf
//        will stop on such an input character.

int smartsearch(char * ascii, char * text, char * pattern, int start_marker, int n, int counter)
{

  int k = 0;			//k will act as a flag
  int i = strlen(pattern);	//i represents size of pattern, used to check if entire pattern
  				//is checked
  int m = start_marker;		//marker represents the index where pattern should start checking
  int num;

  //Base case when start_marker is out of bounds
  if(start_marker > n)
  {
	  printf("Number of character comparisons:  %d \n", counter);
	  return 0;
  }

  //Checking if pattern matches within text starting with last index of pattern 
  do
  {
  	++counter;

	//If character matches, move indexes one previous
  	if (pattern[i-1] == text[m])
	{
		--i;
		--m;
	}

  }while(i > 0 && pattern[i-1] == text[m]);

  //When the entire pattern has been checked, that means the pattern is found
  if(i == 0)
  { 
	  printf("Number of character comparisons:  %d \n", counter);
	  printf("First index where pattern is found: %d \n", m+1);
	  return 1;	//Returns 1 to verify that pattern has been found in text
  }
  else
  {

	num = text[start_marker];	//Grabing start marker character
	start_marker += ascii[num];	//Shifting start marker depending on shift value 

	k += smartsearch(ascii, text, pattern, start_marker, n, counter);
  }

  return k;
}

int main()
{

  char ascii[128];
  char text[10000] ;
  char pattern[200] ;
  int m,n,i,j ;
  int counter;
  int num;

  printf("enter text : ") ;
  scanf("%s", text) ;
  printf("enter pattern you are searching for : ") ;
  scanf("%s", pattern) ;

  m = strlen(pattern) ;
  n = strlen(text) ;
  printf("\n");
  printf("The pattern has %d characters and the text has %d characters.\n", m,n) ;

  //Filling ascii array with pattern size at each index
  for(i = 0; i < 128; ++i)
	  ascii[i] = m;

  //Overriding characters in ascii array with correct shift values
  for(i = m-1, j = 0; i > 0; --i, ++j)
  {
	 //Finding which index to override value using ascii value
	 //And then assigning shift value to correct index
	 num = pattern[j]; 
	 ascii[num] = i;
  }

  //Calling smart search to find pattern
  num = smartsearch(ascii, text, pattern, m-1, n-1, counter);

  if(num != 1)
	  printf("Pattern was not found in text. \n");

  printf("\n");

}


