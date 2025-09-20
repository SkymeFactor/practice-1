#include <cstring>
#include <fstream>
#include <iostream>

int error() {
  std::cerr << "Error!\n";
  return -1;
}

int main(int argc, char **argv) {
  char word[33];
  bool needLetters[53];
  std::fill(needLetters, needLetters + 53, false);
  char filepath[(int)1e3];
  char str[33];

  bool fWord = false;
  bool fFilePath = false;

  for (int i = 0; i < argc; ++i) {
    if (std::strcmp(argv[i], "--word") == 0) {
      if (i + 1 < argc && !fWord) {
        std::strcpy(word, argv[i + 1]);
        fWord = true;
        ++i;
      } else {
        return error();
      }
    } else if (std::strcmp(argv[i], "--file") == 0) {
      if (i + 1 < argc && !fFilePath) {
        std::strcpy(filepath, argv[i + 1]);
        fFilePath = true;
        ++i;
      } else {
        return error();
      }
    }
  }

  for (int i = 0; word[i] != '\0'; ++i) {
    needLetters[word[i] - 'a'] = true;
  }

  std::ifstream file;

  file.open(filepath);

  if (!file.is_open()) {
    return error();
  }

  int wordCnt = 0;
  char letter;
  bool curLetters[53];
  std::fill(curLetters, curLetters + 53, false);
  while (file.get(letter)) {
    if (letter == ' ') {
      bool isCorrect = true;

      for (int i = 0; i < 53; ++i) {
        if (needLetters[i] && !curLetters[i]) {
          isCorrect = false;
          break;
        }
      }

      if (isCorrect) {
        wordCnt++;
      }

      std::fill(curLetters, curLetters + 53, false);
      continue;
    }
    curLetters[letter - 'a'] = true;
  }

  bool isCorrect = true;

  for (int i = 0; i < 53; ++i) {
    if (needLetters[i] && !curLetters[i]) {
      isCorrect = false;
    }
  }

  if (isCorrect) {
    wordCnt++;
  }

  std::cout << wordCnt << '\n';

  file.close();
  return 0;
}
