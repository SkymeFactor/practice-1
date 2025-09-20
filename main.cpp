#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
  char *word = argv[0], *file = argv[0];
  for (int i = 2; i < argc; i++) {
    if (!strcmp(argv[i - 1], "--word") && !strcmp(word, argv[0])) {
      word = argv[i];
    }
    else if (!strcmp(argv[i - 1], "--file") && !strcmp(file, argv[0])) {
      file = argv[i];
    }
  }
  if (strcmp(word, argv[0]) && strcmp(file, argv[0])) {
    bool word_mask[26] = {};
    for (int i = 0; i < strlen(word); i++) {
      word_mask[word[i] - 'a' + ('a' - 'A') * (word[i] < 'a')] = true;
    }
    std::ifstream in(file);
    if (!in) {
      std::cout << "Can't open file";
      return 2;
    }
    char text_word[1000];
    int res = 0;
    while (in >> text_word) {
      bool text_word_mask[26] = {}, flag = true;
      for (int i = 0; i < strlen(text_word); i++) {
        text_word_mask[text_word[i] - 'a' + ('a' - 'A') * (text_word[i] < 'a')] = true;
      }
      for (int i = 0; i < 26; i++) {
        if (word_mask[i] && !text_word_mask[i]) {
            flag = false;
            break;
        }
      }
      res += flag;
    }
    std::cout << res;
  }
  else {
    std::cout << "Wrong input format";
    return 1;
  }
}