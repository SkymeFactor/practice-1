#include <iostream>
#include <fstream>
#include <cstring>


bool charInWord(char* word, char charToFind) {
  charToFind = tolower(charToFind);
  for (int i = 0; i < strlen(word); i++) {
    if (tolower(word[i]) == charToFind) 
      return true;
  }
  return false;
}


int main(int argc, char** argv) {
  if (argc >= 5) {
    char* word = nullptr;
    char* filename = nullptr;
    
    for (int i = 1; i < argc; i++) {
      if (strcmp(argv[i - 1], "--word") == 0) {
        word = argv[i];
      } else if (strcmp(argv[i - 1], "--file") == 0) {
        filename = argv[i];
      }
    }

    if (word == nullptr || filename == nullptr) {
      std::cout << "Syntax Error: ./neatcounter --word <word> --file <file>";
      return 1;
    }
    
    std::ifstream filein{filename};
    if (!filein.is_open()) {
      std::cout << "File Error: Cannot open file";
      return 2;
    }

    char nowWord[100]; 
    int count = 0;
    while (filein >> nowWord) {
      for (int i = 0; i < strlen(word); i++) {
        if (!charInWord(nowWord, word[i])){
          count--;
          break;
        }
      }
      count++;
    }
    std::cout << count;

  } else {
    std::cout << "Syntax Error: ./neatcounter --word <word> --file <file>";
    return 1;
  }
  return 0;
}
