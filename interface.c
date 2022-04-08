#include "book_management.h"
#include "interface.h"
#include "user.h"
#include "save.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void Display_books_login() {
    printf("%s\t","ID");
    printf("%-30s\t","Title");
    printf("%-30s\t","Authors");
    printf("%-4s\t","Year");
    printf("%-4s\n","Copies");
    Book *p;
    p = bl_head->list;
    p = p->next;
    while(1){
        if(p != NULL){
            printf("%d\t",p->id);
            printf("%-30s\t",p->title);
            printf("%-30s\t",p->authors);
            printf("%-4d\t",p->year);
            printf("%-4d\n",p->copies);
            p = p->next;
        }else if (1){
            break;
        }
    }
    fflush(stdin);
}

void Display_books_no_login() {
    printf("%s\t","ID");
    printf("%-30s\t","Title");
    printf("%-30s\t","Authors");
    printf("%-4s\t","Year");
    printf("%-4s\n","Copies");
    Book *p;
    p = bl_head->list;
    p = p->next;
    while(1){
        if(p != NULL){
            printf("%d\t",p->id);
            printf("%-30s\t",p->title);
            printf("%-30s\t",p->authors);
            printf("%-4d\t",p->year);
            printf("%-4d\n",p->copies);
            p = p->next;
        }else if (1){
            break;
        }
    }
    main_menu();
    fflush(stdin);
}



//beginning of the system
void main_menu() {
    while(1) {
        printf("Please choose an option:\n");
        printf("1 Register an account \n");
        printf("2 Login \n");
        printf("3 Search for books \n");
        printf("4 Display all books \n");
        printf("5 Quit \n");
        printf("     option:");
        int option;
        while(1){
            int j = 0;
            scanf("%d", &option);
            while(getchar() != '\n') j++;
            if(j > 0) {
                printf("Sorry, the option you entered was invalid, please try again.\n");
                printf("Please choose an option:\n");
                printf("1 Register an account \n");
                printf("2 Login \n");
                printf("3 Search for books \n");
                printf("4 Display all books \n");
                printf("5 Quit \n");
                printf("     option:");
                continue;
            }else break;
        }
        if (option == 1) {
            register_user();
            break;
        }else if(option == 2) {
            Login();
            break;
        }else if(option == 3) {
            book_search();
        }else if(option == 4) {
            Display_books_no_login();
            break;
        }else if(option == 5) {
            printf("Thank you for using library, goodbye.\n");
            return;
        }else if (option != 1 && option != 2 && option != 3 && option != 4 && option != 5){
            printf("Sorry, the option you entered was invalid, please try again. \n");
            continue;
        }
    }
}

void run_interface (){
    main_menu();
}