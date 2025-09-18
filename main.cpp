#include <consoleparser.h>
#include <errors.h>
#include <fileparser.h>

#include <cstring>
#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
  if (argc < 5) {
    std::cerr << errors::WRONG_ARGUMENT << std::endl;
    return 1;
  }

  const char* word = consoleparser::getWordFromArguments(argc, argv);
  const char* fileName = consoleparser::getFilenameFromArguments(argc, argv);

  if (word == nullptr || fileName == nullptr) {
    std::cerr << errors::WRONG_ARGUMENT << std::endl;
    return 1;
  }

  int correctWords = fileparser::readWordsAndCountCorrect(fileName, word);
  if (correctWords == -1) {
    return 1;
  }

  std::cout << correctWords << std::endl;

  return 0;
}
