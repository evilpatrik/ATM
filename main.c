#include<stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "customer.h"
#include "menu.h"


int main(){
    readFile();
    system("cls");
    printf(GREEN"*****Welcome to ATMs*****\n"NOR);
    menu();
    

}
void writeFile(){                       //write customers from file
    FILE *fl;
    fl=fopen("customer.bin", "wb");
    for(int i=0;i<person;i++){
        fwrite(&p[i], sizeof(struct personinfo), 1, fl);
    }
    fclose(fl);


}

int readFile(){                           //read customer from file
    int i=0;
    FILE *fl;
    fl=fopen("customer.bin", "rb");
    if(!fl){
        return 0;
    }else{
    while(fread(&p[i], sizeof(struct personinfo), 1, fl)==1){
        i++;
        person++;
     }
    }
    return 1;
}