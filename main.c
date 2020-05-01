#include <stdio.h>
#include <stdlib.h>


int read()
{
	
}

int write()
{
	FILE *f;
	f = fopen("data.txt","a+");
	if(f==0)
	{
		f=fopen("add.txt","w+");
	}
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
			printf("Your state is Read");
			break;
		case 'w':
			system("cls");
			printf("Your state is Write");
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

