#include "judge.h"

int main()
{
 char a[100]={"test.exe"};
 //system("cd puzzles/code/test");
 //system(a);
 std::vector<bool> res;
 Judge("test",&res);
 for(int i=0;i<res.size();i++)
     {
      fprintf(stderr,"Test number %d.....%s\n",i,res[i]?"Passed":"Failed");
     }
 return 0;
}
