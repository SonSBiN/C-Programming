// Phone Number Management Program
#include<stdio.h>
#include<string.h>
#include<ncurses.h>

typedef struct member{
	char* name;
	char* phone;
	char* memo;
}PhoneBook;


// count = the number of struct member
int count = 0;

//A function that takes over data from a file and puts it into a structure
void FileOpen(PhoneBook* m)
{
	char buffer[100];

	FILE* fp = fopen("data.txt","r");
	if (fp == NULL){
		printw("\tFile open error");
		border('|','|','_','_',' ',' ',' ',' ');
		fclose(fp);
		return;
	}
	while(fgets(buffer,100,fp) != NULL){
		char* ptr = strtok(buffer,":");

		m[count].name = strdup(ptr);
		ptr = strtok(NULL,":");
		m[count].phone = strdup(ptr);
		ptr = strtok(NULL,":");
		m[count].memo = strdup(ptr);
		count++;
	}
	fclose(fp);
}

// A function that add data in struct and also entered in the file
int AddData(PhoneBook* m, char* buffer1, char* buffer2, char* buffer3)
{
	char answer;
	int i = 0;
	char s[strlen(buffer3)+1];
	while(*buffer3 != '\0'){
		s[i++]=*buffer3++;
	}
	s[i]='\n';
	s[i+1]='\0';
	strcpy(buffer3,s);

	printw("\t%s %s %s\n\n",buffer1,buffer2,buffer3);
	printw("\tadd? [Y/N]: ");
	border('|','|','_','_',' ',' ',' ',' ');
	scanw("%c",&answer);
	if (answer == 'Y' || answer == 'y'){
		m[count].name = buffer1;
		m[count].phone = buffer2;
		m[count].memo = buffer3;
		count++;
	
		FILE* fp = fopen("data.txt","w");
		for(int j = 0; j < count; j++){
			fprintf(fp,"%s:%s:%s",m[j].name,m[j].phone,m[j].memo);
			if (j == count-1)
				fprintf(fp,"\n");
		}
		fclose(fp);
		return 1;
	}
	else
		return 0;

}
// A function that sort struct
void mysort(PhoneBook* m, int count)
{
	PhoneBook temp;

	for (int i = 0; i < count-1; i++){
		for (int j = 0; j < count-i-1; j++){
			if (strcmp(m[j].name, m[j+1].name) > 0){
				temp = m[j];
				m[j] = m[j+1];
				m[j+1] = temp;
			}
		}
	}
	FILE* fp = fopen("data.txt","w");
	for(int k = 0; k < count; k++){
		fprintf(fp, "%s:%s:%s",m[k].name,m[k].phone,m[k].memo);
	}
	fclose(fp);

}
// A function that print struct
void StructPrint(PhoneBook* m)
{
	int num=1;

	printw("\t_______________________________________________\n\n\n");
	for(int i = 0; i < count; i++){
		printw("\t%d %s %s %s\n",num,m[i].name,m[i].phone,m[i].memo);
		num++;
	}
	printw("\t_______________________________________________\n\n");
	border('|','|','_','_',' ',' ',' ',' ');

}

// A function that Finds and prints the words you type
void Search(PhoneBook* m,char* data)
{
	int mnum=0;
	int num=1;
	printw("\n");
	for (int i = 0; i < count; i++){
		if (strstr(m[i].name,data) || strstr(m[i].phone,data) || strstr(m[i].memo,data)){
			printw("\t%d. %s %s %s\n",num,m[i].name,m[i].phone,m[i].memo);
			num++;
			mnum = 1;	
		}
	}
	border('|','|','_','_',' ',' ',' ',' ');
	if (mnum == 0){
		printw("\tno match found.\n");
		border('|','|','_','_',' ',' ',' ',' ');
	}
	else{
		printw("\tmatch found.\n");
		border('|','|','_','_',' ',' ',' ',' ');
	}
}

