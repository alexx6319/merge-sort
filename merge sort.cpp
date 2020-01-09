#include <iostream>
#include<time.h>
using namespace std;
#define MAX 5
void mergeSort(int arr[], int low, int mid, int high);
void partition(int arr[], int low, int high);

int main()
{
	srand((unsigned)time(NULL));
	int merge[MAX], i, n;


	n = MAX;

	/*merge[0] = 9;
	merge[1] = 8;
	merge[2] = 7;
	merge[3] = 6;
	merge[4] = 5;*/

	printf("Before merge sorting elements are: ");
	for (i = 0; i<n; i++)
	{
	merge[i] = rand();
	}
	for (i = 0; i<n; i++)
	{
		printf("%d ", merge[i]);
	}

	partition(merge, 0, n - 1);
	printf("\n");
	printf("After merge sorting elements are: ");
	for (i = 0; i<n; i++)
	{
		printf("%d ", merge[i]);
	}

	system("pause");
}

void partition(int arr[], int low, int high)
{
	int mid;
	if (low<high)
	{
		mid = (low + high) / 2;
		partition(arr, low, mid);
		partition(arr, mid + 1, high);
 		mergeSort(arr, low, mid, high);
	}
}

void mergeSort(int arr[], int low, int mid, int high)
{
	int templocation, leftIndex, rightIndex, k, temp[MAX];

	leftIndex = low;
	rightIndex = mid + 1;
	templocation = low;

	while ((leftIndex <= mid) && (rightIndex <= high))
	{

		if (arr[leftIndex] <= arr[rightIndex])
		{
			temp[templocation] = arr[leftIndex];
			leftIndex++;
		}
		else
		{
			temp[templocation] = arr[rightIndex];
			rightIndex++;
		}
		templocation++;
	}

	if (leftIndex>mid) 
	{
		for (k = rightIndex; k <= high; k++)
		{
			temp[templocation] = arr[k];
			templocation++;
		}
	}
	else 
	{
		for (k = leftIndex; k <= mid; k++)
		{
			temp[templocation] = arr[k];
			templocation++;
		}
	}
	for (k = low; k <= high; k++) 
	{
		arr[k] = temp[k];
	}
}
