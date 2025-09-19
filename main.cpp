#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>

const int UPPER_AND_LOWERCASE_DIF = 'a' - 'A';

bool CompareChars(char ch1, char ch2)
{
  if (ch1 == ch2)
    return true;

  // ch1 - заглавная, ch2 - строчная
  if (ch1 >= 'A' && ch1 <= 'Z' && ch1 + UPPER_AND_LOWERCASE_DIF == ch2)
    return true;
  
  // ch2 - заглавная, ch1 - строчная
  if (ch2 >= 'A' && ch2 <= 'Z' && ch2 + UPPER_AND_LOWERCASE_DIF == ch1)
    return true;
    
  return false;
}

bool CheckWord(char* word, char* main_word)
{
  for (int i = 0; i < strlen(main_word); i++)
  {
    bool flag = false;
    for (int j = 0; j < strlen(word); j++)
    {
      if (CompareChars(word[j],main_word[i]))
      {
        flag = true;
        break;
      }
    }

    if (!flag)
      return false;

  }
  return true;
}

int main(int argc, char** argv)
{
  if (argc < 5)
  {
    std::cerr << "Too few arguments\n";
    return 1;
  }

  if (argc > 5)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }

  if (strcmp(argv[1], "--word") != 0 || strcmp(argv[3], "--file") != 0)
  {
    std::cerr << "Invalid argument format\n";
    return 1;
  }
  char word[33] {0};
  char filename[256] {0};

  strcpy(word, argv[2]);
  strcpy(filename, argv[4]);

  int cnt = 0;

  std::ifstream fin(filename);
  if (fin.is_open())
  {
    char wordf[32];
    while (fin >> wordf)
    {
      if (CheckWord(wordf, word))
        cnt++;
    }
  }
  else
  {
    std::cerr << "Cannot open file\n";
    return 1;
  }
  std::cout << cnt << std::endl;
  fin.close();
  return 0;
}