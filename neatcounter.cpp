#include <iostream>
#include <fstream>
int main(int argc, char** argv) {
  std::ifstream in(argv[4]);

  bool flag1=true,flag2=true;
  char temp1[]="--word",temp2[]="--file";
  for(int i=0;i<6;i++){
    if(argv[1][i]!=temp1[i])
        flag1=false;
  }
  
  for(int i=0;i<6;i++){
    if(argv[3][i]!=temp2[i])
        flag2=false;
  }

  if (!flag1 or !flag2 or !in.is_open()){
    std::cout<<"invalid arguments";
    return 0;
  }

  char words[100][33];
  int cnt=0,siz=sizeof(argv[2])/2,ans=0;

  while(in>>words[cnt++]){}
  for(int i=0;i<cnt;i++){
    bool flag=true;
    for(int j=0;j<siz;j++){
        bool flagSym=false;
        for(int k=0;k<sizeof(words[i])/2;k++)
            if(argv[2][j]==words[i][k])
                flagSym=true;
        if(!flagSym){
            flag=false;
            break;
        }
    }
    if (flag)
        ans+=1;
  }
  std::cout<<ans;
  return 0;
}