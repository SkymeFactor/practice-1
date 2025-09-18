#include <cstring>

namespace consoleparser {

char* getValueOfArgument(int argc, char** argv, char* argumentName) {
  if (argc < 5) {
    return nullptr;
  }

  for (int posOfArgument = 1; posOfArgument <= 3; posOfArgument += 2) {
    if (strcmp(argv[posOfArgument], argumentName) == 0) {
      return argv[posOfArgument + 1];
    }
  }

  return nullptr;
}

char* getWordFromArguments(int argc, char** argv) {
  return getValueOfArgument(argc, argv, (char*)"--word");
}

char* getFilenameFromArguments(int argc, char** argv) {
  return getValueOfArgument(argc, argv, (char*)"--file");
}

};  // namespace consoleparser