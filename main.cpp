#include <cstring>
#include <iostream>

int main(int argc, char* argv[]) {
	if (argc < 5) {
		std::cout << "Not enough arguments" << std::endl;
		return 0;
	}
	char* keyword;
	char* file_path;
	bool kw_found = false;
	bool fp_found = false;
	for (int i = 0; i < argc-1; i++) {
		if (strcmp(argv[i], "--word") == 0) {
			keyword = argv[i+1];
			kw_found = true;
			i++;
		} else if (strcmp(argv[i], "--file") == 0) {
			file_path = argv[i+1];
			fp_found = true;
			i++;
		}
	}

	if (!kw_found) {
		std::cout << "word not specified" << std::endl;
		return 0;
	}
	if (!fp_found) {
		std::cout << "file path not specified" << std::endl;
		return 0;
	}

	std::freopen(file_path, "r", stdin);
	char* current_word;
	while (std::cin >> current_word) {
		bool good = true;
		for (int i = 0; keyword[i] != '\0'; i++) {
			bool found = false;
			for (int j = 0; current_word[j] != '\0'; j++) {
				if (current_word[j] == keyword[i]) {
					found = true;
					break;
				}
			}
			if (!found) {
				good = false;
				break;
			}
		}
		if (good) {
			std::cout << current_word << ' ';
		}
	}
	std::cout << std::endl;
}
