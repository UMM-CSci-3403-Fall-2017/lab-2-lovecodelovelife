#include <stdio.h>
#include <stdlib.h>

#include "disemvowel.h"

int main(int argc, char* argv[]) {
  //Added holder string hold to free up within the while loop
  char* line;
  size_t size;
  char* hold;
  
  size = 100;
  line = (char*) malloc (size + 1);

  //Did the same thing as within disemvowel_test.cpp to free the variable
  //which calls disemvowel afer it is used
  while (getline(&line, &size, stdin) > 0) {
    hold = disemvowel(line);
    printf("%s\n", hold);
    free(hold);
  }
}
