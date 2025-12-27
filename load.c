#include <stdio.h>
#include <string.h>
#include "structs.h"

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