// A function that deletes a user-entered word
int Delete(PhoneBook* m,char* data)
{
	int arr[count];
	int mnum=0;
	int num=1;
	int temp;
	int temp2;
	char answer;

	printw("\n\n");
	for (int i = 0; i < count; i++){
		if (strstr(m[i].name,data) || strstr(m[i].phone,data) || strstr(m[i].memo,data)){
			printw("\t%d. %s %s %s\n\n",num,m[i].name,m[i].phone,m[i].memo);
			border('|','|','_','_',' ',' ',' ',' ');
			arr[num]=i;
			num++;
			mnum = 1;	
		}
	}

	if (mnum == 0){
		printw("\tno match found.\n");
		border('|','|','_','_',' ',' ',' ',' ');
	}
	else {
		printw("\twhich one? ");
		border('|','|','_','_',' ',' ',' ',' ');
		scanw("%d",&temp);
		border('|','|','_','_',' ',' ',' ',' ');
		printw("\n\n");
		if (temp < 1 || temp >= num){
			attron(A_BOLD);
			printw("\n\tYou Entered wrong number\n");
			border('|','|','_','_',' ',' ',' ',' ');
			return 0;
		}
		printw("\t%s %s %s\n",m[arr[temp]].name,m[arr[temp]].phone,m[arr[temp]].memo);
		printw("\tDelete? [Y/N]: ");
		border('|','|','_','_',' ',' ',' ',' ');
		scanw("%c", &answer);
		if (answer == 'Y' || answer == 'y'){
			temp2=arr[temp];
			for (;temp2 <= count;temp2++){
				m[temp2]=m[temp2+1];
			}
			m[count].name=NULL;
			m[count].phone=NULL;
			m[count].memo=NULL;
			count--;
			FILE* fp = fopen("data.txt","w");
			for(int j = 0; j < count; j++){
				fprintf(fp,"%s:%s:%s",m[j].name,m[j].phone,m[j].memo);
			}
			fclose(fp);	
			return 1;
		}	
		else {
			return 0;
		}
	}
}
// A function that update a user-entered word
int Update(PhoneBook* m, int inum,char*buffer1,char*buffer2,char*buffer3)
{

	int i = 0;
	char s[strlen(buffer3)+1];
	while(*buffer3 != '\0'){
		s[i++]=*buffer3++;
	}
	s[i]='\n';
	s[i+1]='\0';
	strcpy(buffer3,s);

	int num=inum-1;
	m[num].name=buffer1;
	m[num].phone=buffer2;
	m[num].memo=buffer3;
	FILE* fp = fopen("data.txt","w");
	for(int j = 0; j< count; j++){
		fprintf(fp,"%s:%s:%s",m[j].name,m[j].phone,m[j].memo);
		if (j == inum-1)
			fprintf(fp,"\n");	
	}
	fclose(fp);
}

