#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
                                //color define
#define NOR "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define C "\x1B[36m"
#define Y "\x1B[33m"
#define REDB "\e[1;31m"                               //color define end
struct personinfo               //main struct personinfo
{
    char firstname[30];
    char lastname[30];
    char id[30];
    char phonenumber[30];
    char cardnumber[30];
    int balance;
    char password[5];
};
struct personinfo p[20];       //example of main struct
int person = 0;
int z;

void empolyee()                 //empolyee function 
{
printf(C"***Welcom to empolyee section***\n"NOR);

int pass;
char user[6];
for (int i = 0; i < 3; i++){
    printf("Enter your user name:\n");
    scanf("%s", user);
    printf("Enter your password:\n");
    scanf("%d", &pass);
    if (adminLogin(user, pass)){
     system("cls");
     printf(C"******WELCOME******\n"NOR);
     line_19:
     printf("1) Create an account\n");
     printf("2) Edit an account\n");
     printf("3) Show the richest customer\n");
     printf("4) Show total balance of all accounts\n");
     printf("5) Show all costumer\n");
     printf("6) Back to main menu\n");
     int num;
     scanf("%d", &num);
     switch (num){
     case 1:
     system("cls");
     create();
     printf(GREEN"Costumer has been create successfully\n"NOR);
     printf(Y"Press any key to continue ...\n"NOR);
     getch();
     system("cls");
     printf(RED"*************************************\n"NOR);
     goto line_19;
      break;
    case 2:
    system("cls");
     edit();
     printf(Y"Press any key to continue ...\n"NOR);
     getch();
     system("cls");
     printf(RED"*************************************\n"NOR);
      goto line_19;
       break;
    case 3:
    system("cls");
     findRich();
     printf(Y"Press any key to continue ...\n"NOR);
     getch();
     system("cls");
     printf(RED"*************************************\n"NOR);
      goto line_19;
        break;
    case 4:
    system("cls");
     showTotal();
     printf(Y"Press any key to continue ...\n"NOR);
     getch();
     system("cls");
     printf(RED"*************************************\n"NOR);
      goto line_19;
       break;
    case 5:
    printf(C"Customers Are : \n"NOR);
    printf(RED"*************************************************\n"NOR);
     system("cls");
     showAll();
     printf(Y"Press any key to continue ...\n"NOR);
     getch();
     system("cls");
     printf(RED"*************************************\n"NOR);
     goto line_19;
      break;
    case 6:
     system("cls");
     menu();
      break;
    default:
     printf(RED"Wrong number!!!\n"NOR);
      goto line_19;
       break;
        }
    }
    else if (!adminLogin(user, pass)){
     printf(RED"Try again!!!\n"NOR);
     z++;
    }
    if (z == 3){
     printf(C"*******Please select an option*******\n"NOR);
     menu();
    }
    }
}

void create(){                         // get first_name,last_name,id,phone_number,card_number,balance

printf("Enter firstname : \n");
scanf("%s", p[person].firstname);
printf("Enter lastname : \n");
scanf("%s", p[person].lastname);
printf("Enter id : \n");
while (1){
    scanf("%s", p[person].id);
    if (checkId(p[person].id)){
        break;
    }
    else{
        printf(RED"Enter correct form of id \n"NOR);
    }
}
printf("Enter phone number : \n");
while (1){
    scanf("%s", p[person].phonenumber);
    if (checkPhone(p[person].phonenumber)){
        break;
    }
    else{
        printf(RED"Enter correct form of phonenumber \n"NOR);
    }
}
printf("Enter cardnumber : \n");
while (1){
    scanf("%s", p[person].cardnumber);
    if (checkCard(p[person].cardnumber)){
        break;
    }
    else{
        printf(RED"Cardnumber should be 16 character and just numbers\n"NOR);
    }
}
printf("Enter balance of account : \n");
while (1)
{
    scanf("%d", &p[person].balance);
    if (p[person].balance >= 0){
        break;
    }
    else{
        printf(RED"Balance should be positive and just numbers\n"NOR);
    }
}

printf("Enter password : \n");
while (1){
    scanf("%s", p[person].password);
    if (checkPass(p[person].password)){
        break;
    }
    else{
        printf(RED"Password should be 4 character and just numbers \n"NOR);
    }
}

person++;
}
void edit()                         //edit function that you can change information
{
    int index = 0;
    char cardnum[30];
    int i;

    while (1){
        printf("Enter cardnumber\n");
        scanf("%s", cardnum);
        if (serechCard(cardnum)){
            break;
        }
        else{
            printf(RED"Cardnumber NOT found\n"NOR);
        }
    }
    system("cls");
    index = foundIndex(cardnum);                          // finding index of customer by cardnumber

    printf(C"First name is : %s\n"NOR, p[index].firstname);    //print information of customer [index]
    printf(GREEN"Last name is :%s\n"NOR, p[index].lastname);
    printf(C"Id is :%s\n"NOR, p[index].id);
    printf(GREEN"Phonenumber is :%s\n"NOR, p[index].phonenumber);
    printf(C"Cardnumber is :%s\n"NOR, p[index].cardnumber);
    printf(GREEN"Balance is :%d\n"NOR, p[index].balance);
    printf(C"Password is :%s\n"NOR, p[index].password);         // end of printing

    printf(RED"***********************************\n"NOR);      // edit section has been start
    printf(GREEN"Which one do you want to edit :\n"NOR);
    printf(RED"***********************************\n"NOR);
    printf("1) Firstname :\n");
    printf("2) Lastname :\n");
    printf("3) Id :\n");
    printf("4) Phonenumber :\n");
    printf("5) Password :\n");
    int n;
    char newname[30];
    char newlast[30];
    char newid[10];
    char newphone[11];
    char newpass[4];
    int newbalance;
    scanf("%d", &n);
    switch (n){                                                  //chosie which one do you want to change
    case 1:
        printf(C"***Please enter new name***\n"NOR);
        scanf("%s", newname);
        strcpy(p[index].firstname, newname);
        printf(GREEN"New firstname has been changed seccsfully\n"NOR);
        writeFile();
        break;
    case 2:
        printf(C"***Please enter new lastname***\n"NOR);
        scanf("%s", newlast);
        strcpy(p[index].lastname, newlast);
        printf(GREEN"New lastname has been changed seccsfully\n"NOR);
        writeFile();
        break;
    case 3:
        printf(C"***Please enter new id***\n"NOR);
        while (1){
        scanf("%s", newid);
        if (checkId(newid)){
        strcpy(p[index].id, newid);
        printf(GREEN"New id has been changed seccsfully\n"NOR);
        writeFile();
        break;
         }
        else{
        printf(RED"Enter correct form of id  \n"NOR);
        }
        }
        break;
    case 4:
        printf(C"***Please enter new phonenumber***\n"NOR);
        while (1){
         scanf("%s", newphone);
         if (checkPhone(newphone)){
         strcpy(p[index].phonenumber, newphone);
         printf(GREEN"New phonenumber has been changed seccsfully\n"NOR);
         break;
         }
         else{
         printf(RED"Enter correct form of phonenumber\n"NOR);
         }
        }
        writeFile();
        break;
    case 5:
        printf(C"***Please enter new password***\n"NOR);
        while (1){
         scanf("%s", newpass);
         if (checkPass(newpass)){
            strcpy(p[index].password, newpass);
            printf(GREEN"New password has been changed seccsfully\n"NOR);
            break;
         }
         else{
            printf(RED"Enter correct form of password \n"NOR);
         }
        }
        writeFile();
        break;
    case 6:
        printf(C"***Please enter new balance***\n"NOR);
        while (1){
            scanf("%d", &newbalance);
            if (newbalance >= 0){
                p[index].balance = newbalance;
                printf(GREEN"New balance has been changed seccsfully\n"NOR);
                break;
            }
            else{
                printf(RED"New balance should be positive \n"NOR);
            }
        }
        writeFile();
        break;
    default:
        break;
    }
} 
                                                        //end of edit function
