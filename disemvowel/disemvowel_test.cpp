#include <gtest/gtest.h>

#include "disemvowel.h"

//Changed the test cases to free up the used memmory from disemvowel.c by
//creating a holder variable to disemvowel the string, which allows
//us to free it after the ASSERT_STREQ call

TEST(Disemvowel, HandleEmptyString) {
  char* hold;
  hold=disemvowel((char*) "");
  ASSERT_STREQ("", hold);
  free(hold);
}

TEST(Disemvowel, HandleNoVowels) {
  char* hold;
  hold=disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", hold);
free(hold);
}

TEST(Disemvowel, HandleOnlyVowels) {
   char* hold;
  hold=disemvowel((char*) "aeiouAEIOUOIEAuoiea");
ASSERT_STREQ("", hold);
free(hold);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
   char* hold;
   hold=disemvowel((char*) "Morris, Minnesota");
ASSERT_STREQ("Mrrs, Mnnst", hold);
free(hold);
}

TEST(Disemvowel, HandlePunctuation) {
   char* hold;
  hold=disemvowel((char*) "An (Unexplained) Elephant!");
ASSERT_STREQ("n (nxplnd) lphnt!", hold);
free(hold);
}

TEST(Disemvowel, HandleLongString) {
  char* str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';

  char* hold;
    hold = disemvowel(str);
  ASSERT_STREQ("xyz", hold);
  
  free(hold);
  free(str);
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
