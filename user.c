#include "book_management.h"
#include "interface.h"
#include "user.h"
#include "save.h"

#include<string.h>
#include<stdio.h>
#include <stdlib.h>


// choice 2
int Login() {
    int i;
    char *a = "librarian";
    char *tp1, *tp2;
    tp1 = (char *) malloc(100 * sizeof(char));
    tp2 = (char *) malloc(100 * sizeof(char));
    printf("Enter your username: ");
    fflush(stdin);
    scanf("%s",tp1);
    getchar();
    printf("Enter your password: ");
    fflush(stdin);
    scanf("%s",tp2);
    getchar();
    // if librarian
    if (strcmp(tp1, a) == 0 && strcmp(tp2, a) == 0) {
        while(1){
            printf("\n");
            printf("You are logging in as: librarian \n");
            printf("1) Add a book \n");
            printf("2) Remove a book \n");
            printf("3) Search for books \n");
            printf("4) Display all books \n");
            printf("5) Log out \n");
            printf("        Option: ");
            int option;
            while(1){
                int j = 0;
                scanf("%d", &option);
                while(getchar() != '\n') j++;
                if(j > 0) {
                    printf("Sorry, the option you entered was invalid, please try again.\n");printf("You are logging in as: librarian \n");
                    printf("1) Add a book \n");
                    printf("2) Remove a book \n");
                    printf("3) Search for books \n");
                    printf("4) Display all books \n");
                    printf("5) Log out \n");
                    printf("        Option: ");
                    continue;
                }else break;
            }
            if (option == 1) {
                char *t;
                t = (char *) malloc(100*sizeof (char));
                Book book_add;
                printf("Enter the title of the book you want to add: \n");
                fflush(stdin);
                gets(t);
                book_add.title = (char *) malloc(100*sizeof(char));
                strcpy(book_add.title,t);
                printf("Enter the author of the book you want to add: \n");
                fflush(stdin);
                gets(t);
                book_add.authors = (char *) malloc(100*sizeof(char));
                strcpy(book_add.authors,t);
                printf("Enter the year(number) that the book you want to add: \n");
                fflush(stdin);
                gets(t);
                i = atoi(t);
                while( i <= 0 ){
                    printf("Wrong number. Enter the year(number) that the book you want to add again: \n");
                    gets(t);
                    i = atoi(t);
                }
                book_add.year = i;
                printf("Enter the number of copies(number) of the book that you want to add: \n");
                fflush(stdin);
                gets(t);
                i = atoi(t);
                while( i <= 0 ){
                    printf("Wrong number. Enter the copies(number) that the book you want to add: \n");
                    gets(t);
                    i = atoi(t);
                }
                book_add.copies = i;
                free(t);
                add_book(book_add);
                printf("You have made a change successfully, please login again to refresh routine.\n");
                Login();
                break;
            }else if(option == 2) {
                char *n;
                n = (char*) malloc(100*sizeof (char));
                printf("Enter the ID of the book you wish to remove: \n");
                fflush(stdin);
                gets(n);
                Book book_remove;
                book_remove.id = atoi(n);
                remove_book(book_remove);
                Login();
                break;
            }else if(option == 3) {
                book_search();
            }else if(option == 4) {
                Display_books_login();
            }else if(option == 5) {
                printf("Thank you for logging, goodbye.\n");
                main_menu();
                break;
            }else if (option != 1 && option != 2 && option != 3 && option != 4 && option != 5){
                printf("Sorry, the option you entered was invalid, please try again. \n");
                continue;
            }
        }
    }
    // not librarian
    else{
        User *p;
        p = temp_list;
        p = p->next;
        tp1[strlen(tp1)] = '\n';
        tp2[strlen(tp2)] = '\n';
        while(1)
        {
            if (p == NULL)
            {
                printf("Sorry, you may entered a wrong Username or Password, please try again. \n");
                Login();
            }
            if(strcmp(p->username,tp1) == 0 && strcmp(p->password,tp2) == 0)
            {
                break;
            }
            p = p->next;
        }
        char *name;
        name = (char *) malloc(100*sizeof (char));
        strcpy(name,tp1);
        name[strlen(name)-1] = '\0';
        while(1){
            printf(" \n");
            printf("( logged in as: %s )\n", name);
            printf("1) Borrow a book\n");
            printf("2) Return a book\n");
            printf("3) Search for books\n");
            printf("4) Display all books\n");
            printf("5) Log out\n");
            printf("     Option: ");
            int option;
            while(1){
                int j = 0;
                scanf("%d", &option);
                while(getchar() != '\n') j++;
                if(j > 0) {
                    printf("Sorry, the option you entered was invalid, please try again.\n");
                    printf("( logged in as: %s )\n", name);
                    printf("1) Borrow a book\n");
                    printf("2) Return a book\n");
                    printf("3) Search for books\n");
                    printf("4) Display all books\n");
                    printf("5) Log out\n");
                    printf("     Option: ");
                    continue;
                }else break;
            }
            if (option == 1) {
                book_borrow(name);
            }else if(option == 2) {
                book_return(name);
            }else if(option == 3) {
                book_search();
            }else if(option == 4) {
                Display_books_login();
            }else if(option == 5) {
                printf("Thank you for logging, goodbye.\n");
                main_menu();
                break;
            }else if (option != 1 && option != 2 && option != 3 && option != 4 && option != 5){
                printf("Sorry, the option you entered was invalid, please try again. \n");
                continue;
            }
        }
    }
}




// choice 1
int register_user(){
    FILE *fh;
    char *tp1, *tp2, *tp3;
    tp1 = (char *) malloc(100 * sizeof (char));
    tp2 = (char *) malloc(100 * sizeof (char));
    tp3 = (char *) malloc(100 * sizeof (char));
    fh = fopen("user.txt","a+");
    printf("Enter your Name: \n");
    fflush(stdin);
    scanf("%s",tp1);
    getchar();
    printf("Enter your Username: \n");
    fflush(stdin);
    scanf("%s",tp2);
    getchar();
    printf("Enter your Password: \n");
    fflush(stdin);
    scanf("%s",tp3);
    getchar();
    if(strcmp( tp2, "librarian") == 0)
    {
        printf("The username you entered has already existed, please choose an option again.\n");
        main_menu();
    }
    User *tp;
    tp = temp_list;
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
                main_menu();
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
    last = temp_list;
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
    main_menu();
}
