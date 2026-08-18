#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
	int x, y, z, i;
	char choose[20];
	
	printf("Choose (Ascending/Descending): ");
	scanf(" %s", choose);
	
	if(strcmp(choose, "Ascending") == 0 || strcmp(choose, "ascending") == 0){
		printf("\n\nEnter a starting number and limit (1-100): ");
		scanf("%d %d", &x, &y);
		
		for(z=x; z<=y; z++){
			printf("\n%d", z);
			sleep(1);
		}
	}
	else if(strcmp(choose, "Descending") == 0 || strcmp(choose, "descending") == 0){
		printf("Enter a starting number and limit (1-100): ");
		scanf("%d %d", &x, &y);
		
		for(z=x; z>=y; z--){
			printf("\n%d", z);
			sleep(1);
		}	
	}
	else{
		printf("\n\nINVALID CHOICE!");
	}
	return 0;
}
