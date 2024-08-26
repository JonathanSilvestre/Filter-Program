#include <stdio.h>
#include <string.h>

char      word[50]; //array to store words

//Create an enumerator for Boolean functions
typedef enum
{
   FALSE = 0,
   TRUE = 1
} T_Bool;

//Function to acquire words from the file
void Acquireword ()
{
    int       i; //Variable to access a location in my character array
    int       car; //variable to store each character as its ASCII value

    car = getchar(); //acquire the first character

    while ((( car == ' ' ) || ( car == '\t' ) || ( car == '\n' ) || ( car == '\r' )) && ( car != EOF )){ //while the character is 
        car = getchar(); //move to the next character
    }

    i = 0; //initialize the variable that indicates the location in my array to 0
    while ((( car != ' ' ) && ( car != '\t' ) && ( car != '\n' ) && ( car != '\r' )) && ( car != EOF )) { //while the character is not
      word[i] = car; //store the character in my word array
      i++; //increment the location in my array
      car = getchar(); //move to the next character
    }
    word[i] = 0x0; //When finished storing the word, mark the end of my array

}

//Function to evaluate if there is a word in my word array
T_Bool Theresaword ()
{
    if ( word[0] == 0x0 ){ //if my word array is empty
        return FALSE; //return false
    }   
    else{ //If not
        return TRUE; //return true
    }
}

//The main function of the program that receives the user's argument
int main(int argc, char *argv[])
{
    char *myparameter; //pointer to my parameter
    char startparameter[20]; //string that indicates the start of the parameter
    char endparameter[20]; //string that indicates the end of the parameter

    if(argc<2){ //If the user did not provide arguments
        printf("ERROR: No arguments were provided"); //Print the error
        return 1; //Return false
    }

    myparameter=argv[1]; //point to the argument entered by the user
    sprintf(startparameter, "@%s", myparameter); //form a string that indicates the start of the parameter
    sprintf(endparameter, "@%s_end", myparameter); //form a string that indicates the end of the parameter

    
    Acquireword(); //acquire my first word

    while ( Theresaword() ){ //While I have a word
        if ( strcmp(word,startparameter)==0 ){ //If my word is the start of my parameter
            while ( Theresaword() ){ //While I have a word
                Acquireword(); //acquire the next word

                if ( strcmp(word,endparameter)==0 ){ //If my word is the end of my parameter
                    break; //break the loop
                }

                printf("%s\n", word); //Print my word
            }
        }
        
        Acquireword(); //Acquire the next word
    }
    
    return 0; //End the program
}