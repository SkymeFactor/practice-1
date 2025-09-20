#include <iostream>
#include <fstream> 
#include <cstring>

void Reset(int* a,int r)
{
  for(int i = 0;i < r;i++)
  {
    *(a+i)=0;
  }
  return;
}

int main(int argc, char *argv[]) {

  if(argc<5) return 2;

  char *world = NULL;
  char *file = NULL;

  if(strcmp(argv[1],"--word")==0) world = argv[2];
  if(strcmp(argv[3],"--file")==0) file = argv[4];
  if(world == NULL || file == NULL) {return 1;}
  
  std::ifstream in(file);

  int st[300],st2[300];
  Reset(&st2[0], 300);
  bool h=0;
  char ch;
  int coll=0;

  for(auto i=world;*i != '\0'; i++)
  {
    st2[*i]++;
  }

  while(in.get(ch))
  {
      if((ch==' ' || ch=='\n') && h==1) {
      h=0;
      bool g=1;
      for(int i = 0;i<300;i++) 
      {
        if(st2[i]>0)
        {
          if(st[i]>0){}
          else {g=0;break;}
        }
      }
      if(g) coll++;
      Reset(&st[0],300);
    }
    else if(ch==' ' || ch=='\n') {}
    else if(ch!=' ' && ch!='\n' && h==0) {h=1;st[(int)ch]++;}
    else {st[(int)ch]++;}
  }

  std::cout << coll;
}
