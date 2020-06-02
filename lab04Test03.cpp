// Created by : Jiahao Zhu
// Created date : 2020/5/6

// test for empty table and multiple insertions (repeated)

#include "WordCount.h"
#include <iostream>
#include <sstream>
#include "tddFuncs.h"
using namespace std;

int main() {

    cout << "Testing class WordCount..." << endl;

    WordCount w;

        // test for repeating adding single member

    for (int i = 1; i < 6; i++) {
        ASSERT_EQUALS(i, w.incrWordCount("testone"));
        ASSERT_EQUALS(i, w.getTotalWords());
        ASSERT_EQUALS(1, w.getNumUniqueWords());
        ASSERT_EQUALS(i, w.getWordCount("testone"));
        ASSERT_EQUALS(0, w.getWordCount("test"));
    }

        // test for deleting from multiples of single member

    for (int i = 5; i > -1; i--) {
        ASSERT_EQUALS(i, w.getTotalWords());
        if (i > 0) ASSERT_EQUALS(1, w.getNumUniqueWords());
        else ASSERT_EQUALS(0, w.getNumUniqueWords());
        ASSERT_EQUALS(i, w.getWordCount("testone"));
        ASSERT_EQUALS(0, w.getWordCount("test"));
        ASSERT_EQUALS(i - 1, w.decrWordCount("testone"));
    }
    ASSERT_EQUALS(0, w.getTotalWords());
    ASSERT_EQUALS(0, w.getNumUniqueWords());
    ASSERT_EQUALS(0, w.getWordCount("testone"));

  return 0;
}
