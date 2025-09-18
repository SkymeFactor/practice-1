#include <errors.h>

#include <fstream>
#include <iostream>

#define MAX_WORD_SIZE 32

namespace fileparser {

int readWordsAndCountCorrect(const char* fileName, const char* expectedWord) {
  std::ifstream is(fileName);
  if (!is.is_open()) {
    std::cerr << errors::FAILED_TO_OPEN_FILE << std::endl;
    return -1;
  }

  const int LENGTH_OF_EXPECTED_WORD = strlen(expectedWord);
  int amountOfCorrectWords = 0;

  char word[MAX_WORD_SIZE + 1];
  is >> word;
  while (!is.eof()) {
    int checkedLetters[LENGTH_OF_EXPECTED_WORD];
    for (int i = 0; i < LENGTH_OF_EXPECTED_WORD; i++) {
      checkedLetters[i] = 0;
    }

    for (char letter : word) {
      for (int i = 0; i < LENGTH_OF_EXPECTED_WORD; i++) {
        if (letter == expectedWord[i]) {
          checkedLetters[i] = 1;
        }
      }
    }

    int amountOfSameLetters = 0;
    for (int element : checkedLetters) {
      amountOfSameLetters += element;
    }

    if (amountOfSameLetters == LENGTH_OF_EXPECTED_WORD) {
      amountOfCorrectWords++;
    }

    is >> word;
  }

  is.close();

  return amountOfCorrectWords;
}
};  // namespace fileparser
