#include <stdio.h>
#include "structs.h"
#include "bankaccount.c"
#include "login.c"
#include "quit.c"
#include "load.c"
#include "prints.c"
#include "change_status.c"
#include "withdraw.c"
#include "deposit.c"
#include "transfer.c"
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
    customer customerss[] = {
    {9700000000, "Michael Jones", "m.jones@gmail.com", 1000, "01009700000", {12, 2007}, "active"},
    {9700000001, "John Roberto", "j.roberto@outlook.com", 100, "01009700001", {12, 2008}, "active"},
    {9700000002, "Timothy Korman", "t.korman@gmail.com", 200, "01009700002", {12, 2015}, "active"},
    {9700000003, "Michael Robert", "michael@yahoo.com", 300, "01009700003", {11, 2008}, "inactive"},
    {9700000004, "Roberto Thomas", "rob.thomas@gmail.com", 400.5f, "01009700004", {11, 2015}, "active"},
    {9700000005, "David Roberts", "david123@gmail.com", 400.5f, "01009700005", {10, 2015}, "active"},
    {9700000006, "Daniel Graves", "dgrave@outlook.com", 450, "01009700006", {1, 2020}, "inactive"},
    {9700000007, "Philipe Brian", "p.brian@outlook.com", 460, "01009700007", {2, 2020}, "active"},
    {9700000008, "Adam Mark", "ad.mark@gmail.com", 350, "01009700008", {10, 2015}, "inactive"},
    {9700000009, "James Adams", "j.adams@gmail.com", 250, "01009700009", {5, 2017}, "active"}
    };

    printf("please enter the function you want to perform :\n1- ADD Account\n2- Delete Account\n3- Modify Account information \n4- Search \n5- Advanced search\n6- Change status\n7- Withdrawl\n8- Deposit\n9- Transfer amount\n10- Report\n11- Print\n12- Quit\n");

    int choice;
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
        
        default:
            printf("Invalid choice, please try again.\n");


    }
    }

    
    return 0;
 }
