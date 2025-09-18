#include <iostream>
#include <cstring>

int main(int argc, char** argv) {
  if (argc == 5) {
    int wordindex = 0, fileindex = 0;
    for (int i = 0; i < argc; i++) {
      if (strcmp(argv[i], "--word") == 0) {
        wordindex = i + 1;
      } else if (strcmp(argv[i], "--file") == 0) {
        fileindex = i + 1;
      }
    }
    freopen(argv[fileindex], "r", stdin);
    char now_word[100]; 
    int count = 0;
    while (std::cin >> now_word) {
      for (int i = 0; i < strlen(argv[wordindex]); i++) {
        if (strrchr(now_word, (int) argv[wordindex][i]) == nullptr) {
          count--;
          break;
        }
      }
      count++;
    }
    std::cout << count;
    if (wordindex == 0 || fileindex == 0) {
      std::cout << "Syntax Error: ./neatcounter --word <word> --file <file>";
    }
  } else {
    std::cout << argc << "Syntax Error: ./neatcounter --word <word> --file <file>";
  }
  return 0;
}
