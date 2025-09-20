#include <iostream>
#include <fstream>

int needhave[('Z' - 'A' + 1) * 2];
int mark[('Z' - 'A' + 1) * 2];

bool isUp(char c){
  return c >= 'A' && c <= 'Z';
}

int main(int argc, char** argv) {
  std::ifstream mycin(argv[4]);

  if (!mycin.is_open()){
    std::cout << "Error\n";
    exit(-1);
  }

  const char* word = argv[2];
  
  int sz = 'a' - 'z' + 1;

  for (int i = 0; i < sizeof(word) / 2; i++){
    char c = word[i];
    int ind;

    //std::cout << c;

    if (isUp(c)) ind = sz + c - 'A';
    else ind = c - 'a';

    needhave[ind]++;
  }
  std::cout << "\n";

  int res = 0;

  
  char nc;
  while (mycin.peek() != EOF){
    nc = mycin.get();
    std::cout << nc;

    if (nc == ' '){
      //std::cout << "Yes\n";
       bool good = 1;
       for (int j = 0; j < ('Z' - 'A' + 1) * 2; j++) {
          if (needhave[j] > mark[j]) {
            good = 0;
          }

          mark[j] =0;
       } 

       if (good) {
        ++res;
       }
    }
    else{
      char c = nc;
    int ind;
    if (isUp(c)) ind = sz + c - 'A';
    else ind = c - 'a';

      mark[ind]++;
    }
  }

  bool good = 1;
       for (int j = 0; j < ('Z' - 'A' + 1) * 2; j++) {
          if (needhave[j] > mark[j]) {
            good = 0;
          }

          //std::cout << mark[j] << " ";
          mark[j] =0;
       } 

       if (good) {
        ++res;
       }

  std::cout << res << "\n";
  mycin.close();

  return 0;
}
