//Binary search : element should be in increasing or decreasing order.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


/*
int binarySearch(int arr[] , int size , int key){

    int start = 0;
    int end = size - 1;

    int mid = (start + end)/2;   // eficient : mid = start + (end-start)/2;

 while(start <= end) {

        if(arr[mid] == key) {
            return mid;
        }

        //go to right wala part
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else{ //key < arr[mid]
            end = mid - 1;
        }

        int mid = (start + end)/2;    // eficient(very big values) : mid = start + (end-start)/2;
    }
    return -1;
}
int main(){
    int even[8] = {1,2,3,4,5,6,7,8};
    int odd[7] = {1,2,3,4,5,6,7};
    int key;
    cout<<"Select the element from the array to search ";
    cin>>key;
    int evenIndex = binarySearch(odd , 8, key);
    cout<<"the element is found at index "<<evenIndex<<endl;
*/

// Questions practice :

 /*
int firstOcc(vector<int>& arr, int n, int key) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(arr[mid] == key){
            ans = mid;
            e = mid - 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

int lastOcc(vector<int>& arr, int n, int key) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e) {

        if(arr[mid] == key){
            ans = mid;
            s = mid + 1;
        }
        else if(key > arr[mid]) {//Right me jao
            s = mid + 1;
        }
        else if(key < arr[mid]) {//left me jao
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }
    return ans;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int,int> p;
    p.first = firstOcc(arr, n, k);
    p.second = lastOcc(arr, n, k);
    
    return p;
*/

/*
// Leetcode 852. Peak Index in a Mountain Array
int peakIndexInMountainArray(vector<int>& arr) {
    int n = arr.size();
    int s = 0;
    int e = n-1;
    int mid;
    while (s<e)
    {
        mid = s + (e-s)/2;    
        if(arr[mid] < arr[mid+1]){
            s = mid + 1;
        }
        else{
            e = mid;
        }
    }
return s;
}
*/

/*

// Finding pivot in sorted rotated array;

int getPivot(int arr[], int n) {

    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e) {

        if(arr[mid] >= arr[0])
        {
            s = mid+1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;
}

int main() {
    int arr[5] = {1, 3, 8, 10, 17};
    cout << "Pivot is " << getPivot(arr, 5) << endl;
}
*/

// Finding square root of an element.
/*
 long long int sqrtInteger(int n) {
        
        int s = 0;
        int e = n;
        long long int mid = s + (e-s)/2;
        
        long long int ans = -1;
        while(s<=e) {
            
            long long int square = mid*mid;
            
            if(square == n)
                return mid;
            
            if(square < n ){
                ans = mid;
                s = mid+1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }

double morePrecision(int n, int precision, int tempSol) {
    
    double factor = 1;
    double ans = tempSol;

    for(int i=0; i<precision; i++) {
        factor = factor/10;

        for(double j=ans; j*j<n; j= j+factor ){
            ans = j;
        }
    }
    return ans;
}
*/


/*
//Book allocation problem 
    bool isPossible(vector<int>arr , int n , int m ,int mid){

        int studentCount = 0;
        int pageSum = 0;

        for (int i = 0; i < n; i++)
        {
            if(pageSum + arr[i] <= mid){
                studentCount++;
                pageSum += arr[i];
            }
            else{
                studentCount++;
                if (studentCount > m &&  arr[i] > mid)
                {
                    return false;
                }
                pageSum = arr[i];
            }
        }
    }

    int allocateBook(vector<int>arr , int n , int m){
        int s = 0;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum+=arr[i];
        }
        int e = sum;
        int mid = s+(e-s)/2;

        int ans = -1;
        while (s<=e)
        {
            if(isPossible(arr,n,m,mid)){ 
                ans = mid;
                e = mid - 1;
            } 
            else{
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        return ans;
    }

*/


/*
//Painters partition problem : 
    bool isPossible(vector<int>arr , int n , int k ,int mid){
        int timesum = 0;
        int painterCount = 0;

        for (int i = 0; i < n; i++)
        {
        
            if (timesum+arr[i]<mid){
                painterCount++;
                timesum = arr[i];
            }
            else{
                painterCount++;
                if (painterCount > k &&  arr[i] > mid)
                {
                    return false;
                }
                timesum = arr[i];
            }
            
        } 
    }
    int partition(vector<int>arr , int n , int k){
        int s = 0;
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        int e = sum;
        int mid = s+(e-s)/2;


        int ans = -1;

        while (s<=e)
        {
            if(isPossible(arr,n,k,mid)){ 
                ans = mid;
                e = mid - 1;
            } 
            else{
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        
        return ans;
    }
*/

/*
//Aggresive Cows problem : 

bool isPossible(vector<int>stalls , int k , int mid){

    int cowCount = 1;
    int lastPos = stalls[0];
    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPos >= mid)
        {
            cowCount++;
            if (cowCount==k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
        return false;
    }
    
}

int aggresiveCow(vector<int>stalls , int n , int k){

    int s = 0;


    int e = stalls[ stalls.size() - 1] - stalls[0];
    int mid = s + (e - s)/2;

    int ans = -1;

    while (s <= e)
    {
        if(isPossible(stalls , k , mid)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    int mid = s + (e - s)/2;
    }
return ans;   
}
*/

