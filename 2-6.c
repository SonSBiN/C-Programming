//A program that converts hexadecimal numbers into decimal numbers
#include<stdio.h>
#include<string.h>	//Header file for measuring string length
int htoi(char s[])
{
	int i;	
	int n=0;	
	int hexa;
	for(i=0;i<strlen(s);i++){
		if(s[i] >= '0' && s[i] <= '9'){	//Since s is character. subtract it  using  the  ASCII CODE and use the integer value.
			hexa=s[i]-'0';
			n=16*n+hexa;	
		}
		if(s[i] >= 'A' && s[i] <= 'F'){
			hexa=s[i]-'A'+10;	//0<=s[i]-'A'<=6, but 10<=s[i]<=16. so s[i]-'A'+10
			n=16*n+hexa;
		}
		if(s[i] >= 'a' && s[i] <= 'f'){
			hexa=s[i]-'a'+10;	
			n=16*n+hexa;
		}

	}
	return n;
}

int main(void)
{
	char h[]="12AF";

	printf("%s\n",h);		//h:char
	printf("%x\n", htoi(h));	//It's shown as h, but it's an integer type.
	printf("%d\n", htoi(h));	//hexadecimal to decimal
	return 0;
}
