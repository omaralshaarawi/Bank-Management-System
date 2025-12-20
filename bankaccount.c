#include"structs.c"
#include"main.c"
void add_account(){
    customer m;
    int i,flag=0,n;
    printf("enter the account number : ");
    scanf("%d",&m.account_number);
    for(i=0;i<=n;++i){
        if(m.account_number==s[i].account_number){
            printf("the account number is duplicated");
            flag=1;
            return;
        }
    }
    if(flag)
        return;
    printf("enter your name: ");
    getchar();
    gets(m.name);
    printf("enter your E-mail: ");
    getchar();
    gets(m.email);
    printf("enter your balance: ");
    scanf("%f",&m.balance);
    printf("enter you mobil: ");
    scanf("%d",&m.mobile_number);
    strcpy(m.open.month,"December");
    strcpy(m.open.year,"2025");
    strcpy(m.status,"active");
    printf("Are you sure you want to save:\n1-save\n2-cancel");
    while (1)
    {
        printf("\nenter you choice: ");
        scanf("%d",n);
        if(n==1)
            save_data(m);
        else if (n==2)
            return;
        else
            printf("Wrong choice please try again");
    }
}