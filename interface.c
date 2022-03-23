#include "book_management.h"

#include "interface.h"

#include<string.h>
#include<stdio.h>
#include <stdlib.h>


//beginning of the system
void main_menu() {
    while(1) {
        printf("Please choose an option:\n");
        printf("1) Register an account\n");
        printf("2) Users login\n");
        printf("3) Librarian login\n");+
        printf("4) Search for books\n");
        printf("5) Display all books\n");
        printf("6) Quit\n");
        printf("     option:");
        int option;
        scanf("%d", &option);
        switch (option) {
            case 1:
                if (option == '1')
                {
                    if(register_user() == 2) //fail to register
                    {
                        printf("The username you entered has already existed, please choose an option again.\n");
                    }
                    fflush(stdin);
                }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                printf("Thank you for using library\n");
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

