// take some marks of some students and sort their marks in ascending order
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }

    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(v[i]>v[j])
            {
                int temp=v[i];
                v[i]=v[j];
                v[j]=temp;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
}
