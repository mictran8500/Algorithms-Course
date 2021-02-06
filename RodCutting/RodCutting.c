//Michael Tran, CS350, 2/27/2020
//Dynamic Programming, Rod-Cutting Problem

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int find_max(int a, int b) {
	if(a > b) return a;
	return b;
}

int RodCutting(int n, int prices[]) {

	int i,j,max;
	int hold[n+1];
	hold[0] = 0;	//index 0 represents no rod, therefore price = 0

	for(i = 0; i <= n; ++i) {
		max = -999;
		
		for(j = 1; j <= i; ++j) {
			max = find_max(max, prices[j] + hold[i-j]);
			hold[i] = max;
		}
	}

	return hold[n];
}

int main() {

	//Array of prices, index corresponding to the length of the rod portion,
	//and how much that rod portion is priced at
	int prices[] = {0, 3, 8, 1, 5, 8, 12, 4};
	int n = 7;

	int check = RodCutting(n, prices);
	printf("Greatest Price: %d \n", check);

}
