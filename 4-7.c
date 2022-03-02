// Quick sort program
#include<stdio.h>
#include<string.h>

#define ELEMENTS 7
#define NAMELEN 10

void myqsort(char v[][NAMELEN], int left, int right)
{
	int i, last;	
// Declaration to use myswap function
	void myswap(char v[][NAMELEN], int i, int j);

	if (left >= right){
		return;
	}
	myswap (v, left, (left + right)/2);
	last = left;
//For statement that replace ++last and i when v[left] is larger than v[i] through the strcmp function
	for (i = left+1; i <= right; i++){
		if(strcmp(v[i],v[left]) < 0){
			myswap(v, ++last, i);
		}
	}
// The differnece between the pivot value and the left is reduced through recursive calls.
	myswap(v, left, last);
	myqsort(v, left, last-1);
	myqsort(v, last+1, right);
}

//Swap function that replaces v[i] and v[j]
void myswap(char v[][NAMELEN], int i, int j)
{
	char temp[NAMELEN];

	strncpy(temp, v[i], NAMELEN);
	strncpy(v[i], v[j], NAMELEN);
	strncpy(v[j], temp, NAMELEN);
}


int main(void)
{
	char array[ELEMENTS][NAMELEN] = {"kim", "lee", "park", "choi", "jung", "kang", "cho"};
// It is two-dimensional array and should be printed as %s.
	printf("array[] \n");
	for (int i=0; i < ELEMENTS; i++)
		printf("%s ",array[i]);
	printf("\n");
	
	myqsort(array, 0, 6);

	printf("array[] after qsort() \n");	
	for (int i=0; i < ELEMENTS; i++)
		printf("%s ",array[i]);
	printf("\n");
	return 0;
}
