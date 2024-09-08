#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
vector<int>adj[N];

int main(){
  int n;
  cin>>n;
  int n1=n-1;
  while(n1--){
      int u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
  }

  vector<int>given_bfs(n);
  for(int i=0;i<n;i++)cin>>given_bfs[i];

 
  

if(given_bfs[0]!=1)cout<<"NO";
else {
  bool flag=true;
  int flag1=0;
  int ls,le;
  vector<int>vis1(N,0);
  vis1[1]=1;
  for(int i=0;i<n;i++){
    int s=adj[given_bfs[i]].size();
    
    for(auto it:adj[given_bfs[i]]){
           if(vis1[it]==1){
            s--;
           }
    }


    if(flag1==0){
       ls=i+1;
       flag1=1;
    }
    else if(flag1==1){
      ls=le+1;
    }

     le=ls+s-1;
   
    map<int,int>m;
    for(int j=ls;j<=le;j++){
      
      m.insert({given_bfs[j],1});
     
    }

    

    for(auto it:adj[given_bfs[i]]){
      if(vis1[it]==0){
        vis1[it]=1;
            if(m[it]!=1){
          flag=false;
          break;
         }
      }
        
    }


    if(flag==false)break;
    if(le==n-1)break;

  }


   
  if(flag==false)
  cout<<"NO";
  else cout<<"YES";

   
}


  



}
