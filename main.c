#include <stdio.h>

#include "book_management.h"
#include "interface.h"
#include "user.h"
#include "save.h"



int main()
{
    printf("Welcome to the library!\n");
    FILE *fp;
    fp = fopen("book.txt","r");
    if(fp == NULL)
    {
        fp = fopen("book.txt","w+");
    }
    load_books(fp);
    fclose(fp);
    FILE *fd;
    fd = fopen("user.txt","r");
    if(fd == NULL)
    {
        fd = fopen("user.txt","w+");
    }
    load_login(fd);
    run_interface();
}
