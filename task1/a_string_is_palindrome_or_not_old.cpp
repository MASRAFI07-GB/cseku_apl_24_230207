
#include <bits/stdc++.h>
#include<string.h>
using namespace std;
int f(char  s1[])
{
   int l=strlen(s1);
   char s2[100];
   int z=0;
   for(int i=l-1;i>=0;i--)
   {
         s2[z++]=s1[i];
   }
   s2[z]='\0';
   int  a=strcmp(s1,s2);
   if(a==0)
   return 1;
   else return 0;
}
int main()
{
   int n;
   cin>>n;
   char s[n][100];
   for(int i=0;i<n;i++)
   {
      scanf("%s",s[i]);
   }

  for(int i=0;i<n;i++)
  {
      if(f(s[i]))
      cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
  }
  
}
