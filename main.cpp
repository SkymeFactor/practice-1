#include <iostream>
#include <fstream>
#include <string>


bool is_equal(const char* s1, const char* s2){
    int i = 0;
    while (*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0'){
        i++;
    }

    if (*(s1 + i) == *(s2 + i)){
        return true;
    } else {
        return false;
    }
}

bool is_word(const char* origin, const char* word){
    bool a[200];
    for (int i = 0; i < 200; i++){
        a[i] = false;
    }
    {
        int i = 0;
        while (word[i] != '\0'){
            a[word[i]] = true;
            i++;
        }
    }
    {
        int i = 0;
        while (origin[i] != '\0'){
            a[origin[i]] = false;
            i++;
        }
    }
    for (int i = 0; i < 200; i++){
        if (a[i]){
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    char* word = nullptr;
    char* file_name = nullptr;
    {
        int i = 1;
        while (i < argc){
            if (is_equal(argv[i], "--word")){
                if (word != nullptr || i + 1 == argc){
                    return 1;
                }
                i++;
                word = argv[i];
            } else if (is_equal(argv[i], "--file")){
                if (file_name != nullptr || i + 1 == argc){
                    return 2;
                }
                i++;
                file_name = argv[i];
            } else {
                return 3;
            }
            i++;
        }
    }

    std::ifstream file(file_name);

    if (!file.is_open()){
        return 4;
    }
    int answer = 0;
    char* line;

    while (file >> line){
        answer += is_word(word, line);
    }

    std::cout << answer << '\n';
    return 0;
}
