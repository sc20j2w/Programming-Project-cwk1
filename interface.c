#include "book_management.h"

#include "interface.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


//beginning of the system
void main_menu() {
    while(1) {
        printf("Please choose an option:\n");
        printf("1) Register an account \n");
        printf("2) Login \n");
        printf("3) Search for books \n");
        printf("4) Display all books \n");
        printf("5) Quit \n");
        printf("     option:");
        int option;
        scanf("%d", &option);
        switch (option) {
            case 1:
                register_user();
                break;
            case 2:
                Login_user();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                printf("Thank you for using library, goodbye.\n");
                return;
            default:
                printf("Sorry, the option you entered was invalid, please try again. \n");
                break;
        }
    }
}

void run_interface ()
{
    main_menu();
}