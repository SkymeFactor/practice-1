#include <iostream>
#include <fstream>
#include <cstring>

// Function that counts each letter in given word and writes results to an array.
void countLetters( int letCnt[], char *word ) {
  for (int i = 0; i < strlen(word); i++) {
    if (word[i] >= 'a') {
      letCnt[word[i] - 'a']++;
    }
    else {
      letCnt[word[i] - 'A']++;
    }
  }
}

bool isCnt1InCnt2( int letCnt1[], int letCnt2[] ) {
  bool fitsCriteria = true;

  for (int i = 0; i < 26 && fitsCriteria; i++) {
    if (letCnt1[i] > letCnt2[i]) {
      fitsCriteria = false;
    }
  }

  return fitsCriteria;
}

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
    std::cout << "Error! No reference word inputed!" << std::endl;
  }

  std::fstream file(fileName);
  if (!file.is_open()) {
    std::cout << "Error! Couldn't open file " << fileName << std::endl;
    return 1;
  }

  int refLetCnt[26] = {0}; // the amount of each letter in the reference refWord
  countLetters(refLetCnt, refWord);

  int wordCount = 0;

  while (!file.eof()) {
    char word[100];
    file >> word;
    
    if (strlen(word) == 0) { // an empty string is not a word, so we skip it
      continue;
    }
    
    int letCnt[26] = {0};

    countLetters(letCnt, word);

    if (isCnt1InCnt2(refLetCnt, letCnt)) {
      wordCount++;
    }
  }

  std::cout << wordCount;

  return 0;
}
