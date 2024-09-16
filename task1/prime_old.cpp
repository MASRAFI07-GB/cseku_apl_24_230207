
#include <bits/stdc++.h>
using namespace std;
int f(int ele)
{
   int flag=0;
   for(int i=2;i<=sqrt(ele);i++)
   {
      if(ele%i==0)
      {
         return 0;
      }
   }

   return 1;
}

int sum(int ele)
{
   int sum=0;
   while(ele>0)
   {
      sum+=(ele%10);
      ele/=10;
   }

   return sum;
}

int main()
{
   int n;
   cin>>n;
   vector<int>v(n);
   for(auto &it:v)cin>>it;
   for(int i=0;i<n;i++)
   {
      int ele=v[i];
      if(f(ele))
      {
         v[i]=sum(ele);
      }
   }

   for(int i=0;i<n;i++)
   cout<<v[i]<<" ";
}
