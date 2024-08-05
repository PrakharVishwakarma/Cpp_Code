/* Custom camparator in inbuilt sort function. */

#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(char first , char second){
    return first > second;          // bada character pehle.
}                                   //H.W. : help ramu question.

int main(){

    string str = "aAbAcC";
    cout <<endl<<str;

    sort(str.begin(), str.end());
    cout << endl<< str << endl;

    sort(str.begin(), str.end() , cmp);
    cout << str << endl;

return 0;
}

