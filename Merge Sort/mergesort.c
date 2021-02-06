//Mergesort Algorithm
//Michael Tran, CS350, 1/30/2020

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max 100

int orig[max];
int temp[max];

//sorts the designated portion of the array
void sorting(int lo, int mid, int hi)
{
	int i;
	int finger1;
	int finger2;

	//For loop going through the temp array and copying the sorted values into the 
	//original array
	for(i = lo, finger1 = lo, finger2 = mid+1; finger1 <= mid && finger2 <= hi; ++i)
	{
		
		if(orig[finger1] > orig[finger2])
		{
			temp[i] = orig[finger2];
			++finger2;
		}
		else 
		{
			temp[i] = orig[finger1];
			++finger1;
		}
	}

	//Goes through the remainder of the temp array b/c the for-loop stops when
	//either of the halves reaches its end
	//So one half has not reached its last index yet, and that is dealth with here
	while(finger1 <= mid)
	{
		temp[i] = orig[finger1];
		++i;
		++finger1;
	}
	while(finger2 <= hi)
	{
		temp[i] = orig[finger2];
		++i;
		++finger2;
	}
		

	//Copying temp array values into original array
	for(i = lo; i <= hi; ++i)
		orig[i] = temp[i];
}


//recursive part that splits the portion of the array into halves
void mergesort(int lo, int hi)
{
	int mid = (lo+hi)/2;

	if(lo == hi)
		return;

	mergesort(lo, mid);
	mergesort(mid+1, hi);
	
	sorting(lo, mid, hi);
}

int main()
{
	int i;
	int n;

	//Reading in numbers for array
	printf("Please first enter in the total amount of numbers, and then each number in afterwards: \n");

	scanf("%d",&n);

	for(i = 0; i < n; ++i)
		scanf("%d", &orig[i]);

	//This is where the mergesorting begins
	mergesort(0, n-1);	

	//Printing out sorted array
	printf("Here is your list in sorted order: ");

	for(i = 0; i < n; ++i)
		printf("%d ", orig[i]);

	printf("\n");

	return 0;
}
