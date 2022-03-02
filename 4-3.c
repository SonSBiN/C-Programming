//A program that creates a random number using srand() and time()
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//stdlib.h and time.h headers are required to use srand() and time()

int main(void)
{
	srand(time(NULL));
// Set the seed of rand() function to time(NULL) so that the seed value of the rand() function changes over time.
	for(int i = 0; i < 4; i++){
		printf("%3d", rand() % 10);
	}
	printf("\n");

	return 0;
}
