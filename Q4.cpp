#include<bits/stdc++.h>
using namespace std;

int bfs_rec(vector<int> employ,vector<int> employ_conflict[],vector<bool>& vis,int n,int start){
    queue<pair<int,int>> q;
    q.push({start,0});
    int val1=0,val2=0;
    while(!q.empty()){
        int emp = q.front().first;
        int cond = q.front().second;
        q.pop();
        if(cond==0){
            val1+=employ[emp];
            vis[emp]=true;
            cond=1;
        }
        else{
            val2+=employ[emp];
            vis[emp]=true;
            cond=0;
        }
        int size = employ_conflict[emp].size();
        for(int i=0;i<size;i++){
            if(vis[employ_conflict[emp][i]]==false){
                q.push({employ_conflict[emp][i],cond});
            }
        }
    }
    return max(val1,val2);
}

int bfs(int ans,vector<int> employ,vector<int> employ_conflict[],vector<bool>& vis,int n){
    int even =0;
    int odd =0;
    bool flag = false;
    int start = -1;
    for(int i=1;i<=n;i++){
        if(vis[i]==false){
            ans+=bfs_rec(employ,employ_conflict,vis,n,i);
        }
    }
    return ans;
}

int main(){
   int n,c;
   cin>>n>>c;

   vector<int> employ_conflict[n+1];
   for(int i=0;i<c;i++){
      int emp1,emp2;
      cin>>emp1>>emp2;
      employ_conflict[emp1].push_back(emp2);
      employ_conflict[emp2].push_back(emp1);
   }
   vector<int> employ(n+1);
   employ[0]=1;
   for(int i=1;i<=n;i++){
     cin>>employ[i];
   }
   int ans = 0;
   vector<bool> vis(n+1,false);
   for(int i=1;i<=n;i++){
      if(employ_conflict[i].size()==0){
          ans += employ[i];
          vis[i]=true;
      }
   }
   cout<<bfs(ans,employ,employ_conflict,vis,n+1);
   
}