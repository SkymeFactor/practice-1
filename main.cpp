#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
  if (argc == 5 && !(strcmp(argv[1], "--word") && strcmp(argv[3], "--word")) && !(strcmp(argv[1], "--file") && strcmp(argv[3], "--file"))) {
    char *word = argv[2], *file = argv[4];
    if (!strcmp(argv[3], "--word")) {
      word = argv[4], file = argv[2];
    }
    bool word_mask[26] = {};
    for (int i = 0; i < strlen(word); i++) {
      word_mask[word[i] - 'a' + ('a' - 'A') * (word[i] < 'a')] = true;
    }
    std::ifstream in(file);
    if (!in) {
      std::cout << "Error";
      return 1;
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
    std::cout << "Error";
    return 1;
  }
}