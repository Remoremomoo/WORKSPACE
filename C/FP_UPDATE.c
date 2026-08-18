// Array of Baseball Players
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

// GLOBAL VARIABLES
char name[MAX][50];
int at_bats[MAX], hits[MAX];
int last = -1;   // array is initially empty

// UDFs declaration
void addRecord(char n[], int ab, int h);
void delRecord(char n[]);
void display();
int isfull();
int isempty();
void updateRecord(char n[]);
int locate(char n[]);
float batAve(int ab, int h);
int menu();
void savetoFile();
void retrievefromFile();

int main() {
    char nm[50];
    int at, hts;

    retrievefromFile();   // populate the arrays from file data

    while (1) {   // infinite loop
        switch (menu()) {

        case 1:
            printf("Input Name: ");
            getchar();
            scanf("%[^\n]", nm);

            if (locate(nm) > -1) {
                printf("Duplicate record.\n");
                system("pause");
                break;
            }

            printf("Input At bats: ");
            scanf("%d", &at);

            printf("Input hits: ");
            scanf("%d", &hts);

            addRecord(nm, at, hts);
            break;

        case 2:
            printf("Input Name: ");
            getchar();
            scanf("%[^\n]", nm);
            updateRecord(nm);
            break;

        case 3:
            printf("Input Name: ");
            getchar();
            scanf("%[^\n]", nm);
            delRecord(nm);
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Saving...\n");
            system("pause");
            savetoFile();
            exit(0);

        default:
            printf("Invalid input.\n");
            system("pause");
        }
    }

    return 0;
}

// UDF definitions

void addRecord(char n[], int ab, int h) {
    if (isfull()) {
        printf("Array is full!\n");
        system("pause");
    } else {
        last++;
        strcpy(name[last], n);
        at_bats[last] = ab;
        hits[last] = h;
    }
}

void delRecord(char n[]) {
    int p, i;

    if (isempty()) {
        printf("Nothing to delete.\n");
        system("pause");
    } else {
        p = locate(n);

        if (p == -1) {
            printf("Not found.\n");
            system("pause");
        } else {
            for (i = p; i < last; i++) {
                strcpy(name[i], name[i + 1]);
                at_bats[i] = at_bats[i + 1];
                hits[i] = hits[i + 1];
            }

            last--;
            printf("Record of %s was deleted from the array.\n", n);
            system("pause");
        }
    }
}

void display() {
    int i;
    float ba;

    system("cls");
    printf("%5s %-20s %-6s %-6s %-6s\n",
           "No.", "Name", "AtBats", "Hits", "Bat. Ave");

    for (i = 0; i <= last; i++) {
        ba = batAve(at_bats[i], hits[i]);
        printf("%5d %-20s %-6d %-6d %6.2f\n",
               i + 1, name[i], at_bats[i], hits[i], ba);
    }

    system("pause");
}

int isfull() {
    return (last == MAX - 1);
}

int isempty() {
    return (last == -1);
}

int locate(char n[]) {
    for (int i = 0; i <= last; i++) {
        if (strcmp(name[i], n) == 0)
            return i;
    }
    return -1;   // not found
}

int menu() {
    int ch;

    system("cls");
    printf("Menu\n");
    printf("1. Add Record\n");
    printf("2. Update a Record\n");
    printf("3. Delete a Record\n");
    printf("4. Display All\n");
    printf("5. Exit\n");
    printf("Select[1-4]: ");
    scanf("%d", &ch);

    return ch;
}

float batAve(int ab, int h) {
    return (float)h / ab * 100;
}

void updateRecord(char n[]) {
    int p, ch;

    if (isempty()) {
        printf("Nothing to delete.\n");
        system("pause");
    } else {
        p = locate(n);

        if (p == -1) {
            printf("Not found.\n");
            system("pause");
        } else {
            while (1) {
                system("cls");

                printf("Name: %s\n", name[p]);
                printf("At bats: %d\n", at_bats[p]);
                printf("Hits: %d\n", hits[p]);
                printf("Batting Ave: %6.2f%%\n",
                       batAve(at_bats[p], hits[p]));

                printf("Update Options:\n");
                printf("1.) At Bats\n");
                printf("2.) Hits\n");
                printf("3.) Return to main\n");
                printf("Select[1-3]: ");
                scanf("%d", &ch);

                switch (ch) {
                case 1:
                    printf("Input new At bats: ");
                    scanf("%d", &at_bats[p]);
                    break;

                case 2:
                    printf("Input new Hits: ");
                    scanf("%d", &hits[p]);
                    break;

                case 3:
                    return;

                default:
                    printf("Invalid choice.\n");
                    system("pause");
                }
            }
        }
    }
}

void savetoFile() {
    FILE *fp;
    int i;

    fp = fopen("bscs1cd26", "w");

    if (fp == NULL) {
        printf("File error.\n");
        system("pause");
    } else {
        for (i = 0; i <= last; i++) {
            fprintf(fp, "%s,%d,%d\n",
                    name[i], at_bats[i], hits[i]);
        }
        fclose(fp);
    }
}

void retrievefromFile() {
    FILE *fp;
    char line[80];
    char nm[50];
    int ab, hts;

    fp = fopen("bscs1cd26", "r");

    if (fp == NULL) {
        printf("File error.\n");
        system("pause");
    } else {
        while (fgets(line, sizeof(line), fp)) {
            sscanf(line, "%[^,],%d,%d",
                   nm, &ab, &hts);
            addRecord(nm, ab, hts);
        }
        fclose(fp);
    }
}
