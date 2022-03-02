//Indicates the signed and unsigned values for each data type
#include<stdio.h>
#include<limits.h>	//To represent the minimun value of an integer in the source code, must use the limit.h hear file

#define UNSIGNED_MIN 0	//Since unsigned is an integer value greater than or equal to zero, so the minimum value of unsigned is defined as zero.
int main(void)
{
	printf("Signed Char Min = %d			 Signed Char Max = %d\n",CHAR_MIN,CHAR_MAX);	
	printf("Signed Short Min = %d		 Signed Short Max = %d\n",SHRT_MIN,SHRT_MAX);
	printf("Signed Int Min = %d		 Signed Int Max = %d\n",INT_MIN,INT_MAX);
	printf("Signed Long Min = %ld	 Signed Long Max = %ld\n",LONG_MIN,LONG_MAX);	
	// Output char, short, int as %d and long as %ld
	printf("Unsigned Char Min = %d			 Unsigned Char Max = %u\n",UNSIGNED_MIN,UCHAR_MAX);	
	printf("Unsigned Short Min = %d			 Unsigned Short Max = %u\n",UNSIGNED_MIN,USHRT_MAX);
	printf("Unsigned Int Min = %d			 Unsigned Int Max = %u\n",UNSIGNED_MIN,UINT_MAX);
	printf("Unsigned Long Min = %d			 Unsigned Long Max = %lu\n",UNSIGNED_MIN,ULONG_MAX);
	// Output unsigned char, short int as %u and long as %lu
	return 0;
}
