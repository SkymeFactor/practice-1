#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, char** argv) {
  bool nextIsFileName = false;
  bool nextIsWord = false;
  
  char *fileName = nullptr;
  char *refWord = nullptr;

  for (int i = 1; i < argc; i++) { 
    if (nextIsFileName) {
      fileName = argv[i];
      nextIsFileName = false;
      continue;
    }

    if (nextIsWord) {
      refWord = argv[i];
      nextIsWord = false;
      continue;
    }

    if (strcmp(argv[i], "--file") == 0) {
      nextIsWord = false;
      nextIsFileName = true;
      continue;
    }
    
    if (strcmp(argv[i], "--word") == 0) {
      nextIsFileName = false;
      nextIsWord = true;
      continue;
    }   
  }
  
  if (fileName == nullptr) {
    std::cout << "Error! No file name inputed!" << std::endl;
    return 1;
  }

  if (refWord == nullptr) {
    refWord = "";
  }

  std::fstream file(fileName);
  if (!file.is_open()) {
    std::cout << "Error! Couldn't open file " << fileName << std::endl;
    return 1;
  }

  int refLetCnt[26] = {0}; // the amount of each letter in the reference refWord

  for (int i = 0; i < strlen(refWord); i++) {
    if (refWord[i] >= 'a') {
      refLetCnt[refWord[i] - 'a']++;
    }
    else {
      refLetCnt[refWord[i] - 'A']++;
    }
  }

  int count = 0;
  int letCnt[26]; // array storing the amount of each letter in each word in the file

  while (!file.eof()) {
    char word[100];
    file >> word;
    if (strlen(word) == 0) // an empty string is not a word, so we skip it
      continue;
    
    for (int i = 0; i < 26; i++) {
      letCnt[i] = 0;
    }

    for (int i = 0; i < strlen(word); i++) {
      if (word[i] >= 'a') {
        letCnt[word[i] - 'a']++;
      }
      else {
        letCnt[word[i] - 'A']++;
      }
    }

    bool fitsCriteria = true;
    for (int i = 0; i < 26 && fitsCriteria; i++) {
      if (letCnt[i] < refLetCnt[i]) {
        fitsCriteria = false;
      }
    }

    if (fitsCriteria) {
      count++;
    }
  }

  std::cout << count;

  return 0;
}
