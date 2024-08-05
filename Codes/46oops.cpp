#include<iostream>
#include "Contry.cpp"

using namespace std;

class Hero{
 
    private:
    int strenth;   

    public:
    int capacity;
    string level; 

    int getStrenth(){
        return strenth;
    }
    string getLevel(){
        return level;
    }
    void setStrenth(int s){
        strenth = s;
    }
    void setLevel(string str){
        level = str;
    }

    Hero(){
        cout<<"Consructwer called "<<endl;
    }

    Hero(int capacity , string level){
        cout<<"this -> "<<this<<endl;   //this stores the address of current object.
        this -> level = level; 
        this -> capacity = capacity; 

    }
    Hero(Hero& temp) {
        cout << "Copy constructor called" << endl;
        this->capacity = temp.capacity;
        this->level = temp.level;
    }

     
};

int main()
{
    /*
    Contry nwz;
    cout<<"size of nwz is "<<sizeof(nwz)<<endl;

//  static allocation :
    Hero superman;
    superman.setStrenth(50);
    cout<<"Strenth of superman is "<<superman.getStrenth()<<endl;

//  Dynamically allocation :
    Hero *ironMan = new Hero;
    (*ironMan).setStrenth(51);
    cout<<"Now strenth is "<<(*ironMan).getStrenth();
    */
    Hero thor( 52 ,"moderate");
    cout<<"Address of thor is "<< &thor<<endl;
    cout<<"Capacity is "<<thor.capacity<<endl;
    cout<<"Level of thor is "<<thor.level<<endl<<endl;


    Hero halk(thor);    //Copy Constructor.
    //  It means :
    // halk.capacity=thor.capacity
    // halk.level=thor.level    
    cout<<"Capacity is "<<halk.capacity<<endl;
    cout<<"Level of thor is "<<halk.level<<endl<<endl;

    Hero roman(thor);
    cout<<"Capacity is "<<roman.capacity<<endl;
    cout<<"Level of thor is "<<roman.level<<endl;
}

