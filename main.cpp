#include <iostream>
#include <fstream>
#include <string>


const int MAX_CHAR = 256;
bool prepare_str(const char* s){
    if (s == nullptr){
        return false;
    }
    {
        int i = 0;
        while (s[i] != '\0'){
            if (s[i] < 0 || s[i] >= MAX_CHAR){
                return false;
            }
            i++;
        }
    }
    return true;
}
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
    if (!prepare_str(word) || !prepare_str(origin)){
        return false;
    }
    bool a[MAX_CHAR];
    for (int i = 0; i < MAX_CHAR; i++){
        a[i] = false;
    }
    {
        int i = 0;
        while (origin[i] != '\0'){
            a[origin[i]] = true;
            i++;
        }
    }
    {
        int i = 0;
        while (word[i] != '\0'){
            a[word[i]] = false;
            i++;
        }
    }
    for (int i = 0; i < MAX_CHAR; i++){
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
            if (!prepare_str(argv[i])){
                return 5;
            }
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
