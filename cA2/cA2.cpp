/*
File: Assignment 2 cA2.cpp
Name: Ian Ewing
Date: January 31, 2020
Description: This program allows a user to input separate integers as a base and exponent/ 
The program will return the power of those two integers upon request. 
It will only allow numbers within a predetermined range for the base and the exponent. 
The program runs until the user chooses to exit. 
*/

#include <stdio.h>

//Function prototypes
void printMenu(void);
int calculatePower(int base, int exp);
int getNum(void);
int checkRange(int checkVal, int minVal, int maxVal);
int checkInput(int menuChoice, int base, int exp);
int promptForInput(void);

int main(void)
{
    int menuChoice = 0;
    int base = 0;
    int exp = 0;

    while (menuChoice != 4) //Allows the user to continue in a loop until they manually exit the program.
    {
        printMenu();
        menuChoice = getNum(); //Takes input from the user and puts it into menuChoice
        
        if (menuChoice == 1) {
            base = checkInput(menuChoice, base, exp); //Stores user input for the base variable into base
        }
        else if (menuChoice == 2) {
            exp = checkInput(menuChoice, base, exp); //Stores user input for the exp variable into variable
        }
        else if (menuChoice == 3) {
            printf("The answer is %d\n", calculatePower(base, exp)); //Passes the user entered variables for base and exp 
        }
        else if (menuChoice == 4)
        {
            printf("Goodbye. Ian is a buttface\n"); //Prints goodbye and ends the while loop, ending the program.
        }
    }
    return 0;
}

#pragma warning(disable: 4996)
int getNum(void)
{
    /* the array is 121 bytes in size; we'll see in a later lecture how we can improve this code */
    char record[121] = { 0 }; /* record stores the string */
    int number = 0;
    /* NOTE to student: indent and brace this function consistent with your others */
    /* use fgets() to get a string from the keyboard */
    fgets(record, 121, stdin);
    /* extract the number from the string; sscanf() returns a number
     * corresponding with the number of items it found in the string */
    if (sscanf(record, "%d", &number) != 1)
    {
        /* if the user did not enter a number recognizable by
         * the system, set number to -1 */
        number = -1;
    }
    return number;
}

void printMenu(void)
{
    printf("Power Menu:\n\n");
    printf("     1. Change base\n");
    printf("     2. Change exponent\n");
    printf("     3. Display base raised to exponent\n");
    printf("     4. Exit program\n\n");
    printf("Please Select an Option:\n");
}


//Uses a while loop to incrememnt a variable. 
//This incrementation allows you to replicat the power function by setting the number
//of times to multiply a base by an exponent.
int calculatePower(int basePower, int expPower)
{
    int answer = basePower;
    int count = 1; //Used for the while loop condition. Will increment up to exponent value

    while (count < expPower)
    {
        answer *= basePower;
        count++;
    }
    return answer;
}

//This function takes in 3 arguments to check whether the integer is within the specified range. 
//It returns a value to the calling function indicating the result of the test.
int checkRange(int checkVal, int minVal, int maxVal)
{
    if (checkVal >= minVal && checkVal <= maxVal)
    {
        return 1; //input is within acceptable range
    }
    else
    {
        return 0; //input is not within the acceptable range
    }
}

//This function will take the input and first check if the program will continue to run.
//If the input is 4, the program will exit
//First the function will compare the input against the checkRange function
//If its valid, the function will either assign it to the base or exponent
//If its choice 3, the function will call calulatePower.
int checkInput(int menuChoice, int base, int exp)
{
    int input = 0;
        
    if (menuChoice == 1)
    {
        input = promptForInput(); //Takes input from the user to place into the base value
        if (checkRange(input, 1, 25) == 1)
        {
            base = input;
            return base;
        }
        else
        {
            printf("That number is not within the acceptable range.\n");
        }

    }
    else if (menuChoice == 2)
    {
        input = promptForInput(); //Takes input from the user to place into the exponent value
        if (checkRange(input, 1, 5) == 1)
        {
            exp = input;
            return exp;
        }
        else
        {
            printf("That number is not within the acceptable range.\n");
        }
    }
    else
    {
        printf("Please enter valid input.\n");
    }
    return 0;
}

int promptForInput(void)
{
    int input = 0;
    printf("Please enter a whole number:\n");
    input = getNum();
    return input;
}
