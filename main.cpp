#include <iostream>
#include <fstream>

bool check(char* str_1, char* str_2)
{
    int i = 0;
    while((str_1[i] >= 65 && str_1[i] <= 122 && str_2[i] >= 65 && str_2[i] <= 122) || str_1[i] == 45 || str_2[i] == 45)
    {
        if(str_1[i] != str_2[i]) return false;
        i++;
    }
    return true;
}

int main(int argc, char* argv[]) {

    char word[34]{'\0'};
    int word_len = 0;
    char file_name[100]{'\0'};
    if(argc >= 2)
    {
        for(int i=1; i<4; i++)
        {
            if(check(argv[i], "--word")) 
            {
                int j = 0;
                while(argv[i+1][j] >= 65 && argv[i+1][j] <= 122)
                {
                    word_len++;
                    word[j] = argv[i+1][j];
                    j++;
                }
            }
            else if(check(argv[i], "--file"))
            {
                int j = 0;
                while((argv[i+1][j] >= 65 && argv[i+1][j] <= 122) || (argv[i+1][j] >= 48 && argv[i+1][j] <= 57) || argv[i+1][j] == '.')
                {
                    file_name[j] = argv[i+1][j];
                    j++;
                }

                std::ifstream file;
                file.open((const char*) file_name);
                
                int letters_check[word_len];
                for(int l=0; l<word_len; l++) letters_check[l] = 0;

                int word_cout = 0;
                char letter = ' ';
                while(file.get(letter)) 
                {
                    if(letter >= 65 && letter <= 122)
                    {
                        for(int l=0; l<word_len; l++) 
                        {
                            if((letter == word[l]) || (letter <= 90 && letter+32 == word[l]) || (letter >= 97 && letter-32 == word[l])) letters_check[l]++; // заглавные и строчные буквы приравниваются
                        }
                    }
                    else if(letter == ' ' || letter == '\n')
                    {
                        word_cout++;
                        for(int l=0; l<word_len; l++) 
                        {
                            if(letters_check[l] == 0)
                            {
                                word_cout--;
                                break;
                            }
                        }
                        for(int l=0; l<word_len; l++) letters_check[l] = 0;
                    }
                }

                file.close();

                std::cout << word_cout << std::endl;
            }
            else if(argv[i][0] == '-' && argv[i][1] == '-') std::cout << "Error: wrong argument" << std::endl;
        }
    }
    else std::cout << "Error: not enough arguments was given" << std::endl;

    return 0;
}
