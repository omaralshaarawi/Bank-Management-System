#include"structs.h"
#include<stdio.h>
#include<string.h>
#include"save.c"
#include<ctype.h>
#include<time.h>
void add_account(){
    customer m;
    int i=0,flag=1,k;
    while(1){
    flag=1,i=0;
    printf("enter the account number : ");
    scanf("%lld",&m.account_number);
    for(i=0;i<=n;++i){
        if(m.account_number==customers[i].account_number){
            printf("the account number is duplicated please try other account number\n");
            flag=0;
            break;
        }
    }
    if(flag)
        break;
    }
    i=0;
    while (1)
    {
        flag=1;
        printf("enter your name: ");
        getchar();
        gets(m.name);
        while (m.name[i]!='\0'){
            if(!isalpha(m.name[i])&&m.name[i]!=' '){
                printf("it is an invalid name please try again %c%d\n",m.name[i],i);
                flag=0;
            }
            ++i;
        }
        if(flag)
        break;    
    }
    while (1)
    {   
        flag=1;
        i=0;
        printf("enter your E-mail: ");
        gets(m.email);
        int atpos=-1,counter=0;
        while (m.email[i]){
            if(m.email[i]==' '||counter==2||atpos==0){
                flag=0;
                printf("hey %d",i);
                break;
            }
            if(m.email[i]=='@'){
                ++counter;
                atpos=i;
            }
            if(m.email[i]=='.'&&m.email[i+1]=='c'&&m.email[i+2]=='o'&&m.email[i+3]=='m')
                flag=1;

            ++i;
        }
        if(flag!=1)
            printf("Invalid E-mail please enter a valid email\n");
        else 
            break;
    }
    while (1)
    {
        printf("enter your balance: ");
        if(scanf("%f",&m.balance)!=1)
            printf("Invalid balance please try again\n");
        else
            break;
    }
    while (1)
    {
        printf("enter you mobile: ");
        scanf("%s",m.mobile_number);
        i=0;
        while (m.mobile_number[i]){
           if(!isdigit(m.mobile_number[i])||strlen(m.mobile_number)>11){
                printf("Invaild mobile number please try again:\n");
                break;
            }
            ++i;
        }
        if(i==11)
            break;
        
    }
    time_t t = time(NULL);         // Get the current time in seconds since the Unix epoch
    struct tm *currentTime = localtime(&t); // Convert to local time components
    m.open.month=currentTime->tm_mon + 1;
    m.open.month=currentTime->tm_year+1900;
    strcpy(m.active,"active");
    printf("Are you sure you want to save:\n1-save\n2-cancel");
    while (1)
    {
        printf("\nenter you choice: ");
        scanf("%d",&i);
        if(i==1){
            save(m,1);
            break;
        }
        else if (i==2)
            return;
        else
            printf("Wrong choice please try again");
    }
}