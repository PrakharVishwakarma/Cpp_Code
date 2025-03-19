// Leetcode 853

/*

There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.

You are given two integer array position and speed, both of length n, where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.

*/
#include<iostream>
#include<vector> 
#include <algorithm> 
#include <stack> 

using namespace std;


class Car{
public:
    int pos;
    int spd;
    Car(int p, int s):pos(p), spd(s){};
};

static bool myComp(Car &a, Car &b){
    return  a.pos < b.pos;
}

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    vector<Car> cars;
    for(int i = 0; i < position.size(); i++){
        cars.push_back(Car(position[i], speed[i]));
    } 
    sort(cars.begin(), cars.end(), myComp);

    stack<double> st;
    for(auto car : cars){
        float currKaTime = (float)(target - car.pos) / car.spd; 
        while (!st.empty() && currKaTime >= st.top()) st.pop();
        
        st.push(currKaTime);
    } 
return st.size();
}


int main(){
    vector<int> position = {10,8,0,5,3};
    vector<int> speed = {2, 4, 1, 1, 3};
    int target = 12;

    cout<<"The number of car fleets that will arrive at the destination "<<carFleet(target, position, speed);


return 0;
}



// Solution 2 

/*
public:
    class Car {
    public:
        int pos;
        int spd;
        Car(int pos, int spd) : pos(pos), spd(spd) {};
    };

    static bool myComp(Car &a, Car &b) {
        return a.pos > b.pos; 
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        for (int i = 0; i < position.size(); i++) cars.push_back(Car(position[i], speed[i]));
        
        sort(cars.begin(), cars.end(), myComp); 

        stack<double> fleets;
        for (auto car:cars) {
            double time = (double)(target - car.pos) / car.spd;
            if (fleets.empty() || time > fleets.top()) fleets.push(time);   
        }
        return fleets.size();
    }
*/
