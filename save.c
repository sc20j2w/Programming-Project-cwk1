#include "book_management.h"
#include "interface.h"
#include "user.h"
#include "save.h"


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int load_books(FILE*file)
{
    bl_head = (BookList *) malloc(sizeof (BookList));
    bl_head->list = (Book *) malloc(sizeof (Book));
    Book *h, *p,*last;
    h = (Book*) malloc(sizeof (Book));
    bl_head->list = h;
    last = bl_head->list;
    char *line;
    line = (char *) malloc(200*sizeof (char));
    while(1)
    {
        if(fgets(line,50,file) == NULL)
        {
            break;
        }
        p = (Book*) malloc(sizeof (Book));
        p->id = atoi(line);
        fgets(line,50,file);
        p->title = (char *)malloc(sizeof(line));
        strcpy(p->title,line);
        p->title[strlen(p->title)-1] = '\0';
        fgets(line,50,file);
        p->authors = (char *)malloc(sizeof(line));
        strcpy(p->authors,line);
        p->authors[strlen(p->authors)-1] = '\0';
        fgets(line,50,file);
        line[strlen(line)-1] = '\0';
        p->year = atoi(line);
        fgets(line,50,file);
        line[strlen(line)-1] = '\0';
        p->copies = atoi(line);
        last->next = p;
        last = p;
    }
    last->next = NULL;
    return 0;
}


//save the user into file
void load_login(FILE *fd){
    int i = 0;
    temp_list = (User *) malloc(sizeof (User));
    User *head,*p,*last;
    head = (User *) malloc(sizeof (User));
    temp_list = head;
    last = temp_list;
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
        for(i=0 ; i<=99; i++)
        {
            p->book_id[i]=0;
        }
        last->next = p;
        last = p;
    }
    last->next = NULL;
}
