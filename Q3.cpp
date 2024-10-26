#include<bits/stdc++.h>
using namespace std;

int pow(int n1,int n2){
    int ans = 1;
    for(int i=1;i<=n2;i++){
        ans = ans*n1;
    }
    return ans;
}

int operation(int n1,int n2,char ch){
    if(ch=='+'){
        return n1+n2;
    }
    if(ch=='-'){
        return n1-n2;
    }
    if(ch=='*'){
        return n1*n2;
    }
    if(ch=='%'){
        if(n2==0){
            return INT_MAX;
        }
        return n1%n2;
    }
    if(ch=='/'){
        if(n2==0){
            return INT_MAX;
        }
        return n1/n2;
    }
    if(ch=='^'){
         return pow(n1,n2);
    }
    return INT_MAX;
}

int generate_num(string s,unordered_map<string,int> num_map){
     int ans = 0;
     string temp = "";
     int n = s.length();
     for(int i=0;i<n;i++){
        if(s[i]=='c'){
            if(num_map.find(temp)!=num_map.end()){
                ans = ans*10+num_map[temp];
            }
            else{
                return -1;
            }
            temp = "";
        }
        else{
            temp += s[i];
        }
     }
     if(num_map.find(temp)!=num_map.end()){
                ans = ans*10+num_map[temp];
            }
    else{
             return -1;
    }

     return ans;
}

void resolve(string s,unordered_map<string,int> num_map,unordered_map<string,char> operation_map){
        string temp = "";
        stack<char> st;
        int n1 = INT_MAX,n2=INT_MAX;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]==' '){
               if(operation_map.find(temp)!=operation_map.end()){
                    st.push(operation_map[temp]);
               }
               else if(num_map.find(temp)!=num_map.end()){
                   if(n1==INT_MAX){
                      n1 = num_map[temp];
                   }else{
                      n2 = num_map[temp];
                      if(st.size()==0){
                        cout<<"expression is not complete or invalid"<<endl;
                        return;
                      }
                      char ch = st.top();
                      st.pop();
                      n1 = operation(n1,n2,ch);
                      if(n1==-1){

                      }
                      n2 = INT_MAX;
                   }
               }
               else{
                   int num = generate_num(temp,num_map);
                   if(num==-1){
                      cout<<"expression evaluation stopped invalid words present"<<endl;
                      return;
                   }
                    if(n1==INT_MAX){
                      n1 = num;
                    }else{
                        n2 = num;
                        if(st.size()==0){
                            cout<<"expression is not complete or invalid"<<endl;
                            return;
                        }
                        char ch = st.top();
                        st.pop();
                        n1 = operation(n1,n2,ch);
                        if(n1==INT_MAX){
                            cout<<"expression is not complete or invalid"<<endl;
                            return;
                        }
                        n2 = INT_MAX;
                    }
               }
               temp = "";
            }
            else{
                temp += s[i];
            }
        }
        if(operation_map.find(temp)!=operation_map.end()){
                    st.push(operation_map[temp]);
               }
               else if(num_map.find(temp)!=num_map.end()){
                   if(n1==INT_MAX){
                      n1 = num_map[temp];
                   }else{
                      n2 = num_map[temp];
                      if(st.size()==0){
                        cout<<"expression is not complete or invalid"<<endl;
                        return;
                      }
                      char ch = st.top();
                      st.pop();
                      n1 = operation(n1,n2,ch);
                      n2 = INT_MAX;
                   }
               }
               else{
                   int num = generate_num(temp,num_map);
                   if(num==-1){
                      cout<<"expression evaluation stopped invalid words present"<<endl;
                      return;
                   }
                    if(n1==INT_MAX){
                      n1 = num;
                    }else{
                        n2 = num;
                        if(st.size()==0){
                            cout<<"expression is not complete or invalid"<<endl;
                            return;
                        }
                        char ch = st.top();
                        st.pop();
                        n1 = operation(n1,n2,ch);
                        n2 = INT_MAX;
                    }
               }
        if(n1==-1){
            cout<<"expression evaluation stopped invalid words present"<<endl;
              return;
         }
         
         cout<<n1;
}

void solve(string s){
    unordered_map<string,int> num_map;
    unordered_map<string,char> operation_map;
    num_map["zero"]=0;
    num_map["one"]=1;
    num_map["two"]=2;
    num_map["three"]=3;
    num_map["four"]=4;
    num_map["five"]=5;
    num_map["six"]=6;
    num_map["seven"]=7;
    num_map["eight"]=8;
    num_map["nine"]=9;

    operation_map["add"]='+';
    operation_map["mul"]='*';
    operation_map["sub"]='-';
    operation_map["rem"]='%';
    operation_map["pow"]='^';
    operation_map["div"]='/';

    resolve(s,num_map,operation_map);
}

int main(){

    string s;
    getline(cin, s); 
    solve(s);
}