#include <iostream>
#include <fstream>
#include <cstring>

const int N = 200;
bool used[N] {};

int same_letters(char* cur) {
  bool used_cur[N] {};
  for (int i = 0; cur[i]; i++) {
    used_cur[int(cur[i])] = 1;
  }
  int ans = 0;
  for (int i = 65; i < 123; i++) {
    if (used[i] && !used_cur[i]) {
      ans = i;
      break;
    }
  }
  return ans;
}

int main(int argc, char** argv) {
  if (argc < 5) {
    std::cout << "ERROR argc\n";
    return 0;
  }
  if (strcmp(argv[1], "--word") != 0) {
    std::cout << "ERROR word\n";
    return 0;
  }
  if (strcmp(argv[3], "--file") != 0) {
    std::cout << "ERROR file\n";
    return 0;
  }

  char* word = argv[2];
  char* filename = argv[4];

  std::ifstream in;
  in.open(filename);
  if (in.bad()) {
    std::cout << "ERROR filename\n";
    return 0;
  }

  for (int i = 0; word[i]; i++) {
    used[int(word[i])] = 1;
  }

  char word_cur[35] {};
  int cnt = 0;
  while (in >> word_cur) {
    int res = same_letters(word_cur);
    //std::cout << word_cur << " " << res << '\n';
    if (res == 0) {
      cnt++;
    }
  }

  std::cout << cnt << '\n';

  return 0;
}
