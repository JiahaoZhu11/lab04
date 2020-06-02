// Created by : Jiahao Zhu
// Created date : 2020/5/6

// test for helper functions

#include "WordCount.h"
#include <iostream>
#include <sstream>
#include "tddFuncs.h"
using namespace std;

int main() {

    cout << "Testing class WordCount helper functions..." <<  endl;

    for (int i = 0; i < 128; i++) {     // range in ASCII
        if ((i > 64 && i < 91) || (i > 96 && i < 123)) { // ASCII of letters
            ASSERT_TRUE(WordCount::isWordChar((char) i));
        }
        else {
            ASSERT_TRUE(!WordCount::isWordChar((char) i));
        }
    }

    string test = "";
    string ans = "a-b'c-d'e-f'g-h'i-j'k-l'm-n'o-p'q-r's-t'u-v'w-x'y-z'-'-'-'a-b'c-d'e-f'g-h'i-j'k-l'm-n'o-p'q-r's-t'u-v'w-x'y-z";
    for (int i = 0; i < 128; i++) {
        test += (char) i;
        if (i % 2 == 1) test += '-';
        else test += "'";
    }
    ASSERT_EQUALS(ans, WordCount::makeValidWord(test));

  return 0;
}
