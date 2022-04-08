#include "book_management.h"
#include "interface.h"
#include "user.h"
#include "save.h"


#include <string.h>
#include <stdio.h>
#include <stdlib.h>


// store book
int store_book_borrow(FILE*fd){
    int i = 0;
    User *p;
    p = temp_list;
    p = p->next;
    while(1)
    {
        if (p == NULL)
        {
            break;
        }else{
            fputs(p->username, fd);
            fprintf(fd,"%d \n",p->book_id[i]);
            p = p->next;
        }
    }
    return 0;
}

// load book
int load_book_borrow(FILE*fd){
    int i = 0;
    char *t;
    t = (char *) malloc(100*sizeof(t));
    User *p;
    p = temp_list;
    p = p->next;
    while(1)
    {
        if(fgets(t,100,fd) == NULL)
        {
            break;
        }
        if(strcmp(t,p->username) == 0)
            {
                for(i=0 ; i<= 99; i++)
                {
                    fgets(t,100,fd);
                    t[strlen(t)-1] = '\0';
                    p->book_id[i] = atoi(t);
                }
            }
            if(fgets(t,100,fd) == NULL)
            {
                break;
            }
            p = p -> next;
    }
    return 0;
}



// save book
int store_books(FILE*fh)
{
    Book *p;
    p = bl_head->list;
    p = p->next;
    if(fh == NULL)
    {
        return 0;
    }
    while(1)
    {
        if (p == NULL)
        {
            break;
        }else{
            fprintf(fh, "%d\n", p->id);
            p->title[strlen(p->title)] = '\n';
            fputs(p->title, fh);
            p->authors[strlen(p->authors)] = '\n';
            fputs(p->authors, fh);
            fprintf(fh, "%d\n", p->year);
            fprintf(fh, "%d\n", p->copies);
            p = p->next;
        }
    }
    return 0;
}

//load the book from file
int load_books(FILE*fd){
    bl_head = (BookList*) malloc(sizeof (BookList));
    bl_head->list = (Book*) malloc(sizeof (Book));
    Book *head,*p,*last;
    head = (Book*) malloc(sizeof (Book));
    bl_head->list = head;
    last = bl_head->list;
    char *temp;
    temp = (char*) malloc(100 * sizeof (char));
    while(1)
    {
        if(fgets(temp,100,fd) == NULL)
        {
            break;
        }
        p = (Book*) malloc(sizeof (Book));
        //id
        p->id = atoi(temp);
        //tittle
        p->title = (char *)malloc(sizeof(temp));
        fgets(temp,100,fd);
        strcpy(p->title,temp);
        p->title[strlen(p->title)-1] = '\0';
        //authors
        p->authors = (char *)malloc(sizeof(temp));
        fgets(temp,100,fd);
        strcpy(p->authors,temp);
        p->authors[strlen(p->authors)-1] = '\0';
        //year
        fgets(temp,100,fd);
        temp[strlen(temp)-1] = '\0';
        p->year = atoi(temp);
        //copies
        fgets(temp,100,fd);
        temp[strlen(temp)-1] = '\0';
        p->copies = atoi(temp);
        last->next = p;
        last = p;
    }
    last->next = NULL;
    return 0;
}


//load the user from file
void load_login(FILE*fd){
    int i = 0;
    temp_list = (User*) malloc(sizeof (User));
    User *head,*p,*last;
    head = (User*) malloc(sizeof (User));
    temp_list = head;
    last = temp_list;
    char *temp;
    temp = (char*) malloc(100 * sizeof(char));
    while(1)
    {
        if (fgets(temp,100,fd) == NULL)
        {
            break;
        }
        p = (User*) malloc(sizeof (User));
        //username
        p->username = (char*) malloc(100 * sizeof (char));
        strcpy(p->username,temp);
        //password
        p->password = (char*) malloc(100 * sizeof (char));
        fgets(temp,100,fd);
        strcpy(p->password,temp);
        //name
        fgets(temp,100,fd);
        p->name = (char*) malloc(100 * sizeof (char));
        strcpy(p->name,temp);
        //id
        p->book_id = (int*) malloc(100 * sizeof (int));
        for(i=0 ; i<=99; i++)
        {
            p->book_id[i]=0;
        }
        last->next = p;
        last = p;
        }
    last->next = NULL;
}
