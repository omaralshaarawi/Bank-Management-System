#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "structs.h"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define RESET   "\033[0m"
int login()
{
    char username[20];
    char password[20];

    printf("Enter username: ");
    scanf("%s", username);
    printf( "Enter password: " RESET);
    scanf("%s", password);

    FILE *fp = fopen("users.txt", "r");
    if (!fp)
    {
        perror("File open failed");
        return 0;
    }

    char word[256];

    while (fscanf(fp, "%99s", word) == 1)
    {
        if (strcmp(word, username) == 0)
        {
            fscanf(fp, "%99s", word);
            if (strcmp(word, password) == 0)
            {
                printf(GREEN "Login successful!\n" );
                fclose(fp);
                return 1;
            }
        }
        else
            fscanf(fp, "%99s", word);
    }
    printf("Login failed! Invalid username or password.\n");
    fclose(fp);
    return 0;
}


void load()
{
    FILE *fptr1;
    fptr1 = fopen("accounts.txt","r");
    if (fptr1==NULL) {
        perror("File open failed");
        return;
    }
    char line[10000];
    char *token;
    int cnt=0;
    while (fgets(line, sizeof(line), fptr1)) {
        token = strtok(line, ",");
        cnt=0;
        while (token != NULL) {
            if(cnt==0)
            {
                customers[n].account_number=atoll(token);
            }
            else if(cnt==1)
            {
                strcpy(customers[n].name,token);
            }
            else if(cnt==2)
            {
                strcpy(customers[n].email,token);
            }
            else if(cnt==3)
            {
                customers[n].balance=atof(token);
            }
            else if(cnt==4)
            {
                strcpy(customers[n].mobile_number,token);
            }
            else if(cnt==5)
            {
                char* token1;
                token1 = token;
                if(token1[1]=='-')token1[1]='\0';
                else token1[2]='\0';
                customers[n].open.month=atoi(token1);
                if(token1[1]=='\0')token1+=2;
                else token1+=3;
                customers[n].open.year=atoi(token1);
            }
            else if(cnt==6)
            {
                if(strcmp(token,"active\n")==0)token[6]='\0';
                if(strcmp(token,"inactive\n")==0)token[8]='\0';
                strcpy(customers[n].active,token);
                
            }
            cnt++;
            token = strtok(NULL, ",");
        }
    FILE *fptr;
    char acc_number[50];
    sprintf(acc_number,"%lld.txt",customers[n].account_number);
    fptr = fopen(acc_number, "a+");
    if(fptr==NULL)
    {
        perror("The account number file wasn't made");
    }
    fclose(fptr);
        n++;
    }
    n--;
}


void quit() {
    printf("Thank you for using the Bank Management System. Goodbye!\n");
    exit(0);
}