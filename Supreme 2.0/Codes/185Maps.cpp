#include<iostream>
#include<unordered_map>

using namespace std;
    
int main(){
    unordered_map<string, int> mapping;

    pair<string, int> p = make_pair("Modi", 143);

    pair<string, int> q("Day", 4);

    pair<string, int> r;
    r.first = "Meloni";
    r.second = 1433;

    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);

    cout<<mapping.size()<<endl;
    cout<<mapping.at("Modi")<<endl;
    cout<<mapping["Meloni"]<<endl;
    cout<<mapping.count("Day")<<endl;
    cout<<mapping.count("Say")<<endl;

    if(mapping.find("Modi") != mapping.end()){
        cout<<"Found."<<endl;
    }
    else
        cout<<" Not Found."<<endl;

    cout<<"Entry is created wwhen we use the sqare bracket : "<<mapping["Rome"]<<endl;
    cout<<mapping.size()<<endl;

    // Print the count of all characters in the given string: 
    string str = "lovebabber";

    unordered_map<char, int> countStrchar;
    for (int i = 0; i < str.length(); i++)
    {
        countStrchar[str[i]]++;
    }
    for(auto i:countStrchar){
        cout<<i.first<<" ->"<<i.second<<endl;
    }

return 0;
}