#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, char** argv) {
  if (argc == 5) {
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
      return 0;
    }
    
    std::ifstream filein{filename};
    char now_word[100]; 
    int count = 0;
    while (filein >> now_word) {
      for (int i = 0; i < strlen(word); i++) {
        if (strrchr(now_word, (int) word[i]) == nullptr) {
          count--;
          break;
        }
      }
      count++;
    }
    std::cout << count;
  } else {
    std::cout << argc << "Syntax Error: ./neatcounter --word <word> --file <file>";
  }
  return 0;
}
