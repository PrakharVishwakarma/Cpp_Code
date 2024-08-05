#include <bits/stdc++.h>

using namespace std;

int main()
{
     int profit[10],dead_line[10];int maximum_profit=0,n,temp;
     cout<<"Enter Number Of Jobs"<<endl;
     cin>>n;
     bool box[n];

     for(int i=0; i<n; i++){
        cout<<"Enter the profit and deadlines of job "<< i+1 <<" repectively : " <<endl;
        cin>>profit[i]>>dead_line[i];
     }

     for(int i=0; i<n-1; i++){
       for(int j=i+1; j<n; j++)

        if(profit[i]<profit[j]){
 
            temp = profit[i];
            profit[i] = profit[j];
            profit[j] = temp;

            temp = dead_line[i];
            dead_line[i] = dead_line[j];
            dead_line[j] = temp;

         }
     }

      cout<<"After Sorting"<<endl;
       for(int i=0; i<n; i++){
          cout<<profit[i]<<" "<<dead_line[i]<<endl;
       }

       memset(box,false,sizeof(box));
        for(int i=0; i<n; i++){
            for(int j=min(n,dead_line[i])-1; j>=0; j--){
                if(box[j]==false){
                      box[j]=true;
                maximum_profit +=profit[i];
                  break;
                }
            }
        }
        cout<<"Maximum Profit: "<<maximum_profit<<endl;
    return 0;
}