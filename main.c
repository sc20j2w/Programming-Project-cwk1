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
    if(argv[1] == NULL || argv[2] == NULL || argv[3] == NULL ){
        printf("You don't name all three files you need. \n");
        printf("The program automatically generates three files or you can re-enter the program to name the folder. \n");
        char *a = "users.txt";
        char *b = "books.txt";
        char *c = "book_borrow.txt";
        strcpy(Users,a);
        printf("The file storing the user is automatically named users. \n");
        fflush(stdin);
        strcpy(Books,b);
        printf("The file storing the book is automatically named books. \n");
        fflush(stdin);
        strcpy(Book_borrow,c);
        printf("The file storing the books that have borrowed is automatically named book_borrow. \n");
        fflush(stdin);
    }else{
        while (i < argc) {
            if (t == 0) {
                strcpy(user_defined, argv[i]);
                t = 1;
            } else {
                strcat(user_defined, " ");
                strcat(user_defined, argv[i]);
            }
            if (strstr(user_defined, ".txt") == NULL) {
                i += 1;
                continue;
            }
            if (j == 1) {
                strcpy(Users, user_defined);
            }
            if (j == 2) {
                strcpy(Books, user_defined);
            }
            if (j == 3) {
                strcpy(Book_borrow, user_defined);
            }
            if (j == 4) {
                printf("You entered more files than required, only used first three names. \n");
                printf(" \n");
                break;
            }
            t = 0;
            j += 1;
            i += 1;
        }
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
