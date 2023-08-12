#include<stdio.h>
int num; // a global num for 

void customer(){                //customer function
   
    int index,ind;
    char cardnumber[17];
    char tempcard[17];
    char password[4];
    int whithdrawl;
    for(int i=0;i<4;i++){
     printf("Please enter cardnumber\n");
     scanf("%s",cardnumber);
     printf("Please enter password\n");
     scanf("%s",password);
     if(logingIn(cardnumber,password)){
        strcpy(tempcard,cardnumber);
        break;
        }else if (i==3){
          printf(REDB"YOU will be back to the main menu press any key ...\n"NOR);
          getch();
          system("cls");
          menu(); 
        
        }else{
            system("cls");
          printf(RED"***************\n"NOR);
          printf(RED"NOT FOUND !!!\n"NOR);
        }
    }
    system("cls");
     index=foundIndex(tempcard);                  //found index of person wiith same cardnumber    
    do{
        printf(RED"********************************\n"NOR);
        printf("1) Account balance\n");
        printf("2) Cash transfer\n");
        printf("3) Cash withdrawal\n");
        printf("4) Recent account updates\n");
        printf("5) Change password\n");
        printf(RED"6) Back to the main menu\n"NOR);
        scanf("%d",&num);
        system("cls");
    switch (num) {
    case 1:
    printf(RED"*******************************\n"NOR);
    printf(GREEN"Account balance is : %d\n"NOR,p[index].balance);
    printf(RED"*******************************\n"NOR);
    printf(Y"Press any key to continue ... \n"NOR);
    getch();
    system("cls");
        break;
    case 2:
    
     printf(GREEN"***Welcome to cash transfer section***\n"NOR);
     
     char seccard[16];
     while(1){
        printf("Please enter the cardnumber that you want to send cash \n");
        scanf("%s",seccard);
        if(serechCard(seccard)){
            ind=foundIndex(seccard);
            printf(C"%s\n"NOR,p[ind].firstname);
            printf(C"%s\n"NOR,p[ind].lastname);
            break;
        }else{
            system("cls");
            printf(RED"***NOT FOUND***\n"NOR);
        }
     }
     printf(C"Are you sure that is correct person if yes enter 1 if No enter 0\n"NOR);
     int n;
     scanf("%d",&n);
     int cash;
     if(n==1)
     {
     while(1){
        printf("How much money do you want to transfer : \n");
        scanf("%d",&cash);
         if(cash<=p[index].balance){
           p[index].balance-=cash;
           p[ind].balance+=cash;
           system("cls");
           printf(GREEN"***your procces has been seccess\n"NOR);
           printf(Y"Press any key to continue ... \n"NOR);
           getch();
           system("cls");
           break;
        }else{
         printf(RED"***NOT ENAUGH MONEY***\n"NOR);
         printf(GREEN"your account balance is : %d\n"NOR,p[index].balance);
            }
         }
     }
     else if(n==0){
        printf(RED"you will be back to the main menu\n"NOR);
     
     }
     writeFile();
        break;
    case 3:
    printf(GREEN"***Welcom to cash withdrawl section***\n"NOR);
    while(1){
    printf("How much money do you want to withdrawl : \n");
    scanf("%d",&whithdrawl);
    if(whithdrawl<=p[index].balance){
        p[index].balance-=whithdrawl;
        system("cls");
        printf(GREEN"***your procces has been seccess\n"NOR);
        printf(Y"Press any key to continue ... \n"NOR);
        getch();
        system("cls");
        break;
    }else{
        printf(RED"***NOT ENAUGH MONEY***\n"NOR);
        printf(GREEN"your account balance is : %d\n"NOR,p[index].balance);
    } 
    }
    writeFile();
     break;
    case 4:
    printf("Sorry this section is not working :\n");
    printf(REDB"404 NOT FOUND\n"NOR);
    printf(Y"Press any key to continue ...\n"NOR);
     getch();
     printf(RED"*************************************\n"NOR);
        break;
    case 5 :
    printf(GREEN"***Welcom to change password section***\n"NOR);
    char newpass[4];
    while(1){
        printf("Please enter new password : \n");
        scanf("%s",newpass);
        if(checkPass(newpass)){
          strcpy(p[index].password,newpass);
          printf(GREEN"your procces has been seccess \n"NOR);
          printf(Y"Press any key to continue ... \n"NOR);
          getch();
          system("cls");
          break;
        }else{
            printf(RED"Please Enter correct form of password\n"NOR);
        }

    }
    writeFile();
    break;
    case 6:
     menu();
        break;
    default:
       printf(RED"********************\n"NOR);
        printf(RED"Wrong number!!!\n"NOR);
        
        break;
    }
    }while(num>6);

}
int logingIn(char car [17], char pas[4]){               //This function is checking customer that  exist
    
    for(int i=0;i<person;i++){
        if(!(strcmp(car,p[i].cardnumber)||strcmp(pas,p[i].password))){
            
            return 1;
        }
    }
    return 0;
}

int foundIndex(char cardnum[17]){                       //This function return index of cardnumber
    int i, z=0;
    for(i=0;i<person;i++){  
        if(!strcmp(cardnum,p[i].cardnumber)){
                break;
        }
    }
    return i;
}

int serechCard(char card[16]){                      //This function is serceching cards thas exist
    for(int i=0;i<person;i++){
        if(!strcmp(card,p[i].cardnumber)){
            return 1;
        }
    }
    return 0;
}

