#include "WordCount.h"

using namespace std;

// Default constructor
WordCount::WordCount() {}

// Simple hash function. Do not modify.
size_t WordCount::hash(std::string word) const {
	size_t accumulator = 0;
	for (size_t i = 0; i < word.size(); i++) {
		accumulator += word.at(i);
	}
	return accumulator % CAPACITY;
}

int WordCount::getTotalWords() const {
	int count = 0;
    for (size_t i = 0; i < CAPACITY; i++) {
        for(size_t j = 0; j < table[i].size(); j++) {
            count += table[i][j].second;
        }
    }
	return count;
}

int WordCount::getNumUniqueWords() const {
	int count = 0;
    for (size_t i = 0; i < CAPACITY; i++) {
        count += table[i].size();
    }
	return count;
}

int WordCount::getWordCount(std::string word) const {
	std::string temp = makeValidWord(word);
    size_t index = hash(temp);
    for (size_t i = 0; i < table[index].size(); i++) {
        if (table[index][i].first == temp) return table[index][i].second;
    }
	return 0;
}
	
int WordCount::incrWordCount(std::string word) {
    std::string temp = makeValidWord(word);
    if (temp == "") return 0;
	size_t index = hash(temp);
    for (size_t i = 0; i < table[index].size(); i++) {
        if (table[index][i].first == temp) return ++table[index][i].second;
    }
    table[index].push_back(make_pair(temp, 1));
	return 1;
}

int WordCount::decrWordCount(std::string word) {
	std::string temp = makeValidWord(word);
    size_t index = hash(temp);
    for (size_t i = 0; i < table[index].size(); i++) {
        if (table[index][i].first == temp) {
            if (table[index][i].second > 1) return --table[index][i].second;
            table[index].erase(table[index].begin() + i);
            return 0;
        }
    }
	return -1;
}

bool WordCount::isWordChar(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return true;
	return false;
}

std::string WordCount::makeValidWord(std::string word) {
	std::string temp = "";
    std::string tempSign = "";
    for (size_t i = 0; i < word.length(); i++) {
        if (isWordChar(word[i])) {
            if (tempSign != "") {
                temp += tempSign;
                tempSign = "";
            }
            temp += tolower(word[i]);
        }
        else if (word[i] == (char) 39 || word[i] == (char) 45) {
            if (temp == "") continue;
            tempSign += word[i];
        }
    }
	return temp;
}
