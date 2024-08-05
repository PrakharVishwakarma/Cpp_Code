// Minimum cost for ticket pass :

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int findMinPass(vector<int>&days ,vector<int>&costs , int i ){

//base case :
    if(i>=days.size())return 0;

// One day pass :
    int cost1day = costs[0]+findMinPass(days , costs , ++i);

//Seven day pass :
    int passEndDay = days[i] + 7 - 1;
    int j = i;
    while(j < days.size() && j < passEndDay){
        j++;
    }

    int cost7day = costs[1]+findMinPass(days , costs , j);

// Thirty days pass : 
    passEndDay = days[i] + 30 - 1;
    j = i;
    while(j < days.size() && j < passEndDay) {
        j++;
        }

    int cost30day = costs[2]+findMinPass(days , costs , j);
 
    return min(cost1day , min(cost7day , cost30day));
}


int main(){
    int element;
    int n;
    cout<<"Enter the number of days you want to travel : ";
    cin>>n;
    vector<int>day;
    cout<<"Enter the days in which you want to travel : ";
    for (int i = 0; i < n; i++)
    {
        cin>>element;
        day.push_back(element);
    }
    cout<<"days array is : ";
    for (int i = 0; i < n; i++)
    {
        cout<<day[i]<<" ";
    }
    cout<<endl;

    int m = 3;      // pass schemes are only three one is for OneDayPass second is SevenDayPass ans third is ThirdDayPass. 
    vector<int>cost;
    cout<<"Enter the pass costs respectively  : ";
    for (int i = 0; i < m; i++)
    {
        cin>>element;
        cost.push_back(element);
    }
    cout<<"cost array is : ";
    for (int i = 0; i < m; i++)
    {
        cout<<cost[i]<<" ";
    }
    cout<<endl;
    cout<<"Min Cost for yout entire travel :"<<findMinPass(day , cost , 0);
    return 0;
}