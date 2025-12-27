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
        i=0,flag=1;
        while (m.mobile_number[i]){
           if(!isdigit(m.mobile_number[i]))
            {
                printf("Invaild mobile number please try again:\n");
                flag=0;
                break;
            }
            ++i;
        }
        if(flag)
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
int Delete_account(int multiple){          //check if he want to delete multiple
    int x,i,k,flag;
    FILE *file1,*file2;
    while(1){
    if(multiple>=0)
    x=multiple;
    else 
        x=search_account(1);
    if(x>=0){

        if(customers[x].balance!=0){
            printf("the deletion is rejected because the account contain money\n");
            return -1;
        }
        for(i=x;i<=n;++i){
            customers[i]=customers[i+1];
        }
        --n;
        FILE *fptr;
        char acc_number[50];
        sprintf(acc_number,"%lld.txt",customers[x].account_number);
        if(remove(acc_number)!=0){
            printf("file is not found\n");
            return -1;
        }
        save(customers[x],0);
        if(multiple>0)
            return 0;
        if (multiple==-1)
        {
            printf("the deletion is done successfully");
            return 0;
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
    while (1)
    {
    
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
            save(customers[x],0);
            return;
        }
        else if(k==2){
                while (1)
                {
                    printf("enter the New mobile Number: ");
                    scanf("%s",customers[x].mobile_number);
                    i=0,flag=1;
                    while (customers[x].mobile_number[i]){
                        if(!isdigit(customers[x].mobile_number[i])){
                        printf("Invaild mobile number please try again\n");
                        flag=0;
                        break;
                        }
                        ++i;
                    }
                if(flag)
                    break;
        
                }
            save(customers[x],0);
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
                save(customers[x],0);
                return;                
    }
    else
        printf("Wrong Choice Please try again\n");
    
    }
    }
    printf("\n-----tha Account number is not found-----\n1-enter another account\n2-exit\n");
    while (1)
    {
        int s;
        printf("enter your choice: ");
        scanf("%d",&s);
        if(s==1)
            break;
        else if (s==2)
            return;
        else
            printf("Wrong choice please try again: ");
        
    }
    }
}
void delete_multipile(){
    int k,i,month,year,flag,cnt;
    printf("1-Delete by date\n2-Inactive accounts");
    while ((1))
    {
        printf("enter your choice: ");
        scanf("%d",&k);
        if(k==1)
            break;
        else if (k==2)
            break;
        else
            printf("Wrong choice please try again\n");
    }
    if(k==1){
        flag=0,cnt=0;
        printf("enter the month of date: ");
        scanf("%d",&month);
        printf("enter the year of date: ");
        scanf("%d",year);
        for(i=n;i>=0;--i){
            if(customers[i].open.month==month&&customers[i].open.year==year){
                    if(Delete_account(i)==-1){
                        printf("the Account Number of this account is :%lld\n",customers[i].account_number);
                    }
                    else{
                    flag=1;
                    ++cnt;
                    }
            }
        }
        if(flag){
            printf("\n--------the process of deteltion the accounts is completed------\nthe numbers of accounts that deleted is:%d",cnt);
        }    
        else
            printf("there is no account with the same date\n");
    }
    if(k==2){
        time_t t = time(NULL);          //calculate all secondes from 1970
        struct tm *currentTime = localtime(&t);
        int current_mon = currentTime->tm_mon + 1;
        int current_year = currentTime->tm_year + 1900;
        int cnt = 0;
        int flag = 0;
        for(i=n;i>=0;--i){
            int total_current_months = (current_year * 12) + current_mon;
            int total_open_months = (customers[i].open.year * 12) + customers[i].open.month;
            int diff_months = total_current_months - total_open_months;
            if(customers[i].balance==0&&diff_months>=3){
                if(Delete_account(i)!=-1){
                    flag=1;
                    ++cnt;
                }
            }

        }
    }
}    
