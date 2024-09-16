
#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n, k;
   cin >> n >> k;
   vector<int> v(n);
   for (auto &it : v)
      cin >> it;
   while (k--)
   {
      int ele;
      cin >> ele;
      if (ele <= v[0])
      {
         cout << "1" << endl;
         continue;
      }
      else if (ele > v[n - 1])
      {
         cout << n+1 << endl;
         continue;
      }
      int st = 0, end = n - 1, mid;
      int flag = 0;
      int cnt = 0;
      int size = 0;
      while (st <= end)
      {
         mid = st + (end - st) / 2;
         if (ele < v[mid])
         {
            end = mid - 1;
            if ((end >= 0 && end <= (n - 1)) && v[end] < ele)
            {
               size = mid + 1;
               break;
            }
         }
         else if (ele > v[mid])
         {
            st = mid + 1;
            if ((st >= 0 && st <= (n - 1)) && v[st] > ele)
            {
               size = st + 1;
               break;
            }
         }
         else
         {      
            size = mid + 1;
            for (int j = mid -1 , k = st; j >= st && k <= mid - 1; j--, k++)
            {
               if (v[j] != ele)
               {
                  size = j+2;
                  break;
               }
               else if (v[k] == ele)
               {
                  size=k+1;
                  break;
               }
            }
            break;
         }
      }

      cout << size << endl;
   }
}
