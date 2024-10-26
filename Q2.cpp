#include<bits/stdc++.h>
using namespace std;

void solve(string x,string y,int s,int r){
    int cnt=0,cnt_rev=0;

    int i=0;
    vector<int> vis1(x.length(),0);
    vector<int> vis2(x.length(),0);
    while(i<x.length()){
        int j=0;
        bool flag = false;
        int maxi = INT_MIN;
        int ans = i;
        while(j<y.length()){
            if(x[i]==y[j]){
                i++;
                j++;
                flag = true;
                maxi=max(maxi,i);
            }else{
                i=ans;
                j++;
            }
        }
        if(flag){
            cnt++;
            i=maxi;
        }else{
            i++;
            continue;
        }
        for(int k=ans;k<=i;k++){
            vis1[k]=i-ans+1;
        }
    }
    i=0;
    reverse(y.begin(),y.end());
    while(i<x.length()){
        if(vis1[i]>0){
            i++;
            continue;
        }
        int j=0;
        bool flag = false;
        int maxi = INT_MIN;
        int ans = i;
        while(j<y.length()){
            if(x[i]==y[j]){
                i++;
                j++;
                flag = true;
                maxi=max(maxi,i);
            }else{
                i=ans;
                j++;
            }
        }
        if(flag){
            cnt_rev++;
            i=maxi;
        }else{
            i++;
            continue;
        }
        for(int k=ans;k<=i;k++){
             vis2[k]=max(maxi,vis2[k]);
        }
    }

    for(int i=0;i<x.length();i++){
        if(vis1[i]==0 && vis2[i]==0){
            cout<<"Impossible"<<endl;
            return;
        }
    }
    cout<<cnt<<" "<<cnt_rev;
}

int main(){
    string x,y;
    cin>>x>>y;
    int s,r;
    cin>>s>>r;

   solve(x,y,s,r);
}