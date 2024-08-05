// Leetcode 71 : Simplify Path.

#include<iostream>
#include<stack>

using namespace std;

void buildAns(stack<string>&st , string &ans){
    if (st.empty())return;
    string minpath = st.top();st.pop();
    buildAns(st,ans);
    ans += minpath;
}

string simplifyPath(string &path){
    stack<string>st;
    int i = 0;
    while (i < path.size())
    {
        int s = i;
        int e = i+1;
        while (e<path.size() && path[e] != '/')
        {
            e++;
        }
        string minPath = path.substr(s,e-s);
        i = e;
        if (minPath == "/" || minPath == "/.") continue;
        if (minPath != "/..") st.push(minPath);
        else if(!st.empty()) st.pop();   
    }
    string ans = st.empty() ? "/" : "";
    buildAns(st,ans);
return ans;
}

int main(){
    string path = "/a/.b/../../c/";
    cout<<simplifyPath(path)<<endl;

return 0;
}