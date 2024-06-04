#include <stdio.h>

void Swap(int *pa, int *pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

void PrintArray(int *ptr, int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", ptr[i]);
	}
	printf("\n");
}

int IsLess(int a, int b)
{
	return a < b;
}

int IsLarger(int a, int b)
{
	return a > b;
}

// Define a function pointer type, which points to a function
typedef int (*ComparatorFuncPtr)(int, int);

void BubbleSort(int *ptr, int n, ComparatorFuncPtr compare)
{
	for (int iMax = n - 2; iMax >= 0; iMax--) {
		for (int i = 0; i <= iMax; i++) {
			if (compare(ptr[i], ptr[i + 1])) {
				Swap(ptr + i, ptr + i + 1);
			}
		}
	}
}

int main(void)
{
	int arr[] = { 30, 50, 20, 10, 60, 40 };
	int len = sizeof(arr) / sizeof(arr[0]);

	// a function pointer variable which points to the function IsLarger
	ComparatorFuncPtr fptr = &IsLarger;
	printf("Before sorting:\n");
	PrintArray(arr, len);
	BubbleSort(arr, len, fptr);
	// in an ascending order
	printf("After sorting:\n");
	PrintArray(arr, len);

	// a function pointer variable which points to the function IsLess
	fptr = &IsLess;
	printf("\nBefore sorting:\n");
	PrintArray(arr, len);
	BubbleSort(arr, len, fptr);
	// in an descending order
	printf("After sorting:\n");
	PrintArray(arr, len);
	return 0;
}
