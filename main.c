#include <stdio.h>
#include<stdlib.h>


int main (){
	
	char state;
	
	printf("What do you want to do? (Read : r, Write: w,Find: f)\n");
	scanf("%c", &state);
	//printf("Your state is : %c",state);
	
	if( state == 'r' ){
		printf("Your state is Read");
	}else if( state == 'w' ){
		printf("Your state is Write");
	}else if(state == 'f' ){
		printf("Your state is Find");
	}else{
		printf("İnvalid input");
	}

}

