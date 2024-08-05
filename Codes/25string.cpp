#include<iostream>
using namespace std;

int getLength(char name[]) {
    int count = 0;
    for(int i = 0; name[i] != '\0'; i++) {
        count++;
    }

    return count;
}
void reverse(char name[], int n) {
    int s=0;
    int e = n-1;

    while(s<e) {
        swap(name[s++], name[e--]);
    }
}

bool checkPalindrome(char a[], int n) {
    int s = 0;
    int e = n-1;

    while(s<=e) {
        if(a[s] != a[e]) 
        {
            return 0;       
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}
char chartoLoewrcase(char ch){
    if(ch >='a' && ch<='z'){
        return ch;
    }
    else{
        char temp = ch - 'A'+'a';
    return temp;
    }
}
int main(){

    cout<<"Enter Your Name here ";
    char name[10] ;   
    cin>>name;

    cout<<"Your name is "<<name<<endl;
    int n =getLength(name);
    cout<<"Size of name is "<<n<<endl;  
    reverse(name,n);
    cout<<"reversed string is "<<name<<endl; 
    // If name = rverse of name then string is pallindrome .
    cout<<"Is String pallindrome or not : "<<checkPalindrome(name,getLength(name))<<endl;

    cout<< "your character is "<< chartoLoewrcase('q')<<endl;
    cout<< "your character is "<< chartoLoewrcase('A');
    cout<<name;

}