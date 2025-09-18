#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <cstring>


bool CheckWord(char* word, char* MainWord)
{
  for (int i = 0; i < strlen(MainWord); i++)
  {
    bool flag = false;
    for (int j = 0; j < strlen(word); j++)
    {
      if (word[j] == MainWord[i])
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