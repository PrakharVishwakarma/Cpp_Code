#include <iostream>
#include <cstring>

using namespace std;

char getMaxOcc(string s){

int arr[26] = {0};

//Creting thr array of count :
for(int i = 0 ; i < s.length(); i++)
{
    char ch = s[i];
    int number = 0;
    if(ch >='a' && ch <= 'z')
    {
        number = ch - 'a';
    }
    else{
        number = ch - 'A';
    }
    arr[number]++;
}

// find max occurence element :
int maxi = -1; 
int ans = 0;
for(int i = 0 ; i<26; i++){
    if (maxi<arr[i]){
            ans = i;
            maxi = arr[i];
    }
    char finalAns = 'a'+ans;
return finalAns;
    
}
}

int main(){
    string s;
    cout<<"Enter string s ";
    getline(cin , s);;
    cout<<"Maximum Occurence in string "<< s << " is "<<getMaxOcc(s)<<endl;

    char str1[] = "Prakhar"; 
    char str2[] = "Vishwakarma"; 
    cout<<str1<<endl<<str2<<endl; 
    cout << "Length of the given string is "<< strlen(str1) << endl;
    cout<<strcmp(str1 , str2)<<endl;
    cout<<strcpy(str1 , str2);
} 