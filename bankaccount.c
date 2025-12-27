#include"structs.h"
#include<stdio.h>
#include<string.h>
#include"save.c"
#include<ctype.h>
#include<time.h>
#include<stdlib.h>
void add_account(){
    customer m;
    int i=0,flag=1,k;
    while(1){
    i=0,flag=1;
    printf("enter the account number : ");
    if(scanf("%lld",&m.account_number)!=1){               //if the user put anything other than numbers
        printf("The Account Number is Not valid please try again\n");
        while (getchar()!='\n')
        {
            continue;   //clean the buffer
        }
        continue;
    }                
    for(i=0;i<=n;++i){
        if(m.account_number==customers[i].account_number){
            printf("the Account Number is duplicated please try to enter another account number\n");
            flag=0;
            break;
        }
    }
    if(flag)
        break;
    }
    while (1)
    {
        i=0;
        flag=1;
        printf("enter your name: ");
        getchar();
        gets(m.name);
        while (m.name[i]!='\0'){
            if(!isalpha(m.name[i])&&m.name[i]!=' '){
                printf("it is an invalid name please try again\n");
                flag=0;
                break;
            }
            ++i;
        }
        if(flag)
        break;    
    }
    while (1)
    {   
        flag=0;
        i=0;
        printf("enter your E-mail: ");
        gets(m.email);
        int atpos=-1,counter=0;
        while (m.email[i]){
            if(m.email[i]==' '||counter==2||atpos==0){
                flag=0;
                break;
            }
            if(m.email[i]=='@'){
                ++counter;
                atpos=i;
            }
            if(atpos!=-1){
            if(i>atpos&&m.email[i]=='.'&&m.email[i+1]=='c'&&m.email[i+2]=='o'&&m.email[i+3]=='m')
                flag=1;
            }
            ++i;
        }
        if(flag!=1)
            printf("Invalid E-mail please enter a valid email\n");
        else 
            break;
    }
    while (1)
    {
        i=0,flag=1;
        char a[1000],*end;
        printf("enter your balance: ");
        gets(a);
        while (a[i])
        {
            if(!isdigit(a[i])&&a[i]!='.'){
            printf("Invailed Balance please try again\n");
            flag=0;
            break;
            }
            ++i;
        }
        if(flag){
            m.balance=atof(a);
            break;
        }
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
    m.open.year=currentTime->tm_year+1900;
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
int search_account(int check){     //if check=1 return index of customer if account is found 
    int i,flag,k;
    long long x;
    while (1)
    {
        flag=1;
        printf("please enter the account number: ");
        scanf("%lld",&x);
        for(i=0;i<=n;++i){
            if(x==customers[i].account_number){
                if(check==1)                //to check for another functions that customer is found
                    return i;
                flag=0;
                printf("Account Number: %lld\n",customers[i].account_number);
                printf("Name: %s\n",customers[i].name);
                printf("E-mail: %s\n",customers[i].email);
                printf("Balance: %f\n",customers[i].balance);
                printf("Mobile: %s\n",customers[i].mobile_number);
                printf("Date opened: %d-%d\n",customers[i].open.month,customers[i].open.year);
                printf("Status: %s\n",customers[i].active);
                return 0;
            }
        }
        if(check==1)
            return -1;
        if (flag)
        {
            printf("the account number is not found in the system\n");
            printf("1-enter another bank account\n2-cancel\n");
            while (1)
            {
                printf("enter your choice: ");
                scanf("%d",&k);
                if(k==1)
                    break;
                else if(k==2)
                    return 0;
                else
                    printf("Wrong choice please try again\n");
            }
        }
        
    }
}
void advanced_search(){
    int i,flag;
    char k[1000];
    while (1) 
    {
        flag=0;
        printf("please enter the keyword: ");
        getchar();
        gets(k);
        printf("Search Result: \n");
        for (i=0;i<=n;++i)
        {
            if(strstr(customers[i].name,k)){
                printf("\nAccount Number: %lld\n",customers[i].account_number);
                printf("Name: %s\n",customers[i].name);
                printf("E-mail: %s\n",customers[i].email);
                printf("Balance: %f\n",customers[i].balance);
                printf("Mobile: %s\n",customers[i].mobile_number);
                printf("Date opened: %d-%d\n",customers[i].open.month,customers[i].open.year);
                printf("Status: %s\n",customers[i].active);
                flag=1;
            }
        }
        if(!flag)
            printf("there isn't any account with tha same keyword\n1-enter another keyword\n2-cancel\n");
        else
            return;
        while (1)
        {
            printf("enter your choice : ");
            scanf("%d",&flag);
            if(flag==1)
                break;
            else if(flag==2)
                return;
            else 
                printf("Wrong choice please try again\n");
        }
    }
}
void Delete_account(int c){
    int x,i,k,flag;
    FILE *file1,*file2;
    printf("you want to confirm the changes:\n1-confirm\n2-cancel\n");
    while (1)
    {
        printf("enter your choice: ");
        scanf("%d",&flag);
        if(flag==1)
            break;
        else if (flag==2)
            return;
        else
            printf("Wrong choice please try again\n");
    }
    while(1){
    if(c==-1)
    x=search_account(1);
    else
    x=c;
    if(x>=0){
        if(c==-1){
        if(customers[i].balance!=0){
            printf("the deletion is rejected because the account contain money\n");
            return;
        }
        for(i=x;i<=n;++i){
            customers[i]=customers[i+1];
        }
        --n;
        FILE *fptr;
        char acc_number[50];
        sprintf(acc_number,"%lld.txt",customers[x].account_number);
        fptr = fopen(acc_number, "w");
        if(fptr==NULL)
        {
            perror("The account number file wasn't found");
            return;
        }
        fclose(fptr);
        printf("the deletion is done successfully\n");
        }
        file1=fopen("account.txt","w");
        for(i=0;i<=n;++i){
            fprintf(file1,"%lld,%s,%s,%f,%s,%d-%d,%s\n",customers[i].account_number,customers[i].name,customers[i].email,customers[i].balance,customers[i].mobile_number,customers[i].open.month,customers[i].open.year);
        }
    }
    else{
        printf("------the account number is not found-----\n1-enter another bank account\n2-cancel\n");
        while (1)
        {
            printf("enter your choice: ");
            scanf("%d",&k);
            if(k==1)
                break;
            else if (k==2)
                return;
            else 
                printf("Wrong choice please try again\n");
        }  
    }
    }
}
void modify_account(){
    int x,i,k,flag;
    x=search_account(1);
    if(x>=0){
        printf("\n----modifiable option----\n");
        printf("1-Name\n2-Mobile Number\n3-E-mail\n");
        while(1){
        printf("enter your choice: ");
        scanf("%d",&k);
        if(k==1){
            while (1){
                flag=1;
                i=0;
                printf("enter the New Name: ");
                getchar();
                gets(customers[x].name);
                while (customers[x].name[i]!='\0'){
                    if(!isalpha(customers[x].name[i])&&customers[x].name[i]!=' '){
                        printf("it is an invalid name please try again\n");
                        flag=0;
                        break;
                    }
                    ++i;
                }
                if(flag)
                break;
            }
            Delete_account(x);
            return;
        }
        else if(k==2){
                while (1)
                {
                    printf("enter the New mobile Number: ");
                    scanf("%s",customers[x].mobile_number);
                    i=0;
                    while (customers[x].mobile_number[i]){
                    if(!isdigit(customers[x].mobile_number[i])||strlen(customers[x].mobile_number)>11){
                    printf("Invaild mobile number please try again:\n");
                    break;
                    }
                    ++i;
                    }
                if(i==11)
                    break;
        
                }
            Delete_account(x);
            return;
        }
        else if(k==3){
                while (1)
                {   
                    i=0;
                    printf("enter New E-mail: ");
                    gets(customers[x].email);
                    int atpos=-1,counter=0;
                    while (customers[x].email[i]){
                        if(customers[x].email[i]==' '||counter==2||atpos==0){
                            flag=0;
                            break;
                    }
                    if(customers[x].email[i]=='@'){
                        ++counter;
                        atpos=i;
                    }
                    if(i>atpos && customers[x].email[i]=='.'&&customers[x].email[i+1]=='c'&&customers[x].email[i+2]=='o'&&customers[x].email[i+3]=='m')
                        flag=1;

                    ++i;
                    }
                    if(flag!=1)
                        printf("Invalid E-mail please enter a valid email\n");
                    else 
                    break;
                }
                Delete_account(x);
                return;                
    }
    else
        printf("Wrong Choice Please try again\n");
    
    }
    }
    printf("tha Account number is not found");
    }
