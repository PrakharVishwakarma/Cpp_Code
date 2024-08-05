
#include<iostream>
using namespace std;

bool checkEvenOdd(int num){
	return num & 1;
}

int main(){

	//signed toh half kar dega but unsigned nahi kar payega.
	/*
	unsigned int num;
	cout<<"Enter the Number ";
	cin>>num;
	cout<<num<<endl;
	cout<< (num >> 1)<<endl;
	
	unsigned int a = -40;
	cout<<a<<endl;
	*/

	/* Garbage value:

	int num = 10;
	cout<<(num >> -1);
	cout<<(num << -1);
	*/

	/*
	int number;
	cout<<"Enter the number : ";
	cin>>number;

	if(checkEvenOdd(number)){
		cout<<"Odd.";
	}
	else{
		cout<<"Even.";
	}
	*/
	
	/*
	int num = 10;
	int* ptr = &num;
	cout<<ptr<<endl;
	cout<<&(ptr);
	*/


	/*
	char ch[10] = "Babber";
	// for (int i = 0; i < sizeof(ch)/sizeof(char); i++)
	// {
	// 	cout<<ch[i];
	// }
	char* ptr = ch;
	cout<<&ch[0]<<endl;
	cout<<*ptr;
	*/

	int arr[10] = {1,5,1,8,54,54,2452,24,24,9};

	int *ptr = arr;
	cout<<&(arr)<<endl;
	cout<<&arr[0]<<endl;
	cout<<ptr;

	return 0;
}

