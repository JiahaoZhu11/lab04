// Created by : Jiahao Zhu
// Created date : 2020/5/6

// test for empty table and single insertion

#include "WordCount.h"
#include <iostream>
#include <sstream>
#include "tddFuncs.h"
using namespace std;

int main() {

    cout << "Testing class WordCount..." << endl;

    WordCount w;

        // test for empty table

    ASSERT_EQUALS(0, w.getTotalWords());
    ASSERT_EQUALS(0, w.getNumUniqueWords());
    ASSERT_EQUALS(0, w.getWordCount("test"));
    ASSERT_EQUALS(-1, w.decrWordCount("test"));
    ASSERT_EQUALS(0, w.getTotalWords());
    ASSERT_EQUALS(0, w.getNumUniqueWords());
    ASSERT_EQUALS(0, w.getWordCount("test"));

        // test for adding to empty table

    ASSERT_EQUALS(1, w.incrWordCount("test"));
    ASSERT_EQUALS(1, w.getTotalWords());
    ASSERT_EQUALS(1, w.getNumUniqueWords());
    ASSERT_EQUALS(1, w.getWordCount("test"));
    ASSERT_EQUALS(0, w.getWordCount("testone"));

        // test for deleting from single member table

    ASSERT_EQUALS(-1, w.decrWordCount("testone"));
    ASSERT_EQUALS(1, w.getTotalWords());
    ASSERT_EQUALS(1, w.getNumUniqueWords());
    ASSERT_EQUALS(1, w.getWordCount("test"));
    ASSERT_EQUALS(0, w.getWordCount("testone"));
    ASSERT_EQUALS(0, w.decrWordCount("test"));
    ASSERT_EQUALS(0, w.getTotalWords());
    ASSERT_EQUALS(0, w.getNumUniqueWords());
    ASSERT_EQUALS(0, w.getWordCount("test"));

  return 0;
}
