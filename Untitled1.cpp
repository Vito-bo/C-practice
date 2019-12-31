#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int Partion(int a[], int low, int high)
{
	int pivot = a[low];
	while (low < high)
	{
		while (low < high && a[high] >= pivot)
		{
			high--;
		}
		if (low < high)
		{
	    	a[low++] = a[high];
		}
		while (low < high && a[low] < pivot)
		{
			low++;
		}
		if (low < high)
		{
			a[high--] = a[low];
		}
	}
	return low;
}
void QuickSort(int a[], int low, int high)
{
	int mid;
	while (low < high)
	{
		mid = Partion(a, low, high);
		QuickSort(a, low, mid - 1);
		QuickSort(a, mid + 1, high);
	}
}
int main()
{
	int a[5];
	int i;
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &a[i]);
	}
	QuickSort(a, 0, 4);
	for (i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
