// Phone Number Management Program
#include<stdio.h>
#include<string.h>

typedef struct member{
	char* name;
	char* phone;
	char* memo;
}PhoneBook;

int count = 0;
//A function that takes over data from a file and puts it into a structure
int FileOpen(PhoneBook* m)
{
	char buffer[100];

	FILE* fp = fopen("data.txt","r");
	if (fp == NULL){
		printf("File open error");
		fclose(fp);
		return 0;
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
	return 0;
}
 
// If only 'Enter' is entered, print the manual.
void manual()
{
	printf("Manual\n");
	printf("$tel -a data : add data in txt file.\n");
	printf("$tel -d data : delete data in text file.\n");
	printf("$tel -l : Output all list Alphabetic order \n");
	printf("$tel data : find data in the text file.\n");
}

// A function that add data in struct and also entered in the file
void AddData(PhoneBook* m, char* buffer[])
{
	char answer;
	printf("%s, %s, %s\n",buffer[0],buffer[1],buffer[2]);
	printf("add? [Y/N]: ");
	scanf("%c",&answer);
	if (answer == 'Y' || answer == 'y'){
		m[count].name = buffer[0];
		m[count].phone = buffer[1];
		m[count].memo = buffer[2];
		count++;
	}
	FILE* fp = fopen("data.txt","w");
	for(int j = 0; j < count; j++){
		fprintf(fp,"%s:%s:%s",m[j].name,m[j].phone,m[j].memo);
		if (j>=count-1)
			fprintf(fp,"\n");
	}
	fclose(fp);
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
}
// A function that print struct
void StructPrint(PhoneBook* m)
{
	int num=1;
	for(int i = 0; i < count; i++){
		printf("%d %s %s %s \n",num,m[i].name,m[i].phone,m[i].memo);
		num++;
	}

}

// A function that Finds and prints the words you type
void Search(PhoneBook* m,char* data)
{
	int mnum=0;
	int num=1;
	for (int i = 0; i < count; i++){
		if (strstr(m[i].name,data) || strstr(m[i].phone,data) || strstr(m[i].memo,data)){
			printf("%d. %s %s %s\n",num,m[i].name,m[i].phone,m[i].memo);
			num++;
			mnum = 1;	
		}
	}
	if (mnum == 0)
		printf("no match found.\n");
	else
		printf("match found.\n");
}

// A function that deletes a user-entered word
void Delete(PhoneBook* m,char* data)
{
	int arr[count];
	int mnum=0;
	int num=1;
	int temp;
	int temp2;
	for (int i = 0; i < count; i++){
		if (strstr(m[i].name,data) || strstr(m[i].phone,data) || strstr(m[i].memo,data)){
			printf("%d. %s %s %s\n",num,m[i].name,m[i].phone,m[i].memo);
			arr[num]=i;
			num++;
			mnum = 1;	
		}
	}

	if (mnum == 0)
		printf("no match found.\n");
	printf("which one? ");
	scanf("%d",&temp);
	arr[temp];
	temp2=arr[temp];
	for (;temp2 <= count;temp2++)
		m[temp2]=m[temp2+1];
	m[count].name=NULL;
	m[count].phone=NULL;
	m[count].memo=NULL;
	count--;
	

	FILE* fp = fopen("data.txt","w");
	for(int j = 0; j < count; j++){
		fprintf(fp,"%s:%s:%s",m[j].name,m[j].phone,m[j].memo);
	}	
}
int main(int argc, char* argv[])
{
	PhoneBook m[200];
	FileOpen(m);
	char c;
	int i = 0;
	char* buffer[100];
	char* temp;
	if (argc == 1)
		manual();
	else if (--argc > 0 && (*++argv)[0] == '-'){
		if(c = *++argv[0]){
			switch (c) {
				case 'a':
					while(*++argv != NULL){
						buffer[i]=*argv;
						i++;
					}
						AddData(m,buffer);
					break;
				case 'd':
					temp = argv[1];
					Delete(m,temp);
					break;
				case 'l':
					mysort(m,count);
					StructPrint(m);
					break;
				default:
					printf("Invalid option entered.");
			}
		}
	}
	else{
		temp=argv[0];
		Search(m,temp);
	}
	return 0;
}
