// Created by : Jiahao Zhu
// Created date : 2020/5/6

//hybrid test

#include "WordCount.h"
#include <iostream>
#include <sstream>
#include "tddFuncs.h"
using namespace std;

int main() {

    cout << "Testing class WordCount..." << endl;

    WordCount w;

    // add multiple members

    string tests[5] = { "testone", "testtwo", "testthree", "testfour", "testfive" };

    for (int i = 1; i < 6; i++)
    {
        ASSERT_EQUALS(1, w.incrWordCount(tests[i - 1]));
        ASSERT_EQUALS(i, w.getTotalWords());
        ASSERT_EQUALS(i, w.getNumUniqueWords());
        for (int j = 0; j < i; j++)
        {
            ASSERT_EQUALS(1, w.getWordCount(tests[j]));
        }
        for (int j = i; j < 5; j++)
        {
            ASSERT_EQUALS(0, w.getWordCount(tests[j]));
        }
        ASSERT_EQUALS(0, w.getWordCount("test"));
    }

    // repeat multiple members

    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j < 5; j++) {
            ASSERT_EQUALS(j + 1, w.incrWordCount(tests[i]));
            ASSERT_EQUALS(5+ i * 4 + j, w.getTotalWords());
            ASSERT_EQUALS(5, w.getNumUniqueWords());
            for (int k = 0; k < i; k++)
            {
                ASSERT_EQUALS(5, w.getWordCount(tests[k]));
            }
            ASSERT_EQUALS(j + 1, w.getWordCount(tests[i]));
            for (int k = i + 1; k < 5; k++)
            {
                ASSERT_EQUALS(1, w.getWordCount(tests[k]));
            }
            ASSERT_EQUALS(0, w.getWordCount("test"));
        }
    }

    // add collisions and uper/lower cases

    string col[4] = { "dtest", "dtestd", "ddtestd", "ddtestdd" };   // (int) d = 100, will not change hash result
    string num[5] = { "One", "tWo", "thRee", "fouR", "FIVE",};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            ASSERT_EQUALS(1, w.incrWordCount(col[i] + num[j - 1]));
            ASSERT_EQUALS(25 + i * 5 + j, w.getTotalWords());
            ASSERT_EQUALS(5 + i * 5 + j, w.getNumUniqueWords());
            ASSERT_EQUALS(0, w.getWordCount("test"));
        }
    }

    // delete

    int accTotal = w.getTotalWords();
    int accUnique = w.getNumUniqueWords();

    for (int i = 0; i < 4; i++)
    {
        for (int j = 1; j < 6; j++)
        {
            accTotal -= 1;
            accUnique -= 1;
            ASSERT_EQUALS(0, w.decrWordCount(col[i] + num[j - 1]));
            ASSERT_EQUALS(accTotal, w.getTotalWords());
            ASSERT_EQUALS(accUnique, w.getNumUniqueWords());
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j < 5; j++) {
            accTotal -= 1;
            ASSERT_EQUALS(5 - j, w.decrWordCount(tests[i]));
            ASSERT_EQUALS(accTotal, w.getTotalWords());
            ASSERT_EQUALS(5, w.getNumUniqueWords());
        }
    }

    for (int i = 1; i < 6; i++)
    {
        accTotal -= 1;
        accUnique -= 1;
        ASSERT_EQUALS(0, w.decrWordCount(tests[i - 1]));
        ASSERT_EQUALS(accTotal, w.getTotalWords());
        ASSERT_EQUALS(accUnique, w.getNumUniqueWords());
    }

    ASSERT_EQUALS(0, w.getTotalWords());

    return 0;
}
