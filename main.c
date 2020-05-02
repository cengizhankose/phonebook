#include<stdio.h>
#include<stdlib.h>
#include <conio.h>


struct ContactDetail
{
	char name[50];
	char phonenumber[50];
}Contact;

void read()
{
	int i;
	FILE *f;
	f = fopen("data.txt","r");
	if(f == NULL)
	{
		system("cls");
		printf("No Contacts Available");
		getch();
		exit(0);
	}
	system("cls");
	printf("NAME");
	printf("\tPHONE NUMBER\n");
	for(i=0;i<35;i++)
		printf("=");
	while(!feof(f))
	{
		fscanf(f,"%s\t%s\n",&Contact.name,&Contact.phonenumber);
		printf("\n%s\t%s",Contact.name,Contact.phonenumber);
	}	
	puts("");
	for(i=0;i<35;i++)
		printf("=");	
	fclose(f);
	printf("\nPress any key to exit");
	getch();
	//system("cls");
}

void write()
{
	FILE *f;
	f = fopen("data.txt","a+");
	if(f==NULL)
	{
		f=fopen("data.txt","w+");
	}
	while(1)
	{
		printf("Enter Contact Details:");
		printf("\n==========================\n");
		printf("Enter Name:\n");
		scanf("%s",Contact.name);
		fflush(stdin);
		printf("Enter Phonenumber:\n");
		scanf("%s",Contact.phonenumber);
		fprintf(f,"%s\t%s\n",Contact.name,Contact.phonenumber);
		fflush(stdin);
		printf("\n\nContact is successfully added!");
		printf("\n Press any key to exit");
		getch();
		break;		
	}
	fclose(f);
}

void find()
{
	char nameToSearch[40];
	FILE *f;
	f = fopen("data.txt","r");
	if(f == NULL)
	{
		system("cls");
		printf("No Contacts Available");
		getch();
		exit(0);
	}
	printf("Enter the name:\n");
	scanf("%s",nameToSearch);
	//printf("%s",nameToSearch);
	searchName(nameToSearch);
	printf("\nPress any key to exit");
	getch();
}

void searchName(char nameToSearch[])
{
	char line[401];
	FILE *f;
	f = fopen("data.txt","r");
	while(!feof(f))
	{
		fgets(line,400,f);
		if(strstr(line,nameToSearch)!=NULL)
		printf("\n%s",line);		
	}	
}

int main ()
{
while(1){
	system("cls");
	int state,i;
	
	printf("   ******************************  |MAIN MENU|  ***************************** \n");
	for(i=0;i<80;i++)
	printf("=");
	printf("\n");
	printf("\t\t *Please enter your choice for menu*:");
	printf("\n\n");
	printf(" \n Enter 1 -> See your contact list");
	printf("\n----------------------------------");
	printf(" \n Enter 2 -> Add a new contact");
	printf("\n----------------------------------");
	printf(" \n Enter 3 -> Search a contact");
	printf("\n----------------------------------");
	printf(" \n Enter 4 -> Exit");
	printf("\n\n");
	for(i=0;i<80;i++)
	printf("=");
	printf("\n");
	
	scanf("%d", &state);
	//printf("Your state is : %c",state);
	
	switch(state)
	{
		case 1:
			system("cls");
			//printf("Your state is Read");
			read();
			break;
		case 2:
			system("cls");
			//printf("Your state is Write");
			write();
			break;
		case 3:
			system("cls");
			//printf("Your state is Find\n");
			find();
			break;
		case 4:
			system("cls");
			for(i=0;i<80;i++)
			printf("=");
			printf("\n");
			printf("   ******************************  |THANK YOU|  ***************************** \n");
			for(i=0;i<80;i++)
			printf("=");
			printf("\n");
			exit(0);
			break;
		default:
			system("cls");
			printf("Invalid input");
			break;
	}
}
}

