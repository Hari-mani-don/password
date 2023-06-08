/* Alogrithm :
1.start the program.
2.Declare the necdssary variables for password checking: 'password', 'rank',
'uppercaseCount', 'lowercaseCount', 'symbolCount', 'numericcount', and 'length'.
3.Get the password input from the user.
4.Calculate the length of the password using the 'strlen()' function.
5.Initialize all the counters('uppercaseCount', 'lowercaseCount','symbolCount', 'numericCount') to zero.
6.Iterate over each character in the password using a loop.
  a.check if the character is an uppercase letter using the condition'(password[i] >= 'A'
   && password[i] <= 'Z'). If true, increment 'uppercaseCount' by 1
  b.Check if the character is a lowercase letter using the condition '(password[i] >= 'a' &&
  password[i] <= 'z') . If true, increment 'lowercaseCount' by 1.
  c.Check if the character is a symbol (non-alphanumeric) using the condition "(!
  (password[i] >= 'A' && password[i] <= 'Z') & !(password[i] >= 'a' && 
  password[i] <= 'z') && !(password[i] >= '0' && password[i] <= '9'))". If true,
  increment 'symbolCount' by 1.
  d.Check for three consecutive numeric characters using the condition
  '(isNumeric (password[i]) && isNumeric(password[i+1] && isNumeric(password[i+2])). If true,
  increment 'numericCount' by 1.
7.Evaluate the password strength based on the given conditions:
  a.If the length of the password is at least 8 characters, increment 'rank' by 1.
  b.If 'uppercaseCount' is greater than 0, increment 'rank' by 1.
  c.If 'lowercaseCount' is greater than or equal to 3, increment 'rank' by 1.
  d.If 'symbolCount' is greater than 0, increment 'rank' by 1.
  e.If 'numericCount' is greater than 0, increment 'rank' by 1.
8.Print the password strength message based on the value of 'rank':
  a.If 'rank' is 0, print"Weakest password".
  b.If 'rank' is 1, print "Weak password".
  c.If 'rank' is 2, print"Average password".
  d.If 'rank' is 3, print"Medium password".
  e.If 'rank' is 4, print"Strong password".
  f.If 'rank' is 5, print"Strongest password".
  g.If'rank' is not within the above range, print "Invalid rank".
9,End the program.

*/



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
   
    //check each character in the password method 1
   /*
    for(int i=0; i<length;i++)
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

     //check each character in the password method 2
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
