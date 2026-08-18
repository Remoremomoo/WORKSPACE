#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <unistd.h>

int main(){
    printf("%93s", "====================================================================");//TITLE UI
    printf("\n%70s", "#ARITHMETIC PACHINKO#");
    printf("\n%93s", "====================================================================");

    printf("\n\n%72s", "Test your SKILL and LUCK!");
    printf("\n\n%79s", "Answer arithmetic questions to increase");
    printf("\n%77s", "your LUCK and hit the JACKPOT (777)");

    printf("\n\n%93s", "--------------------------------------------------------------------");

    printf("\n");
    while(!_kbhit()){
        printf("\r%50sPRESS ENTER TO START", "");
        fflush(stdout);
        sleep(1);

        printf("\r%50s                                      ", "");
        fflush(stdout);
        sleep(1);

    }
    getchar();


    return 0;
}
