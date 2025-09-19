#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int lengthStr(char* str_arg){
  int ans = 0;
  char* str=str_arg;
  while(*str!='\0'){
    ans++;
    str++;
  }
  return ans;
}
int strCmp(const char* first,const char*second){
  while(*first==*second && *first!='\0' && *second!='\0'){
    first++;
    second++;
  }
  return *first=='\0' && *second=='\0';
}
bool areAllLettersInWord(int* letters1, int* letters2){
  const int length_of_alphabet=26;
  for(int i = 0; i < length_of_alphabet; i++){
    if(letters1[i]!=0 && letters2[i]==0)return false;
  }
  return true;
}
void toLower(char* symbols){
  for(int i = 0; symbols[i]!='\0'; i++){
    if(symbols[i]>='A' && symbols[i]<='Z'){
      symbols[i]=symbols[i]-'A'+'a';
    }
  }
}
int main(int argc, char** argv) {
  char filename[1000]{};
  char word[100]{};
  const char kWordCmd[] {"--word"};
  const char kFileCmd[]{"--file"};
  for(int i = 1; i < argc; i++){
    if(strCmp(kWordCmd,argv[i]) && i+1<argc){
      strcpy(word,argv[i+1]);
    }
    if(strCmp(kFileCmd,argv[i]) && i+1<argc){
      strcpy(filename,argv[i+1]);
    }
    else if(strCmp(kFileCmd,argv[i]) && i+1>=argc){
      cerr << "after --file should be a parameter"<<endl;
      return -1;
    }
    else if(strCmp(kWordCmd,argv[i]) && i+1>=argc){
      cerr << "after --word should be a parameter"<<endl;
      return -1;
    }
  }
  toLower(filename);
  toLower(word);
  if(filename==nullptr || word==nullptr){
    cerr << "not enough parameters"<<endl;
    return -1;
  }
  int letters_of_word[26]{};
  for(int i = 0; i < lengthStr(word); i++){
    letters_of_word[word[i]-97]++;
  }
  fstream input(filename);
  char tmp[1024];
  int answer=0;
  if(input.is_open()){
    while(input >> tmp){
      int letters[26]{};
      for(int i = 0; i < lengthStr(tmp); i++){
        letters[tmp[i]-97]++;
      }
      if(areAllLettersInWord(letters_of_word,letters)){
        answer++;
        cout << tmp<<' ';
      }
    }
  }
  else{
    cerr << "ERROR(tried to open file)";
    return -1;
  }
  cout << answer;
}
