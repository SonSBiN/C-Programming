//A program that changes lines for each spacing when a sentence is entered.
#include<stdio.h>

int main(void)
{
	int count=0;		//count is variable that counts the number of spacing
	char c;			//c is a variable to which the word should be entered.
	printf("Input some characters, then press Ctrl+D.\n"); //An announcement message.
	while ((c=getchar())!=EOF){	//Reading characters untill Ctrl D is pressed.
		if (count!=0 && c!=' '){	//case 1: It's already spacing and next time c get a text
			count=0;
			printf("%c",c);
		}
		else if (count!=0 && c==' '){	//case 2: It's already spacing. so skip next space
			
		}
		else if (count==0 && c!=' '){	//case 3: When a character is entered without a space infront of it
			printf("%c",c);
		}
		else if (count==0 && c==' '){	//case 4: Text was entered earlier, and spacing is entered
			printf("\n");
			count++;
		}
	}
	return 0;
}
