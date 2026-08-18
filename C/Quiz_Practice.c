#include <stdio.h>

int main(){
	int age;
	char name[20];
	
	printf("Enter your name: ");
	scanf("%s",name);
	
	printf("Enter your age: ");
	scanf("%d",&age);
	
	printf("Hello, %s! You are %d years old.", name, age);
	
	return 0;
	
}

