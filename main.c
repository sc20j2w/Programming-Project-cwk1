#include <stdio.h>

#include "book_management.h"
#include "interface.h"
#include "user.h"
#include "save.h"



int main(int argc, char** argv){
    int i = 1;
    int j = 1;
    int t = 0;
    char *user_defined;
    user_defined =  (char*)malloc(100*sizeof(char));
    Books = (char*)malloc(100*sizeof(char));
    Users = (char*)malloc(100*sizeof(char));
    Book_borrow = (char*)malloc(100*sizeof(char));
    while(i < argc)
    {
        if(t == 0)
        {
            strcpy(user_defined,argv[i]);
            t = 1;
        }else{
            strcat(user_defined," ");
            strcat(user_defined,argv[i]);
        }
        if(strstr(user_defined,".txt") == NULL)
        {
            i += 1;
            continue;
        }
        if(j == 1)
        {
            strcpy(Books,user_defined);

        }
        if(j == 2)
        {

            strcpy(Users,user_defined);

        }
        if(j == 3)
        {

            strcpy(Book_borrow,user_defined);

        }
        if(j == 4)
        {
            printf("You entered more files than required, only used first three names. \n");
            printf(" \n");
            break;
        }
        t = 0;
        j += 1;
        i += 1;
    }
    printf("Welcome to the library!\n");
    FILE *fp;
    fp = fopen(Books,"r");
    if(fp == NULL)
    {
        fp = fopen(Books,"w+");
    }
    load_books(fp);
    FILE *fd;
    fd = fopen(Users,"r");
    if(fd == NULL)
    {
        fd = fopen(Users,"w+");
    }
    load_login(fd);
    FILE *fh;
    fh = fopen(Book_borrow,"r");
    if(fh == NULL)
    {
        fh = fopen(Book_borrow,"w+");
    }
    load_book_borrow(fh);
    run_interface();
    FILE *fn;
    fn = fopen(Book_borrow,"w+");
    store_book_borrow(fn);
    FILE *fq;
    fq = fopen(Books,"w+");
    store_books(fq);
}
