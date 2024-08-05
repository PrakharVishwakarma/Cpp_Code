#include <iostream>
#include<array>
#include<vector> 
#include<deque>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<algorithm>

using namespace std;
int main(){
    /*
    int basic[3] = {1,2,3};
    array<int, 4> a = { 1 , 2 , 5 , 4};

    int size = a.size();

    for(int i = 0 ; i < size ; i++){
        cout<<a[i]<<" ";
    }
   cout<<endl;
    cout<<"Element at 2nd index is "<<a.at(2)<<endl;
    cout<<"First element is "<<a.front()<<endl;
    cout<<"last element is "<<a.back()<<endl<<endl;
*/
/*
//Vector : when we insert size+1 th elments in the vector , it does its size doubled, it is dynamic.

    vector<int> v;
    cout<<"Capacity "<<v.capacity()<<endl;

    v.push_back(1);
    cout<<"Capacity "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"Capacity "<<v.capacity()<<endl;

    v.push_back(3);
     cout<<"Capacity "<<v.capacity()<<endl;

    v.push_back(4);
     cout<<"Capacity "<<v.capacity()<<endl;

    v.push_back(5);
     cout<<"Capacity "<<v.capacity()<<endl;

cout<<"Now the vector is"<<endl;
for(int i : v){
    cout<<i<<" ";
}
cout <<endl;
cout<<"poping one element"<<endl;
v.pop_back();

for(int i : v){
    cout<<i<<" ";
}
cout <<endl;
cout<<"Capacity "<<v.capacity()<<endl;

cout<<"poping one element"<<endl;

v.pop_back();
for(int i : v){
    cout<<i<<" ";

}
cout<<"Capacity "<<v.capacity()<<endl;
cout<<"the size of vector is "<<v.size()<<endl;


cout<<"Creating new vector";

vector<int> a(5,1);
cout<<"printing vector a : ";
for(int i : a){
    cout<<i<<" ";
}
cout<<endl;
cout<<"copying the value of vector a in vector b : ";
vector<int> b(a);
for(int i : b){
    cout<<i<<" ";
}
*/

/*
// Doubly Ended Que (DEQ) :

deque<int> d;  

d.push_front(1);
d.push_back(2);
d.push_back(3);

cout<<"Printing deque : ";

for(int i : d){
    cout<<i<<" ";
}
cout<<endl;

cout<<"Printing first element of doubly ended que :"<<d.at(0)<<endl;
cout<<"First element is "<<d.front()<<endl;
cout<<"last element is "<<d.back()<<endl;
cout<<"Empty or not "<<d.empty()<<endl;

cout<<"before erase ";
for(int i : d){
    cout<<i<<" ";
}

d.erase(d.begin() , d.begin()+1);
//     (yahan se  , yahan tak)

cout<<"after erase ";
for(int i : d){
    cout<<i<<" ";
}
/*
d.pop_back();
for(int i : d){
    cout<<i<<" ";
}
cout<<endl;

d.pop_front();
for(int i : d){
    cout<<i<<" ";
}

*/


    // Doubly Linked List (List)
/*
list<int> l;

l.push_front(1);
l.push_front(2);
l.push_front(3);
for(int i : l){
    cout<<i<<" ";
}
cout<<endl;

l.push_back(0);
for(int i : l){
    cout<<i<<" ";
}
cout<<endl;

l.erase(l.begin());
for(int i : l){
    cout<<i<<" ";
}
 cout<<endl;
 
l.pop_back();
for(int i : l){
    cout<<i<<" ";
}
cout<<endl;
l.pop_front();
for(int i : l){
    cout<<i<<" ";
}
cout<<endl;
cout<<"The size of list is "<<l.size();
*/

    // Stack:
/*
stack<string> s;
s.push("pratham");
s.push("dwitiya");
s.push("tritiya");

cout<<"top element is " << s.top()<<endl;

s.pop();
cout<<"Now the top element is " << s.top()<<endl;
cout<<"The size of stack is "<<s.size();
s.push("tritiya");
cout<<"top element is " << s.top()<<endl;
*/

    // Queue
/*
queue<string> q;

q.push("pratham");
q.push("dwitiya");
q.push("tritiya");
q.push("tritiya");

cout<<"Front Element is "<<q.front()<<endl;
cout<<"The size of queue is "<<q.size()<<endl;
q.pop();
cout<<"Front Element is "<<q.front()<<endl;
cout<<"The size of queue is "<<q.size()<<endl;
*/

    // Priority Queue : 
/*
priority_queue<int> maxi;
maxi.push(4);
maxi.push(3);
maxi.push(5);
maxi.push(1);
maxi.push(2);
cout<<"top element of maxi is "<<maxi.top()<<endl;
cout<<"The size of queue is "<<maxi.size()<<endl;
int n = maxi.size();

for (int i = 0; i < n ; i++)
{
   cout<<maxi.top()<<" ";
   maxi.pop();
}
cout<<endl;

priority_queue<int,vector<int>,greater <int>> mini;

mini.push(5);
mini.push(4); 
mini.push(0);
mini.push(2);
mini.push(3);
cout<<"top element of mini is "<<mini.top()<<endl;



int m = mini.size();
for (int i = 0; i < m; i++)
{
    cout<<mini.top()<<" ";
   mini.pop();
}
cout<<endl;
cout<<"Is empty "<<mini.empty();
*/

    //Set :  every element should be unique.
/*
set<int> s;

s.insert(0);
s.insert(1);
s.insert(5);
s.insert(8);
s.insert(4);
s.insert(6);
s.insert(8);
s.insert(4);
s.insert(6);
s.insert(4);
s.insert(6);
s.insert(8);

for(int i : s){
    cout<<i<<endl;
}
cout<<endl;

set <int>::iterator it = s.begin();

s.erase(it);

for(int i : s){
    cout<<i<<endl;
}
cout<<"is 5 is present in the set "<<s.count(5);

set<int>::iterator itr = s.find(5);

for(auto it = itr; it != s.end(; it++)){
cout<<*it<<" ";
}
cout<<endl;

 */

//Map :
/*
map<int,string> m;
m[1]="Love";
m[2]="Babber";
m[13]="c++";
m.insert({5 , "learning"});

cout<<"Before erase";
for(auto i:m){
    cout<<i.first<<" "<<i.second<<endl;
}

cout<<"finding 13 : "<<m.count(13)<<endl<<endl;

m.erase(13);

cout<<"After erase";
for(auto i:m){
    cout<<i.first<<" "<<i.second<<endl;
}
*/

// Algorithms : Binary search

vector<int>v;

v.push_back(1);
v.push_back(5);
v.push_back(8);
v.push_back(13);
v.push_back(15);
v.push_back(20);

cout<<"Finding 6 "<<binary_search(v.begin(), v.end(), 6)<<endl;
cout<<"Finding 13 "<<binary_search(v.begin(), v.end(), 13)<<endl<<endl;;

cout<<"Lower Bound " <<lower_bound(v.begin(),v.end(),10)-v.begin()<<endl;
cout<<"Upper Bound " <<upper_bound(v.begin(),v.end(),10)-v.begin()<<endl;
cout<<"Before rotating the vector "<<endl;
for(int i:v){
    cout<<i<<" ";
}
cout<<endl;
rotate(v.begin(),v.begin()+1,v.end());

cout<<"After rotating the vector "<<endl;
for(int i:v){
    cout<<i<<" ";
}
cout<<endl;
rotate(v.begin(),v.begin()+2,v.end());
cout<<"Again after rotating the vector "<<endl;
for(int i:v){
    cout<<i<<" ";
}
cout<<endl;
rotate(v.begin(),v.begin()+1,v.end()-1);
cout<<"Again after rotating the vector "<<endl;
for(int i:v){
    cout<<i<<" ";
}
cout<<endl;

int a = 5;
int b = 14;

cout<<"Max "<<max(a,b)<<endl;
cout<<"Min "<<min(a,b)<<endl;
swap(a,b);
cout<<"a is "<<a<<" b is "<<b<<endl;

string s = "abcdefg";
cout<<"string is  " <<s<<endl;
reverse(s.begin(),s.end());
cout<<"string is  " <<s<<endl;

vector<int>p;
p.push_back(4);
p.push_back(2);
p.push_back(6);
p.push_back(1);
p.push_back(3);

sort(p.begin(),p.end());
cout<<"After Sorting : ";
for(int i:p){
    cout<<i<<" ";
}

}