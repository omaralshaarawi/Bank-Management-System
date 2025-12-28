#include <stdio.h>
#include <stdlib.h>
#include "ui_helpers.h"
#include<string.h>
#include "structs.h"
#include <ncurses.h>
#include<string.h>

int login(void) {
    char username[64];
    char password[64];
    ui_clear_title("LOGIN");

    prompt_input("Enter username: ", username, sizeof(username));

    // password masked
    int i = 0;
    mvprintw(getcury(stdscr), 2, "Enter password: ");
    refresh();
    curs_set(1);
    noecho();
    int ch;
    while (1) {
        ch = getch();
        if (ch == '\n' || ch == '\r' || ch == KEY_ENTER) break;
        if (ch == KEY_BACKSPACE || ch == 127 || ch == 8) {
            if (i > 0) {
                i--;
                int y = getcury(stdscr);
                int x = getcurx(stdscr);
                if (x > 0) {
                    move(y, x - 1);
                    delch();
                }
            }
            continue;
        }
        if (ch == KEY_LEFT || ch == KEY_RIGHT || ch == KEY_UP || ch == KEY_DOWN) continue;
        if (ch >= 32 && ch <= 126 && i < (int)sizeof(password)-1) {
            password[i++] = (char)ch;
            addch('*');
            refresh();
        }
    }
    password[i] = '\0';
    curs_set(0);
    echo();
    move(getcury(stdscr)+1, 2);
    refresh();

    FILE *fp = fopen("users.txt", "r");
    if (!fp) {
        mvprintw(getcury(stdscr), 2, "users.txt not found");
        refresh();
        pause_msg(NULL);
        return 0;
    }

    char u[128], p[128];
    int ok = 0;
    while (fscanf(fp, "%127s %127s", u, p) == 2) {
        if (strcmp(u, username) == 0 && strcmp(p, password) == 0) { ok = 1; break; }
    }
    fclose(fp);

    if (ok) {
        mvprintw(getcury(stdscr), 2, "Login successful");
        refresh();
        pause_msg(NULL);
        return 1;
    } else {
        mvprintw(getcury(stdscr), 2, "Login failed");
        refresh();
        pause_msg(NULL);
        return 0;
    }
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
