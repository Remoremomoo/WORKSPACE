#include <stdio.h>

struct profile{
	char name[50];
	int age;
};
void name(){
	printf("1. Mark");
}
void print(struct profile *p){
	strcpy(p->name, "Mark");
}

int main(){
	name();
	return 0;
}
