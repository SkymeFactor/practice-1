#pragma once

#include <cstring>

namespace consoleparser {

char* getWordFromArguments(int argc, char** argv);

char* getFilenameFromArguments(int argc, char** argv);

};  // namespace consoleparser