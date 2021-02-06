//Michael Tran, CS350, 2/25/2020

#include <stdlib.h>
#include <stdio.h>

int choose(int n, int k, int array[n][k+1]) {

	//Base Cases
	if(n == 0 || k == 0 || n < k)
		return 0;
	else if(n == k)
		return 1;
	else if(k == 1)
		return n;


	int i, j;
	for(i = 0; i < n; ++i) {
		for(j = 0; j <= k; ++j) {
		
			if(i == 0)
				array[i][j] = 0;
			else if(j == 0)
				array[i][j] = 1;
			else if(i == j)
				array[i][j] = 1;
			else if(j == 1)
				array[i][j] = i;
			else
				array[i][j] = array[i-1][j-1] + array[i-1][j];
		}
	}

	return array[n-1][k-1] + array[n-1][k];
}

int main() {

	int n, k;
	printf("Please enter the 'n' value: ");
	scanf("%d", &n);

	printf("Please enter the 'k' value: ");
	scanf("%d", &k);

	int array[n][k+1];

	printf("Result: %d \n", choose(n, k, array));
}

