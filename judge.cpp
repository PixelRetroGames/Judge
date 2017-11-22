#include "judge.h"
#include "windows.h"
#include <cstring>

void reverse(char s[]);

void itoa(int n, char s[])
{
 int i,sign;
 if((sign=n)<0)
     n=-n;
 i=0;
 do
   {
    s[i++]=n%10+'0';
   }
 while((n/=10)>0);
 if(sign<0)
    s[i++]='-';
 s[i]='\0';
 reverse(s);
}

void atoi(int &n,char s[])
{
 n=0;
 int x=strlen(s);
 for(int i=0;i<x;i++)
     {
      n=n*10;
      n+=(int)(s[i]-'0');
     }
}

void reverse(char s[])
{
 int i,j;
 char c;
 for(i=0,j=strlen(s)-1;i<j;i++,j--)
     {
      c=s[i];
      s[i]=s[j];
      s[j]=c;
     }
}

void Copy_files(char *source,char *destination)
{
 FILE *source_file,*destination_file;
 source_file=fopen(source,"r");
 destination_file=fopen(destination,"w");
 char buffer[TEXT_LENGTH_MAX];
 while(!feof(source_file))
       {
        fgets(buffer,sizeof buffer,source_file);
        fputs(buffer,destination_file);
       }
 fclose(source_file);
 fclose(destination_file);
}

void Judge(char *_name,std::vector<bool> *tests_results)
{
 char path[TEXT_LENGTH_MAX];
 strcpy(path,"puzzles/code/");
 strcat(path,_name);
 strcat(path,"/info.txt");
 FILE *in=fopen(path,"r");
 int number_of_tests;
 fscanf(in,"%d ",&number_of_tests);
 fclose(in);
 strcpy(path,"puzzles/code/");
 strcat(path,_name);
 strcat(path,"/");
 char aux[TEXT_LENGTH_MAX];
 strcpy(aux,"cd ");
 strcat(aux,path);
 system(aux);
 strcpy(aux,path);
 strcat(aux,_name);
 strcat(aux,".out");
 freopen(aux,"w",stdout);
 for(int i=0;i<number_of_tests;i++)
     {
      char aux1[TEXT_LENGTH_MAX];
      strcpy(aux,path);
      strcat(aux,_name);
      itoa(i,aux1);
      strcat(aux,aux1);
      strcat(aux,".in");
      freopen(aux,"r",stdin);

      strcpy(aux,path);
      strcat(aux,_name);
      strcat(aux,".out");
      freopen(aux,"w",stdout);

      strcpy(aux,_name);
      strcat(aux,".exe");
      system(aux);
      fclose(stdout);

      strcpy(aux,path);
      strcat(aux,_name);
      itoa(i,aux1);
      strcat(aux,aux1);
      strcat(aux,".ok");
      strcpy(aux1,path);
      strcat(aux1,_name);
      strcat(aux1,".out");
      tests_results->push_back(Compare_files(aux,aux1));
     }
}

bool Compare_files(char *first_filename,char *second_filename)
{
 FILE *file1,*file2;
 file1=fopen(first_filename,"r");
 file2=fopen(second_filename,"r");
 char buffer1[TEXT_LENGTH_MAX],buffer2[TEXT_LENGTH_MAX];
 bool verdict=true;
 while(!feof(file1) || !feof(file2))
       {
        memset(buffer1,0,sizeof buffer1);
        memset(buffer2,0,sizeof buffer2);
        fgets(buffer1,sizeof buffer1,file1);
        fgets(buffer2,sizeof buffer2,file2);
        if(!Compare(buffer1,buffer2))
           verdict=false;
       }
 fclose(file1);
 fclose(file2);
 return verdict;
}

bool Compare(char *first,char *second)
{
 int i,j;
 i=j=0;
 bool verdict=true;
 while(first[i]!=NULL && second[j]!=NULL && verdict)
       {
        while(first[i]==' ' && first[i+1]==' ')
              i++;
        while(second[j]==' ' && second[j+1]==' ')
              j++;
        if(first[i]!=second[j])
           verdict=false;
        i++;
        j++;
       }
 return verdict;
}
