#include <iostream>
#include <fstream>

bool check_equal(const char* str1, const char* str2) {
  int i = 0;
  while (str1[i] != '\0' && str2[i] != '\0') {
    if (str1[i] != str2[i]) {
      return false;
    }
    i++;
  }
  return (str1[i] == '\0' && str2[i] == '\0');
}
bool containsAllLetters(char* word,char* origin){
  int origFreq[26] = {0};
  int wordFreq[26] = {0};

  for (int i=0;origin[i]!='\0';++i){
    char tmp=origin[i];
    if ('A'<=tmp && tmp<='Z'){
      tmp=tmp+'a'-'A';
    }
    if ('a' <= tmp && tmp <= 'z') {
      origFreq[tmp - 'a']++;
    }

  }
  for (int i=0;word[i]!='\0';++i){
    char tmp=word[i];
    if ('A'<=tmp && tmp<='Z'){
      tmp=tmp+'a'-'A';
    }
    if ('a' <= tmp && tmp <= 'z') {
      wordFreq[tmp - 'a']++;
    }

  }
  for (int i = 0; i < 26; ++i) {
    if (origFreq[i] > wordFreq[i]){
      return false;
    }
  }
  return true;
}

int main(int argc, char** argv) {
  if (argc < 5) {
    std::cout << "Error: Incorrect arguments format\n";
    return 1;
  }
  if (!(check_equal(argv[1], "--word") && check_equal(argv[3], "--file"))) {
    std::cout << "Error: Incorrect arguments format\n";
    return 1;
  }
  
  char word[33] = {0};
  char filename[200] = {0};

  for(int i=0; i < 32 && argv[2][i] != '\0'; i++) {
    word[i] = argv[2][i];
  }
  for(int i=0; i < 32 && argv[4][i] != '\0'; i++) {
    filename[i] = argv[4][i];
  }
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cout << "Ошибка: не удалось открыть файл\\n";
    return 1;
  }
  // std::cout << "исходник: " << word << "\n";
  // std::cout << "файл: " << filename << "\n";
  char fileWord[200];
  int count = 0;
  while (file >> fileWord) {
    if (containsAllLetters(fileWord, word)) {
      count++;
    }
  }
  file.close();
  std::cout << count<<std::endl;
  return 0;
}