int main(void)
{
	PhoneBook m[200];
	FileOpen(m);

	char c;
	int i = 0;
	int enter;
	char buffer1[100];
	char buffer2[100];
	char buffer3[100];
	char temp[30];
	int answer;
	int row,col;
	char firstmessage[]="Phone Number Management Program";
	char lastmessage[]="Program End";
	char check;
	char exit;
	while(1){
		if (exit == 'Y' || exit == 'y')
			break;
		initscr();
		clear();
		
		start_color();
		init_pair(1,COLOR_WHITE,COLOR_BLACK);
		getmaxyx(stdscr,row,col);

		attron(A_BOLD);
		mvprintw(row/16,(col-strlen(firstmessage))/2,"%s\n\n\n",firstmessage);
		attroff(A_BOLD);

		printw("\tFunctions:\n\n");
		printw("\t1. Search\n");
		printw("\t2. Add\n");
		printw("\t3. Delete\n");
		printw("\t4. Update\n");
		printw("\t5. List\n");
		printw("\t6. Exit\n\n");
		
		printw("\tEnter the number of the function: ");
		border('|','|','_','_',' ',' ',' ',' ');
		refresh();
		//enter = getch();
		//getch();	
		scanw("%d",&enter);
		switch (enter) {
			case 1:	//Search
				clear();
				mvprintw(2,(col-30)/2,"You choose function 1 (search)\n\n");
				printw("\tSearch:");
				border('|','|','_','_',' ',' ',' ',' ');
				scanw("%s",&temp);
				printw("\n");
				border('|','|','_','_',' ',' ',' ',' ');
				Search(m,temp);
				refresh();
				break;			
			case 2:	//Add
				clear();
				mvprintw(2,(col-27)/2,"You choose function 2 (add)\n|\n");
				printw("\tAdd:");
				border('|','|','_','_',' ',' ',' ',' ');
				scanw("%s %s %s",&buffer1,&buffer2,&buffer3);
				printw("\n");
				border('|','|','_','_',' ',' ',' ',' ');
				if (AddData(m,buffer1,buffer2,buffer3)){
					attron(A_BLINK);
					mvprintw((row/8)*7,(col-16)/2,"Add data success\n");
				}
				refresh();
				break;
		
			case 3:	//Delete
				clear();
				mvprintw(2,(col-30)/2,"You choose function 3 (delete)\n|\n");
				printw("\tDelete: ");
				border('|','|','_','_',' ',' ',' ',' ');
				scanw("%s",&temp);
				if(Delete(m,temp)){
					attron(A_BLINK);
					mvprintw((row/8)*7,(col-19)/2,"Delete data success\n");
				}
		
				refresh();
				break;
		
			case 4:	//Update
				clear();
				mvprintw(2,(col-30)/2,"You choose function 4 (update)\n\n");
				printw("\n");
				StructPrint(m);
				printw("\twhich one?: ");
				border('|','|','_','_',' ',' ',' ',' ');
				scanw("%d",&answer);
				if (answer<1 || answer>count){
					attron(A_BOLD);
					printw("\n\tYou entered wrong number");
					border('|','|','_','_',' ',' ',' ',' ');
					break;
				}
				printw("\n\tHow?: ");
				border('|','|','_','_',' ',' ',' ',' ');
				scanw("%s %s %s",&buffer1,&buffer2,&buffer3);
				printw("\n");
				printw("\t%s %s %s\n\n",buffer1,buffer2,buffer3);
				printw("\tUpdate?[Y/N]:");
				border('|','|','_','_',' ',' ',' ',' ');
				scanw("%c",&check);
				if(check == 'Y' || check == 'y'){
					if(Update(m,answer,buffer1,buffer2,buffer3)){
						attron(A_BLINK);
						mvprintw((row/8)*7,(col-19)/2,"Update data success\n");
					}
				}
				else{
					attron(A_BOLD);
					mvprintw((row/8)*7,(col-29)/2,"The update has been canceled.\n");
				}
				refresh();
				break;
		
			case 5:	//List
				clear();
				mvprintw(2,(col-28)/2,"You choose function 5 (list)\n\n\n");
				mysort(m,count);
				StructPrint(m);	
				border('|','|','_','_',' ',' ',' ',' ');
				refresh();
				break;
			case 6:	//Exit
				printw("\n");
				border('|','|','_','_',' ',' ',' ',' ');
				break;
			default :
				attron(A_BOLD);
				mvprintw(row*6/8,(col-16)/2,"Invalid function");	
				border('|','|','_','_',' ',' ',' ',' ');
		}
		attroff(A_BLINK);
		mvprintw(row-3,0,"\tEXIT? [Y/N]:");
		attron(A_BOLD);
		border('|','|','_','_',' ',' ',' ',' ');
		scanw("%c",&exit);
	}
	clear();
	border('|','|','_','_',' ',' ',' ',' ');
	attron(A_BLINK);
	attron(A_BOLD);
	mvprintw(row/8,(col-strlen(lastmessage))/2,"%s",lastmessage);
	getch();
	endwin();

	return 0;
}