void showTotal()                                       //show toatal balance of all account 
{
    int total = 0;
    for (int i = 0; i < person; i++){
        total += p[i].balance;
    }
    printf(C"ATM total balance is : %d\n"NOR, total);
}                                                       //end show total balance of all account

int adminLogin(char user[], int pass)                    //checking user and password that has been enterd
{
    int password = 1234;
    char username[] = "admin";

    if (pass == password && !strcmp(user, username)){

        return 1;
    }
    return 0;
}                                                           //end adminloging

void findRich()                                              // This function is findig the richest customer
{
    int max = 0;
    int i, index;
    for (i = 0; i < person; i++){
        if (p[i].balance > max){
            max = p[i].balance;
            index = i;
        }
    }
    printf(RED"************************************\n"NOR);   //print information of customer
    printf(C"Firstname : %s\n"NOR, p[index].firstname);
    printf(GREEN"Lastname : %s\n"NOR, p[index].lastname);
    printf(C"Id : %s\n"NOR, p[index].id);
    printf(GREEN"Phonenumber : %s\n"NOR, p[index].phonenumber);
    printf(C"Cardnumber : %s\n"NOR, p[index].cardnumber);
    printf(GREEN"Balance : %d\n"NOR, p[index].balance);
    printf(C"Password : %s\n"NOR, p[index].password);          //end of printing
}                                                               // end of findrichest customer

int checkId(char id[10])                       // This function is checking id
{
    for (int i = 0; id[i] != '\0'; i++){
        if (!isdigit(id[i])){
            return 0;
        }
    }
    if (strlen(id) == 10){
        return 1;
    }
    else{
        return 0;
    }
}                                               //end check id function

int checkPhone(char phone[11])                // This function is checking phone number
{
    for (int i = 0; phone[i] != '\0'; i++){
        if (!isdigit(phone[i])){
            return 0;
        }
    }
    if (strlen(phone) == 11 && phone[0] == '0' && phone[1] == '9'){
        return 1;
    }
    else{
        return 0;
    }
}                                            //end check phonenumber function

int checkPass(char pass[5])                 // This function is checking password
{
    if (strlen(pass) != 4)
        return 0;
    
    for (int i = 0; pass[i] != '\0'; i++){
        if (!isdigit(pass[i])){
            return 0;
        }
    }
    return 1;
}                                             //end checkpassword function

int checkCard(char card[16])                 // This funtion is checking cardnumber
{
    for (int i = 0; card[i] != '\0'; i++){
        if (!isdigit(card[0])){
            return 0;
        }
    }
    if (strlen(card) == 16){
        return 1;
    }
    else{
        return 0;
    }
}

void showAll()                  // This funtion is show all customer information
{
for (int i = 0; i < person; i++){
    printf(C"First name is : %s\n"NOR, p[i].firstname);
    printf(GREEN"Last name is :%s\n"NOR, p[i].lastname);
    printf(C"Id is :%s\n"NOR, p[i].id);
    printf(GREEN"Phonenumber is :%s\n"NOR, p[i].phonenumber);
    printf(C"Cardnumber is :%s\n"NOR, p[i].cardnumber);
    printf(GREEN"Balance is :%d\n"NOR, p[i].balance);
    printf(C"Password is :%s\n"NOR, p[i].password);
    printf(RED"*************************************\n"NOR);
}
}