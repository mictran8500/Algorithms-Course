//Pebbles Tabular Solution
//Michael Tran, CS350, 2/24

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
	if(a > b) return a;
	return b;
}

int search(int path[5][6], int hold[5][6])
{
	int i, j;

	hold[0][0] = path[0][0];

	for(i = 0; i < 5; ++i) {
		for(j = 0; j < 6; ++j) {
		
			if(i == 0 && j == 0) ;
			else if(i == 0)
				hold[i][j] = hold[i][j-1] + path[i][j];
			else if(j == 0)
				hold[i][j] = hold[i-1][j] + path[i][j];
			else
				hold[i][j] = find_max(hold[i][j-1], hold[i-1][j]) + path[i][j];
		}
	}

	return hold[i-1][j-1];
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

	printf("Pebbles are represented by [1].\n");

	//Displaying 2D array
	for(i = 0; i < 5; ++i){
		for(j = 0; j < 6; ++j){
			printf("[%d] ", path[i][j]);
		}
		printf("\n");
	}

	begin_timing();	
	printf("Maximum Pebbles: %d \n", search(path,hold));
	end_timing();
	printf("Tabular time: %18lf \n", dsec2-dsec1);
}
