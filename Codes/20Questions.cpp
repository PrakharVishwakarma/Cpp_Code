// Print array in reverse order ;
/*
#include <iostream>
#include <vector>

using namespace std;

vector<int>reverse (vector<int>ve){

    int s = 0; 
    int e = ve.size()-1;

    while (s<=e)
    {
        swap(ve[s],ve[e]);
        s++;
        e--;
    }
return ve; 
}

void printVector(vector<int>pe){
    for (int i = 0; i < pe.size(); i++)
    {
        cout<<pe[i]<<" ";
    }
    
}

int main(){


vector<int> v ;

v.push_back(11);
v.push_back(15);
v.push_back(18);
v.push_back(13);
v.push_back(15);
v.push_back(20);

cout<<"Before reversing ";
printVector(v);
cout<<endl;
vector<int>ans = reverse(v);
cout<<"after reversing  ";
printVector(ans);

}
*/

/*
Merge two sorted array in sorted order .

#include <iostream>
using namespace std;

void merge(int arr1[], int n, int arr2[], int m, int arr3[]) {

    int i = 0, j = 0;
    int k = 0;
    while( i<n && j<m) {
        if(arr1[i] < arr2[j]){
            arr3[k++] = arr1[i++];
        }
        else{
            arr3[k++] = arr2[j++];
        }
    }

    //Jab arr1 ke paas element bache honge toh i < n hoge aur j = m ho jayega, toh arr1 ke element arr3 me dalna padega while loop se            is prakar...
   
    while(i<n) {            
        arr3[k++] = arr1[i++];
    }

    //Jab arr2 ke paas element bache honge toh j < m hoge aur i = n ho jayega, toh arr2 bache ke element arr3 me dalna padega while loop se      is prakar...
    while(j<m) {
        arr2[k++] = arr2[j++];
    }
}

void print(int ans[], int n) {
    for(int i=0; i<n; i++) {
        cout<< ans[i] <<" ";
    }
    cout << endl;
}

int main() {

    int arr1[5] = {1,3,5,7,9};
    int arr2[3] = {2,4,6};

    int arr3[8] = {0};

    merge(arr1, 5, arr2, 3, arr3);

    print(arr3, 8);


    return 0;
}
*/

/*
Move all zeros in right side...

#include <iostream>
#include <vector>

using namespace std;

void moveZeros(vector<int> v)
{
    int i=0;
    for (int j = 0; i < v.size(); j++)
    {
       if(v[j] !=0){
        swap(v[i],v[j]);
        i++;
       }
    }
}
void printVector(vector<int>pe){
    for (int i = 0; i < pe.size(); i++)
    {
        cout<<pe[i]<<" ";
    }
    
}


int main(){
    vector<int>v;

v.push_back(1);
v.push_back(0);
v.push_back(8);
v.push_back(13);
v.push_back(0);
v.push_back(20);

moveZeros(v);
printVector(v);

//Check the following code.
*/

/*
Rotate the array k times .

#include <iostream>
#include <vector>

using namespace std;
    void rotate(vector<int>& nums, int k) {
    // just to practice the modulus approach
      int n = nums.size();
      vector<int> temp(n);
      
      
      for(int i =0;i<n;i++) {
        
        temp[(i+k)%n] = nums[i];
        
      }
      
      
      for(int i=0;i<nums.size();i++) 
      {
        nums[i] = temp[i];
      }
 }
    void printVector(vector<int>pe)
{
    for (int i = 0; i < pe.size(); i++)
    {
        cout<<pe[i]<<" ";
    }
    
}
    
int main (){
    vector<int>v;
v.push_back(1);
v.push_back(0);
v.push_back(8);
v.push_back(13);
v.push_back(0);
v.push_back(20);

printVector(v);
cout<<endl;
rotate(v, 2);
printVector(v);
}
*/

/*
// Check if the array is sorted rotated.

#include <iostream>
#include <vector>

using namespace std;
    bool check(vector<int>& nums) {
        int count = 0;
        for(int i=1;i<nums.size();i++) 
        {
            if(nums[i] < nums[i-1])
                count++;
        }
        if(nums[nums.size()-1] > nums[0])
            count++;
        
        return count<=1;
    }
    void printVector(vector<int>pe)
    {
    for (int i = 0; i < pe.size(); i++)
    {
        cout<<pe[i]<<" ";
    }
    }

int main ()
{
    vector<int>v;
v.push_back(3);
v.push_back(4);
v.push_back(5);
v.push_back(1);
v.push_back(2);       // In place of 2 , if we assign v[5] as v[5] > v[1] , then array is not rotated sorted.


printVector(v);
cout<<endl;
if(check(v)){
    cout<<"Array is rotated sorted ";
}
else{
    cout<<"Array is not rotated sorted";
}
}
*/

/*

Sum of array element 
Example arr 1 : 1 12  3  45
        arr 2 :    5 12   5
        sum   : 2  9  0   0
        */ 
#include <iostream>
#include <vector>

using namespace std;

vector<int> reverse(vector<int> v) {
    
    int s = 0;
    int e = v.size()-1;
    
    while(s<e)
    {
        swap(v[s++], v[e--]);
    }
    return v;
}

vector<void> findArraySum(vector<int> a, int n, vector<int> b, int m) {
	
    int i = n-1;
    int j = m-1;
    vector<int> ans;
    int carry = 0;
    
    while(i>=0 && j>=0) {
        int val1 = a[i];
        int val2 = b[j];
            
        int sum = val1 + val2 + carry;   
        
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }
    
    // first case
    while(i>=0) {
        int sum = a[i] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }
    
     // second case
    while(j>=0) {
        int sum = b[j] + carry;
        carry = sum/10;
        int value = sum%10;
        ans.push_back(value);
        j--;
    }
    
     // second case
    while(carry != 0) {
        int sum = carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
    }
    
    //print(ans);
    reverse(ans);
}
int main (){

    vector<int>v;
v.push_back(1);
v.push_back(12);
v.push_back(3);
v.push_back(45);

    vector<int>u;
u.push_back(5);
u.push_back(12);
u.push_back(5);

cout<<" "<<findArraySum(v , 4 , u , 3);
}
 