// STONE PAPER SCISSOR

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int random(int low, int up);          // Randoom number generator funcion
int game(char you, char computer);    // Play game function

// Main function

int main(){
char you, comp;

int num = random(1,99);     // Generating a random number in [1,99] and storing it in num variable

// Getting the input from the computer based on the random number generated above

if(num >= 1 && num <= 33){             // num -> 1 - 33 -> stone
   comp = 's';                         // num -> 34 - 66 -> paper
}else if(num >= 34 && num <= 66){      // num -> 67 - 99 -> scissor
   comp = 'p';                         // Here probability of getting any one of stone, paper or scissor is equal i.e 1/3
}else{
   comp = 'z';
}

// Getting input from the user

printf("\n\n\t\tEnter 's' for stone, 'p' for paper and 'z' for scissor\n\n\t\t");
scanf("%c", &you);

// Printing input of user on screen

if(you == 's'){
   printf("\n\n\t\tYou entered Stone");
}else if(you == 'p'){
   printf("\n\n\t\tYou entered Paper");
}else if(you == 'z'){
   printf("\n\n\t\tYou entered scissor");
}else{
    printf("\n\n\t\tEnter valid input\n\n");     // If user enters any key other than s, p or z the compiler would exit the program and returns to the main function
    return 0;
}

// Priniting input of compputer on screen

if(comp == 's'){
   printf("\n\n\t\tComputer entered Stone");
}else if(comp == 'p'){
   printf("\n\n\t\tComputer entered Paper");
}else{
   printf("\n\n\t\tComputer entered scissor");
}

// Calling game function to play the game and storing its value in result

int result = game(you, comp);

// Giving output on the basis of result

if(result == 0){
   printf("\n\n\t\tDraw");
}else if(result == 1){
   printf("\n\n\t\tHurrah! You won");
}else if(result == -1){
   printf("\n\n\t\tOh! Computer wins");
}

printf("\n\n");

return 0;
}


// Function to generate random number

int random(int low, int up){
   srand(time(0));
   int number = (rand()%(up-low+1)+low);
   return number;
}


// Function to play game

int game(char you, char computer){
   if(you == computer){
      return 0;
   }else if(you == 's' && computer == 'p'){
      return -1;
   }else if(you == 's' && computer == 'z'){
      return 1;
   }else if(you == 'p' && computer == 's'){
      return 1;
   }else if(you == 'p' && computer == 'z'){
      return -1;
   }else if(you == 'z' && computer == 's'){
      return -1;
   }else if(you == 'z' && computer == 'p'){
      return 1;
   }
}