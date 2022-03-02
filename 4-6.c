// Quick sort program
#include<stdio.h>

void myqsort(double v[], int left, int right)
{
	int i, last;
	void myswap(double v[], int i, int j);	

	if (left >= right){
		return;
	}
//The value in the middle of the array determines the pivot and replaces the pivot with the first number
	myswap (v, left, (left + right)/2);
	last = left;
//Each number is compared to the pivot and the number larger than the pivot is moved backward
	for (i = left+1; i <= right; i++){
		if(v[i] < v[left]){
			myswap(v, ++last, i);
		}
	}
//The interval between the first number and the pivot is reduced and continued
	myswap(v, left, last);
	myqsort(v, left, last-1);
	myqsort(v, last+1, right);
}

void myswap(double v[], int i, int j)
{
	double temp;
// Use the parameter temp to change the two values of the array
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

#define ELEMENTS 10

int main(void)
{
	double array[] = {1.1, 9.9, 2.2, 8.8, 3.3, 7.7, 4.4, 6.6, 5.5, 0.0};

	printf("array[] \n");
// sizeof(array) is 80 because array is double-type array and number of array is 10. Therefore, it is divided into sizeof(double) so that repeating statements are excuted by the number of arrays.
	for (int i=0; i<sizeof(array)/sizeof(double); i++)
		printf("%0.1f ",array[i]);
	printf("\n");
	
	myqsort(array, 0, 9);

	printf("array[] after qsort() \n");	
	for (int i=0; i<sizeof(array)/sizeof(double); i++)
		printf("%0.1f ",array[i]);
	printf("\n");
	return 0;
}
