#include<iostream>
using namespace std;

namespace Student{
    int roll_no = 1001;
    string name = "Rohit";

    int add(int a , int b){
        return a+b; 
    }
    struct Demo
    {
       int x;
    };
    class Memo{

        public:
        void show(void){
            cout<<endl<<"I am from student namespace.";
        }
    };
}
int main()
{
    cout<<endl<<"Roll number is "<<Student::roll_no;
    cout<<endl<<"Name  is "<<Student::name;
    cout<<endl<<"Sum is  "<<Student::add(5,8);

    Student::Demo sob;
    sob.x = 1200;
    cout<<endl<<"Value of structure "<<sob.x;
    
    Student::Memo obj;
    obj.show();

    return 0; 
}