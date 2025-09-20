#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv) {
  bool nextIsFileName = false;
  bool nextIsWord = false;
  
  std::string fileName = "";
  std::string word = "";

  for (int i = 1; i < argc; i++) { 
    std::string Arg = argv[i];

    if (nextIsFileName) {
      fileName = Arg;
      nextIsFileName = false;
      continue;
    }

    if (nextIsWord) {
      word = Arg;
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

  std::cout << std::endl << "file: " << fileName << std::endl << "word: " << word;

  return 0;
}
