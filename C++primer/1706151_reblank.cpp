#include<iostream>
using namespace std;
void reblank(char str[],int len)
{
    if(str==NULL&&len<0)return;
    int orilen=0,numbla=0;
    for(int i=0;str[i]!='\0';++i)
    {
        ++orilen;
        if(str[i]==' ')++numbla;
        ++i;
     }
     int newlen=orilen+numbla*2;
     if(newlen>len)return;
     int pori=orilen;
     int pnew=newlen;
     while(pori>=0&&pnew>pori)
     {
        if(str[pori]==' ')
        {
            str[pnew--]='0';
            str[pnew--]='2';
            str[pnew--]='%';
        }
        else str[pnew--]=str[pori];
        --pori;
      }
}
int main()
{
    char str[30]="ha ha ha ha ha ";
    reblank(str,30);
    cout<<str<<endl;
    return 0;
}
