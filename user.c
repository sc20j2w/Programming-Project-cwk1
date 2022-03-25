#include "book_management.h"

#include "interface.h"
#include "user.h"

#include "save.h"
#include<string.h>
#include<stdio.h>
#include <stdlib.h>

// judge user or librarian
char *what_is_login(){

}


// choice 2
int Login_user(){
    char *tp;
    tp = (char *) malloc(200*sizeof (char));
    stpcpy(tp,what_is_login());
    tp[strlen(tp)-1] = '\0';
    if(strcmp(tp,"librarian") != 0 && strcmp(tp,"0") != 0)
    {

    }else if(strcmp(tp,"librarian") == 0)
    {

    }else if(strcmp(tp,"0") == 0)
    {
        printf("You entered a wrong Username or Password. \n");
    }
}

// choice 1
int register_user()
{
    FILE *fh;
    fh = fopen("user.txt","a+");
    printf("Enter your Name: \n");
    char *tp1;
    tp1 = (char *) malloc(100 * sizeof (char));
    fflush(stdin);
    gets(tp1);
    printf("Enter your Username: \n");
    char *tp2;
    char *tp3;
    tp2 = (char *) malloc(100 * sizeof (char));
    fflush(stdin);
    gets(tp2);
    printf("Enter your Password: \n");
    tp3 = (char *) malloc(100 * sizeof (char));
    fflush(stdin);
    gets(tp3);
    if(strcmp( tp2, "librarian") == 0)
    {
        printf("The username you entered has already existed, please choose an option again.\n");
        return 0;
    }
    User *tp;
    tp = list;
    tp = tp->next;
    if(tp != NULL)
    {
        while(1)
        {

            tp->username[strlen(tp->username)-1] = '\0';
            if(strcmp(tp->username,tp1)==0)
            {
                tp->username[strlen(tp->username)] = '\n';
                printf("The username you entered has already existed, please choose an option again.\n");
                return 0;
            }
            tp->username[strlen(tp->username)] = '\n';
            tp = tp->next;
            if(tp == NULL)
            {
                break;
            }
        }
    }
    User *head, *p, *last;
    last = list;
    p = last;
    head = p -> next;
    while(1)
    {
        if(head == NULL)
        {
            //username
            head = (User *) malloc(sizeof(User));
            head->username = (char *) malloc(100 * sizeof(char));
            strcpy(head->username,tp2);
            head->username[strlen(head->username)] = '\n';
            //password
            head->password = (char *) malloc(100 * sizeof(char));
            strcpy(head->password,tp3);
            head->password[strlen(head->password)] = '\n';
            //name
            head->name = (char *) malloc(100 * sizeof (char));
            strcpy(head -> name, tp1);
            head->name[strlen(head -> name)] = '\n';
            //id
            head->book_id = (int *) malloc(100 * sizeof (int));
            head->next = NULL;
            p->next = head;
            break;
        }
        p = head;
        head = head->next;
    }
    fputs(tp2,fh);
    fputs("\n",fh);
    fputs(tp3,fh);
    fputs("\n",fh);
    fputs(tp1,fh);
    fputs("\n",fh);
    printf("Succeeded in creating an account. \n");
    return 0;
}
