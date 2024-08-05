
#include<iostream>
#include<vector>

using namespace std;

int countDevices(string &row){
    int count = 0;
    for(auto isLaser: row) count += isLaser - '0';
    return count;
}
int numberOfBeams(vector<string>& bank) {
    vector<int>devices;
    for(auto row: bank) devices.push_back(countDevices(row));   
    int beams = 0;
    for (int i = 0; i < devices.size(); i++)
    {
        int j = i+1;
        while (j<devices.size())
        {
            beams+=devices[i]*devices[j];
            if(devices[j]==0) j++;
            else break;
        }
    }
return beams;
}

int main(){
    vector<string> bank = {"000","111","000"};
    cout<<"the total number of laser beams in the bank : "<<numberOfBeams(bank)<<endl;
return 0;
}