// Programs that sort dictionary or number size by option '-n'
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//Declare functions and sizes to be used

#define MAXLEN 1000
#define MAXLINES 5000
#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int numcmp(char *, char*);
char *alloc(int);
int mygetline(char *, int);
void myqsort(char *lineptr[], int left, int right, int (*comp)(void *, void*));

char *lineptr[MAXLINES];

// A function that replaces the i'th and j th indices in char*v[]
void myswap(char *v[], int i, int j)
{
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

// A Sort function using recursive functions
void myqsort(char *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;
	void swap(char *v[], int i, int j);
	if (left >= right)
		return;
	myswap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++){
		if ((*comp)(v[i], v[left]) <0){
			myswap(v, ++last, i);
		}
	}
	myswap(v, left, last);
	myqsort(v, left, last-1, comp);
	myqsort(v, last+1, right, comp);
}

// A function that reads one line at a time.
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while ((len = mygetline(line, MAXLEN)) > 0 ){
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len -1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

// A function that outputs in *lineptr[]
void writelines(char *lineptr[], int nlines)
{
	int i;

	for ( i = 0; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

//Functions that compare the size of numbers
int numcmp(char *s1, char *s2)
{
	double v1, v2;

// Received it as char, so changed it to float type through atof
	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

char *alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n){
		allocp += n;
		return allocp - n;
	}
	else
		return 0;
}

void afree(char *p)
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}

// A function that stores that is entered from the user
int mygetline(char *s, int lim)
{
	int c;
	char *t = s;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n'){
		*t++ = c;
		}
	if (c == '\n')
		*t++ =c;
	*t = '\0';
	return t - s;


}

//Receive options through argv
int main(int argc, char *argv[])
{
	int nlines;
// numeric, a role that allows -n to be sorted by the size of numbers
	int numeric = 0;
	int c = 0;
	if ( --argc > 0 && (*++argv)[0] == '-'){
		if (*++argv[0] == 'n'){
			numeric = 1;
		}
	}
	if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
		myqsort(lineptr, 0, nlines-1,(int (*)(void*, void*))(numeric ? numcmp : strcmp));
		printf("\nAfter sort. \n");
		writelines(lineptr, nlines);
		return 0;
	}
	else{
		printf("input too big to sort\n");
		return 1;
	}
}
