#include "book_management.h"

#include "interface.h"
#include "user.h"

#include<string.h>
#include<stdio.h>
#include <stdlib.h>

int register_user()
{
    FILE *fd;
    fd = fopen("user.txt","a+");
    char *temp3;
    temp3 = (char *) malloc(200*sizeof (char));
    printf("Please enter a name: ");
    fflush(stdin);
    gets(temp3);
    printf("Please enter a Username: ");
    char *temp1;
    char *temp2;
    temp1 = (char *) malloc(200*sizeof (char));
    fflush(stdin);
    gets(temp1);
    printf("Please enter a password: ");
    temp2 = (char *) malloc(200*sizeof (char));
    fflush(stdin);
    gets(temp2);
    if(strcmp(temp1,"librarian")==0)
    {
        return 2;
    }
    worker *p,*q,*last;
    last = list;
    q = last;
    p = last->next;
    while(1)
    {
        if(p == NULL)
        {
            p = (worker *) malloc(sizeof(worker));
            p->username = (char *) malloc(200*sizeof(char));
            stpcpy(p->username,temp1);
            p->username[strlen(p->username)] = '\n';
            p->password = (char *) malloc(200*sizeof(char));
            stpcpy(p->password,temp2);
            p->password[strlen(p->password)] = '\n';
            p->book_id = (int *) malloc(10*sizeof (int));
            p->name = (char *) malloc(200*sizeof (char));
            stpcpy(p->name,temp3);
            p->name[strlen(p->name)] = '\n';
            p->next = NULL;
            q->next = p;
            break;
        }
        p->username[strlen(p->username)-1] = '\0';
        if(strcmp(p->username,temp1)== 0)
        {
            return 2;
        }
        q = p;
        p = p->next;
    }
    fputs(temp1,fd);
    fputs("\n",fd);
    fputs(temp2,fd);
    fputs("\n",fd);
    fputs(temp3,fd);
    fputs("\n",fd);
    printf("Registered library account successfully!");
    printf("\n");
    return 0;
}