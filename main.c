#include <stdio.h>
#include "structs.h"
#include "bankaccount.c"
#include "prints.c"
#include "menu.c"
#include "transactions.c"
customer customers[10007];
int n;
int main()
{
    printf("Welcome to the Bank Management System\n");
    printf("Please login to continue\n or Quit\n");
    while(1)
    {
        printf("1- Login\n2- Quit\n");
        int choice;
        scanf("%d",&choice);
        if(choice==1)
        {
            if(login())
            {
                break;
            }
        }
        else if(choice==2)
        {
            return 0;
        }
        else
        {
            printf("Invalid choice, please try again.\n");
        }
    }

   load();
   
    while (1)
    {
    printf("please enter the function you want to perform :\n1- ADD Account\n2- Delete Account\n3- Modify Account information \n4- Search \n5- Advanced search\n6- Change status\n7- Withdrawl\n8- Deposit\n9- Transfer amount\n10- Report\n11- Print\n12- Quit\n13-Delete Multiple\n");
    int choice;
    printf("Please Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            add_account();
            break;
        case 2:
            Delete_account(-1);
            break;
        case 3:
            modify_account();
            break;
        case 4:
            search_account(0);
            break;
        case 5:
            advanced_search();
            break;
        case 6:
            changeStatus();
            break;
        case 7:
           withdraw();
            break;
        case 8:
            deposit();
            break;
        case 9:
            transfer();
            break;
        case 10:
            report();
            break;
        case 11:
            print();
            break;
        case 12:
           quit();
        case 13:
        delete_multipile();
        break;
        default:
            printf("Invalid choice, please try again.\n");


    }
    int k;
    printf("1-Go Back to the menu\n2-exit the programme\n");
    while(1){
        printf("enter your choice: ");
        scanf("%d",&k);
        if(k==1)
            break;
        else if (k==2)
            quit();
        else
            printf("Choice please try again\n");

    }
    }

    
    return 0;
 }
