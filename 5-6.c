// Program that using echo -r option
#include<stdio.h>

int main(int argc,char *argv[])
{
	int i = 0;
// an if statement that checks for option '-r'
	if ( --argc > 0 && (*++argv)[0] == '-'){
		if (*++argv[0] == 'r'){
// If there is an '-r' option, print it upside down
			for(i = argc-1; i > 0; i--){
				printf("%s ", argv[i]);
			}
			putchar('\n');
		}
	}
// It there is no '-r' option, print it out as it is
	else{
		for(i = 0; i <argc; i++){
			printf("%s ", argv[i]);
		}
		putchar('\n');
	}

	return 0;
}
