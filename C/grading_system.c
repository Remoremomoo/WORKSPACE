#include <stdio.h>

int main(){
	int studentGrade;
	
	printf("\n-----| GRADING SYSTEM |-----\n");
	printf("\nEnter score: ");
	scanf("%d",&studentGrade);
	
	if(studentGrade >= 90 && studentGrade <= 100){
		printf("\n\nGrade: A");
		printf("\n\nCLOSING TERMINAL...");
	}
	else if(studentGrade >= 80 && studentGrade <= 89){
		printf("\n\nGrade: B");
		printf("\n\nCLOSING TERMINAL...");
	}
	else if(studentGrade >= 70 && studentGrade <= 79){
		printf("\n\nGrade: C");
		printf("\n\nCLOSING TERMINAL...");
	}
	else if(studentGrade >= 60 && studentGrade <= 69){
		printf("\n\nGrade: D");
		printf("\n\nCLOSING TERMINAL...");
	}
	else if(studentGrade >= 0 && studentGrade < 60){
		printf("\n\nGrade: F");
		printf("\n\nCLOSING TERMINAL...");
	}
	else{
		printf("\n\nINVALID SCORE INPUT!!");
		printf("\n\nCLOSING TERMINAL...");
	}
	
	return 0;
}