/* 
// Eko spouj : 

bool isPossible(vector<long long>tree , long long m , long long int mid ){

    long long int woodCollect=0;
    for(int i  =  0 ; i < tree.size() ; i++)
    {
        if(tree[i] > mid){
            woodCollect+=(tree[i] - mid);
        }
    }
    return woodCollect >= m;
}

long long int maxBladeHeight(vector<long long>tree , long long m ){

    long long int s = 0;
    long long e = *max_element(tree.begin() , tree.end());
    long long int ans = -1;
while (s <= e)
    {
        long long int mid = s + (e - s)/2;
        if(isPossible(tree , m , mid)){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    mid = s + (e - s)/2;
    }
return ans;  
}
*/


/*
// Prata spouj :
bool isPossibleSolution(vector<int>cooksRank, int nP, int mid){
    int currP = 0;
    for (int i = 0; i < cooksRank.size(); i++)
    {
        int R = cooksRank[i];
        int j = 1;
        int timeTaken = 0;
        while(true){
            if(timeTaken + j*R <= mid){
                ++currP;
                timeTaken += j*R;
                j++;
            }
            else{
                break;
            }
        }
        if(currP >= nP) return true;
    }
return false;
}

int minTimeToCompleteOrder(vector<int> cooksRank, int nP){
    int start = 0;
    int highestRank = *max_element(cooksRank.brgin(), cooksRank.end());
    int end = highestRank * (nP*(nP+1)/2);
    int ans = -1;
    int mid = s + (e-s)/2;

    while (start<=end)
    {
        if(isPossibleSolution(cooksRank, nP, mid)){
            ans = mid;
            end = mid - 1;
        }
        else start = mid + 1;
    mid = s + (e-s)/2;
    }
    return ans;
}
*/


int main() {
    
    /*
    // Book allocation problem : 
        int n;
        cout <<" Enter the Size " << endl;
        cin >> n;

        int m;
        cout<<"Enter the number of student : ";
        cin>>m;

        cout<<"Now enter the number of pages in book : ";
        vector<int>v(n);

        for (int i = 0; i < n; i++)
        {
        cin>>v[i];
        }

        cout<<"Size of array "<<n<<endl<<" Number of stodent "<<m<<endl;
        cout<<"Answer for book allocation "<<allocateBook(v , n , m) ;
        
        // int tempSol = sqrtInteger(n);
        // cout <<" Answer is " << morePrecision(n, 3, tempSol) << endl;
    */
   
    
    /* 
    // Painters partition problem :  // code is wrong , check and correct.

        // Book allocation problem : 
        int n;
        cout <<" Enter the Size " << endl;
        cin >> n;

        int k;
        cout<<"Enter the number of painters : ";
        cin>>k;

        cout<<"Now enter the taken time to paint : ";
        vector<int>v(n);

        for (int i = 0; i < n; i++)
        {
        cin>>v[i];
        }
        cout<<"Size of array "<<n<<endl<<" number of painters "<<k<<endl;
        cout<<"The minimum time to paint all boards "<<partition(v , n, k) ;
    */


// Aggresive Cows Problem :  min distnce between any two of them is largest possible.
/*
    int n;
        cout <<" Enter the Size of array : " << endl;
        cin >> n;

        vector<int>v(n);

        int k;
        cout<<"Enter the number of cows : ";
        cin>>k;

        cout<<"Now enter the positions of cows in sorted manner : "<<endl;

        for (int i = 0; i < n; i++)
        {
        cin>>v[i];
        }

        cout<<"Minimum distance between cow so that they should not become aggresive is : "<<aggresiveCow(v , n , k);
    
    
*/

/*
// Eko spouj : 

    long long n;
        cout <<" Enter the Number of trees : " << endl;
        cin >> n;

        vector<long long>tree(n);

    long long m;
        cout<<"Enter the required wood lenth : ";
        cin>>m;

        cout<<"Now enter the height of tree in sorted manner : "<<endl;

    while (n--)
    {
        long long int height;
        cin>>height;
        tree.push_back(height);
    }

    cout<<"The minimum lenth of cutting of the tree is "<< maxBladeHeight(tree , m);
*/
    
 
/*
//Prata spouj 
    int T; cin>>T;
    while (T--){
        int nP, nC;
        cin>>nP>>nC;
        vector<int>cooksRank;
        while(nC--){
            int R; cin>>R;
            cooksRank.push_back(R);
        }
        cout<<minTimeToCompleteOrder(cooksRank, nP)<<endl;
    }
*/
    

    return 0;
}


// Binary seach problems : classical problem , Eliminating search space ,predicate function problem , claculation on index problem Index  
 

 // In this section I have done : 
 //Binary search 
/*

firstOcc
lastOcc
peak index in a mountain array
Finding pivot in sorted rotated array;
Finding square root of an element
Book allocation problem 
Painters partition problem
Aggresive Cows problem : 
Aggresive Cows problem
Eko spouj
Prata Spouj
 */