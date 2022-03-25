#include <stdio.h>

#include "interface.h"
#include "book_management.h"
#include "save.h"
#include "user.h"



int main()
{
    printf("Welcome to the library!\n");
    FILE *fh;
    fh = fopen("user.txt","r");
    if(fh == NULL)
    {
        fh = fopen("user.txt","w+");
    }
    load_login(fh);
    fclose(fh);
    run_interface();
}
