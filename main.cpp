#include <iostream>
#include <cstring>
#include <fstream>

bool compare(char* word, char* string) {
  int wordLenght = std::strlen(word);
  int stringLenght = std::strlen(string);
  
  int t = 0;

  for (int i = 0; i < wordLenght; i++) {
    
    if (word[i] == '\0') continue;
    
    for (int j = 0; j < stringLenght; j++) {
      if (string[j] == '\0') continue;

      if (word[i] == string[j]) {
        t++;
        break;
      }
    }
  }

  return t == wordLenght ? true : false;
}

int main(int argc, char** argv) {
  if (argc <= 0) {
    std::cout << "";
    return -1;
  }

  char* file = nullptr;
  char* word = nullptr;

  for (int i = 1; i < argc; ++i) {
    if (strcmp(argv[i], "--file") == 0) {
      file = argv[i + 1];
    }

    if (strcmp(argv[i], "--word") == 0) {
      word = argv[i + 1];
    }
  }

  if (file == nullptr || word == nullptr) {
    std::cout << "Error. You must provide file and path";
    return -1;
  }


  std::ifstream inputFile(file);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    char fileWord[33];

    int count = 0;

    while (inputFile >> fileWord) {
        if (compare(word, fileWord) == true)
          count++;
    }

    inputFile.close();

    std::cout << count << std::endl;

  return 0;
}
