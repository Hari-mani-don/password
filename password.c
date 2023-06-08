#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>



int isNumeric(char num){
   return num>='0' && num<='9';
}
int check_password(char *password){
    int rank=0;
    int uppercaseCount=0;
    int lowercaseCount=0;
    int symbolCount=0;
    int numericCount=0;
    int length = strlen(password);
   

   /*
    for(int i=0; i<length;i++){
         if(password[i]>='A' && password[i]<='Z'){
         uppercaseCount++;   
          }
          else if(password[i]>='a' && password[i]<='z'){
            lowercaseCount++;
        }
          else if(!(password[i]>='A' && password[i]<='Z') && !(password[i]>='a' && password[i]<='z') && !(password[i]>='0' && password[i]<='9')){
            symbolCount++;
        }
        
        if(isNumeric(password[i]) && i<length-2 && isNumeric(password[i+1]) && isNumeric(password[i+2])) {
            numericCount++;
        }

    }
*/


    for(int i=0; i<length; i++){

        if (isupper(password[i])){
            uppercaseCount++;
        }else if (islower(password[i])){
           lowercaseCount++;
        }else if (!isalnum(password[i])){
           symbolCount++;
        }else if (isNumeric(password[i])  && isNumeric(password[i+1]) && isNumeric(password[i+2])){
        numericCount++;
       }
       
        
    }
    
   //Condition:1 Minimum length of 8 character
     if(length>=8){
        rank++;
     }

     //Condition:2 At least one uppercase character
     if(uppercaseCount>0){
        rank++;
     }

     //Condition:3 At least three lowercase character
     if(lowercaseCount>=3){
        rank++;
     }

     //Condition:4 At least one symbole character
     if(symbolCount>0){
        rank++;
     }

     //Condition:5 At least three non-sequential numeric character
     if (numericCount>0)
     {
        rank++;
             }
     
    return rank;
   
}

int main(){
    char password[50];
    
    //input from the user 
    printf("Enter the password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")]='\0';

    int rank=check_password(password);

    //print message based on the passwrod rank
    switch (rank)
    {
    case 0:
    printf("Weakest password\n");
        break;
        case 1:
    printf("Weak password\n");
        break;
        case 2:
    printf("Average password\n");
        break;
        case 3:
    printf("Medium password\n");
        break;
        case 4:
    printf("strong password\n");
        break;
        case 5: 
        printf("Strongest password\n");
        break;
    
    default:
    printf("Invalid rank\n");
        break;
    }

}
