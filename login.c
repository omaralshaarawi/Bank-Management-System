#include <stdio.h>
#include <stdlib.h>
int login()
{
    char username[20];
    char password[20];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
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
                printf("Login successful!\n");
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
