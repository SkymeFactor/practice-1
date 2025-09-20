#include <iostream>
#include <fstream>


int StrEql(const char* s1, const char* s2)
{
  int i;
  int j;
  for(i = 0, j = 0; s1[i] != '\0' && s2[j] != '\0'; i++, j++) 
  {
    if(s1[i] != s2[j]) {
      return 0;
    }
  }
  return s1[i] == '\0' && s2[j] != '\0';
}


bool IsAlpha(char c)
{
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}


char ToLower(char c)
{
  if(c >= 'A' && c <= 'Z'){
    return char(c - 'A' + 'a');
  }
  return c;
}


int main(int argc, char** argv) {
  if(argc < 5 || (!StrEql(argv[1], "--word") && StrEql(argv[1], "--file")) ||  (!StrEql(argv[3], "--word") && StrEql(argv[3], "--file")))
  {
    std::cout << "Arguments list error" << std::endl;
    return 1;
  }
  const char* word = argv[2];  //TODO
  unsigned int mask = 0;
  int letters_count = 0;

  for(int i = 0; word[i] != '\0'; i++)
  {
    char c = word[i];
    if(!IsAlpha(c))
    {
      std::cout << "Word must consist only of Latin letters" << std::endl;
    }
    mask |= 1 << (c - 'a');
    letters_count++;
    if(letters_count > 32)
    {
      std::cout << "Word is too long" << std::endl;
      return 1;
    }
  }

  std::ifstream input(argv[4]);
  if(!input)
  {
    std::cout << "Can't open file" << std::endl;
    return 1;
  }

  unsigned int temp_mask = 0;
  bool in_word = false;
  char c;
  int count;
  while(input.get(c))
  {
    if(c == ' ' || c == '\n')
    {
      if(in_word)
      {
        if((temp_mask & mask) == mask)
        { 
          count++;
        }
        temp_mask = 0;
        in_word = false;
      }
    } else{
      in_word = true;
      if(IsAlpha(c))
      {
        c = ToLower(c);
        temp_mask |= 1 << (c - 'a');
      }
    }
  }

  if(in_word)
  {
    if((temp_mask & mask) == mask) 
    {
      count++;
    }
  }
  
  std::cout << count << std::endl;
  
  return 0;
}
