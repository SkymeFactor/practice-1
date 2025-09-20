#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {
  bool nextIsFileName = false;
  bool nextIsWord = false;
  
  std::string fileName = "";
  std::string refWord = "";

  for (int i = 1; i < argc; i++) { 
    std::string Arg = argv[i];

    if (nextIsFileName) {
      fileName = Arg;
      nextIsFileName = false;
      continue;
    }

    if (nextIsWord) {
      refWord = Arg;
      nextIsWord = false;
      continue;
    }

    if (Arg == "--file") {
      nextIsWord = false;
      nextIsFileName = true;
      continue;
    }
    
    if (Arg == "--word") {
      nextIsFileName = false;
      nextIsWord = true;
      continue;
    }   
  }
  
  std::fstream file(fileName);
  if (!file.is_open()) {
    std::cout << "Error! Couldn't open file " << fileName << std::endl;
    return 1;
  }

  int refLetCnt[26] = {0}; // the amount of each letter in the reference refWord

  for (int i = 0; i < refWord.size(); i++) {
    if (refWord[i] >= 'a') {
      refLetCnt[refWord[i] - 'a']++;
    }
    else {
      refLetCnt[refWord[i] - 'A']++;
    }
  }

  // Debugging
  /*
  for (int i = 0; i < 26; i++)
  {
    if (refLetCnt[i] > 0)
      std::cout << char('A' + i) << ": " << refLetCnt[i] << std::endl;
  }
  */
 
  int count = 0;
  int letCnt[26];

  while (!file.eof()) {
    std::string word;
    file >> word;
    if (word == "")
      continue;
    
    for (int i = 0; i < 26; i++) {
      letCnt[i] = 0;
    }

    for (int i = 0; i < word.size(); i++) {
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
