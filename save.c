#include "user.h"
#include "save.h"
#include "book_management.h"

#include "interface.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//save the user into file
void load_login(FILE *fd){
    int i = 0;
    list = (User *) malloc(sizeof (User));
    User *head,*p,*last;
    head = (User *) malloc(sizeof (User));
    list = head;
    last = list;
    char *temp;
    temp = (char *) malloc(100 * sizeof(char));
    while(1)
    {
        //username
        if (fgets(temp,100,fd) == NULL)
        {
            break;
        }
        p = (User *) malloc(sizeof (User));
        p->username = (char *) malloc(100 * sizeof (char));
        strcpy(p->username,temp);
        //password
        fgets(temp,100,fd);
        p->password = (char *) malloc(100 * sizeof (char));
        strcpy(p->password,temp);
        //name
        p->name = (char *) malloc(100 * sizeof (char));
        fgets(temp,100,fd);
        strcpy(p->name,temp);
        //id
        p->book_id = (int *) malloc(100 * sizeof (int ));
        for(i=0;i<100;i++)
        {
            p->book_id[i]=0;
        }
        last->next = p;
        last = p;
    }
    last->next = NULL;
}
