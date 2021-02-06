//Partitionsort algorithm (Quicksort)
//Michael Tran, CS350, 1/30

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define max 100

int a[max];

//finds the correct location of the pivot value by partitioning the array
int partition(int pivot, int right)
{
	int left = pivot+1;
	int temp;

	do
	{
		while(left < right && a[pivot] >= a[left])
			++left;
	
		while(left <= right && a[pivot] < a[right])
			--right;

		//Swapping values of left and right
		if(left < right)
		{
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;
		}

	}while(left < right);

	//checking which index should be swapped with the pivot
	if(a[right] < a[pivot])
	{
		temp = a[pivot];
		a[pivot] = a[right];
		a[right] = temp;
		return right;
	}
	else
		return (left + right)/2;

}

//recursive section of the algorithm
void partitionsort(int pivot, int right)
{
	int piv_new_index;

	if(pivot >= right)
		return;

	if(pivot < right)
	{
		//partition will find the correct index for the current pivot and will return the value for piv_new_index to catch
		piv_new_index = partition(pivot, right);

		//recursion starts, halfs are broken up from the left and right of new pivot index
		partitionsort(pivot, piv_new_index - 1);
		partitionsort(piv_new_index + 1, right);
	}

}

int main()
{
	int i;
	int n;

	//Reading in numbers for array
	printf("Please first enter in the total amount of numbers, and then each number in afterwards: \n");

	scanf("%d",&n);

	for(i = 0; i < n; ++i)
		scanf("%d", &a[i]);

	//EDIT: quicksort alogorithm
	partitionsort(0, n-1);

	//outputting sorted array
	printf("Here is your list in sorted order: ");

	for(i = 0; i < n; ++i)
		printf("%d ", a[i]);

	printf("\n");

	return 0;
}
