#include<stdio.h>
#include<stdlib.h>

struct ContactDetail
{
	char name[50];
	char phonenumber[50];
}Contact;

int read()
{
	int i;
	FILE *f;
	f = fopen("data.txt","r");
	if(f == NULL)
	{
		system("cls");
		printf("No Contacts Available");
		getch();
		return -1;
	}
	system("cls");
	printf("NAME");
	printf("\tPHONE NUMBER\n");
	for(i=0;i<35;i++)
		printf("=");
	while(fread(&Contact,sizeof(Contact),1,f)==1)
	{
		printf("\n%s\t%s",Contact.name,Contact.phonenumber);
	}
	puts("");
	for(i=0;i<35;i++)
		printf("=");	
	fclose(f);
	getch();
	system("cls");
}

int write()
{
	char test;
	FILE *f;
	f = fopen("data.txt","a+");
	if(f==NULL)
	{
		f=fopen("data.txt","w+");
	}
	while(1)
	{
		printf("\n Enter Contact Details:");
		printf("\n==========================\n");
		printf("Enter Name:\n");
		scanf("%s",Contact.name);
		fflush(stdin);
		printf("Enter Phonenumber:\n");
		scanf("%s",Contact.phonenumber);
		fwrite(&Contact,sizeof(Contact),1,f);
		fflush(stdin);
		printf("\n\nContact is successfully added!");
		printf("\n Press esc key to exit,  any other key to add another contact:");
		test=getche();
		if(test==27)
			break;		
	}
	fclose(f);
}

int find()
{
	
}

int main ()
{
	
	char state;
	
	printf("What do you want to do? (Read : r, Write: w,Find: f)\n");
	scanf("%c", &state);
	//printf("Your state is : %c",state);
	
	switch(state)
	{
		case 'r':
			system("cls");
			//printf("Your state is Read");
			read();
			break;
		case 'w':
			system("cls");
			//printf("Your state is Write");
			write();
			break;
		case 'f':
			system("cls");
			printf("Your state is Find");
			break;
		default:
			system("cls");
			printf("Invalid input");
			break;
	}

}

