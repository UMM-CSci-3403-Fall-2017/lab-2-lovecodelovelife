#include <stdlib.h>
#include <string.h>
#include "disemvowel.h"

char* disemvowel(char* str) {
  //Declaring variables
  int i;
  int j;
  bool isVowel = 0;
  int spot = 0;
  int len = strlen(str);
  char* toReturn;
  int vowelCount = 0;
 
  //Array to hold vowel characters to check for
  char vowels[11] = {'a','A','e','E','i','I','o','O','u','U','\0'};

  //For loop to check how many vowels are in the string str
  for(i = 0; i < len; i++) {
    for(j = 0; j < 11; j++) {
      if(str[i] == vowels[j]) {
	vowelCount++;
      }
    }
  }

  //Creating a new string with the correct size of str without vowels
  toReturn = (char*) calloc (len - vowelCount + 1, sizeof(char));
  vowelCount = 0;
  

  //For loop that loops through and adds the characters to toReturn if
  //they aren't a vowel
  for(i = 0; i < len; i++) {
    isVowel = bool(0);
    for(j = 0; j < 11; j++) {
      if(str[i] == vowels[j]) {
        isVowel = bool(1);
	vowelCount++;
      } 
    }
    //Boolean check to see if the letter at i in str is a vowel, if it
    //is then it won't be added, otherwise, the character is added
    //and makes the spot the next char in toReturn
     if(!isVowel) {
	toReturn[spot] = str[i];
	spot++;
    }
  }

  //Returns or string with no vowels
  return toReturn;
}
