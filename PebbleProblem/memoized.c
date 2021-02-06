//Pebbles Memoized Solution
//Michael Tran, CS350, 2/20

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

// begin TIMING variables
int signal ;
struct timeval Tp;
struct timezone Tzp ;
long sec,usec ;
double dsec1, dsec2 ;
// end TIMING variables


void begin_timing()
{
  signal = gettimeofday(&Tp,&Tzp) ;
  usec = Tp.tv_usec ;
  sec = Tp.tv_sec ;
  dsec1 = sec + usec/1000000.0 ;
}
  
void end_timing()
{
  signal = gettimeofday(&Tp,&Tzp) ;
  usec = Tp.tv_usec ;
  sec = Tp.tv_sec ;
  dsec2 = sec + usec/1000000.0 ;
}

int find_max(int a, int b) {
	if(a > b)
		return a;
	else
		return b;
}

int search(int path[5][6], int hold[5][6], int i, int j){

	//Base Case
	if(i == 0 && j == 0)
		return path[i][j];

	//Checking if this space has a value saved
	if(hold[i][j] != -1)
		return hold[i][j];

	//Edge Cases
	if(i == 0)
		return search(path, hold, i, j-1) + path[i][j];
	if(j == 0)
		return search(path, hold, i-1, j) + path[i][j];


	int most = find_max(search(path, hold, i-1, j), search(path, hold, i, j-1)) + path[i][j];
	hold[i][j] = most;

	return most;

}

int main(){

	int i, j;
	int path[5][6];
	int hold[5][6];

	unsigned seed;

	printf("Input a random number seed: ");
	scanf("%u", &seed);
	srand(seed);

	//In 2D array, pebble will be represented by 1
	for(i = 0; i < 5; ++i){
		for(j = 0; j < 6; ++j){
			if(rand()%3 == 0)	//Randomly generates value, will insert pebble at location if value is 5
				path[i][j] = 1;
			else
				path[i][j] = 0;
		}
	}

	//initializing memo array with -1 all around
	for(i = 0; i < 5; ++i){
		for(j = 0; j < 6; ++j){
			hold[i][j] = -1;
		}
	}

	printf("Pebbles are represented by [1].\n");

	//Displaying 2D array
	for(i = 0; i < 5; ++i){
		for(j = 0; j < 6; ++j){
			printf("[%d] ", path[i][j]);
		}
		printf("\n");
	}

	begin_timing();	
	printf("Maximum Pebbles: %d \n", search(path,hold,4,5));
	end_timing();
	printf("Time: %18lf\n", dsec2-dsec1);
}
