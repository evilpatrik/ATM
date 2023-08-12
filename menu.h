#include<stdio.h>
#include <stdlib.h>
 //#include "employee.h"
 //#include "customer.h"
void menu()
{
    printf("1) Log in as an employee\n");
    printf("2) Log in as a customer\n");
    printf(REDB"3) Exit\n"NOR);
        int num;
    scanf("%d",&num);


    switch (num)
     {
        case 1:
        printf(GREEN"***************************\n"NOR);
        system("cls");
        empolyee();

            //emp log
            break;
        case 2:
         printf(GREEN"***************************\n"NOR);
         system("cls");
         customer();
         //cus log
         break;
        case 3:
          writeFile();
          exit(0);
          break;

       default:
       printf(RED"Worng number!!!\n"NOR);
       printf(RED"********************************\n"NOR);
       break;
}
if(num!=1&&2&&3){
menu();
}
}
