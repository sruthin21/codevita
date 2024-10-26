#include<bits/stdc++.h>
using namespace std;

int bfs(int src_x,int src_y,int dest_x,int dest_y,int mov_x,int mov_y,vector<vector<int>> matrix){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{src_x,src_y}});
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<bool>> vis(m,vector<bool>(n,false));
    vis[src_x][src_y]=true;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int moves = it.first;
        int x1 = it.second.first;
        int y1 = it.second.second;
        vis[x1][y1]=true;
        if(x1==dest_x && y1==dest_y){
            return moves;
        }
        vector<int> x_cor = {mov_x,-1*mov_x,mov_y,-1*mov_y};
        vector<int> y_cor = {mov_y,-1*mov_y,-1*mov_x,mov_x};

        for(int i=0;i<4;i++){
            int new_x = x1+x_cor[i];
            int new_y = y1+y_cor[i];

            if(new_x>=0 && new_x<m && new_y>=0 && new_y<n){
                 if(matrix[new_x][new_y]==0 && vis[new_x][new_y]==false){
                    pq.push({moves+1,{new_x,new_y}});
                 }
            }
        }
    }
    return 0;
}
 
int solve(){
   int m,n;
    cin>>m>>n;
    vector<vector<int>> matrix(m,vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
             cin>>matrix[i][j];
        }
    }
    int src_x,src_y;
    cin>>src_x>>src_y;
    int dest_x,dest_y;
    cin>>dest_x>>dest_y;
    int mov_x,mov_y;
    cin>>mov_x>>mov_y;
    return bfs(src_x,src_y,dest_x,dest_y,mov_x,mov_y,matrix);
}

int main(){
    cout<<solve()<<endl;
}