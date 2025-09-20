#include <iostream>
#include <fstream>
#include <cstring>


bool containing_letters(char* s1, size_t s1_len, char* s2, size_t s2_len) {
	for (size_t i = 0; i < s1_len; ++i) {
		bool found = false;
		for (size_t j = 0; j < s2_len; ++j) {
			if (s1[i] == s2[j]) found = true;
		}
		if (!found) return false;
	}

  	return true;
}

int main(int argc, char** argv) {
	if (argc < 5) {
		std::cout << "Error: not enough arguments" << std::endl;
		return 0;
	}
	char word[32];
	char path[32];
	for (int i = 0; i < argc; ++i) {
		if (!std::strcmp(*argv, "--word")) {
			for (int j = 0; j < std::strlen(*(argv + 1)); ++j) {
				word[j] = (*(argv + 1))[j];
			}
		}
		if (!std::strcmp(*argv, "--file")) {
			for (int j = 0; j < std::strlen(*(argv + 1)); ++j) {
				path[j] = (*(argv + 1))[j];
			}
		}
		argv++;
	}

	std::ifstream stream;
	stream.open(path);
	if (!stream.is_open()) {
		std::cout << "Erorr: can't open file";
		return 0;
	}

	for (char line[32]; stream >> line;){
		if (containing_letters(word, std::strlen(word), line, std::strlen(line))) {
			std::cout << line << '\n';
		}
	}

	stream.close();
	return 0;
}
