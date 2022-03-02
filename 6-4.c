// A program that uses a binary tree to print words and counts in alphabetical order.
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

#define MAXWORD 100

// Make tree node
struct tnode {
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

int main(void)
{

	struct tnode *addtree(struct tnode *, char*);
	void treeprint(struct tnode *);
	int getword(char *, int);

	struct tnode *root;
	char word[MAXWORD];

	root = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);
	treeprint(root);

	return 0;
}

// A function that when a new word comes in, it creates new node and links them to trees in alphabetical order.
struct tnode *addtree(struct tnode *p, char *w)
{
	struct tnode *talloc(void);
	char *mydup(char *);

	int cond;

	if (p == NULL){
		p = talloc();
		p->word = mydup(w);
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

// Make a space for node
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

// Copy the new word
char *mydup(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s)+1);
	if (p != NULL)
		strcpy(p,s);
	return p;
}
//print trees by in-order
void treeprint(struct tnode *p)
{
	if (p != NULL){
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF){
		*w++ = c;
	}
	if (!isalpha(c)){
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())){
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}
	
#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int value = EOF;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
