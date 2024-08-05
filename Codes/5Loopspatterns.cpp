#include <iostream>
using namespace std;

int main()
{
    /* Pattern 1 :
        int n;
        cout << "Enter n";
        cin >> n;

        int i = 1;

        while (i <= n)
        {

            int j = 1;
            while (j <= n)
            {
                cout << "*";
                j = j + 1;
            }
            cout << endl;

            i = i + 1;
        }
    */

    /* Pattern 2 :
        int n;
        cout << "Enter n";
        cin >> n;

        int i = 1;

        while(i<=n) {

            int j = 1;
            while(j<=n) {
                cout << i;
                j = j + 1;
            }
            cout<<endl;
            i = i+1;
        }
        */

    /* Pattern 3 :
        int n;
        cout << "Enter n";
        cin>>n;

        int i = 1;

        while(i<=n) {

            int j =1;
            while(j<=n) {
                cout<<n-j+1;
                j = j + 1;
            }
            cout<<endl;
            i = i + 1;
        }
        return 0;
         */

    /* Pattern 4:
        int n;
        cout << "enter n";
        cin>>n;

        int i = 1;
        int count = 1;
        while(i<=n) {

            int j=1;
            while(j<=n) {
                cout<<count<<" ";
                count = count  + 1;
                j = j + 1;
            }
            cout<<endl;
            i = i +1;

        }
    */

    /* Pattern 5:
        int n;
        cout<<"Enter n";
        cin>>n;

        int row = 1;
        while(row <= n) {

            int col = 1;
            while(col <= row) {
                cout<< row;
                col = col + 1;
            }
            cout<<endl;
            row = row + 1;
        }
        return 0;
    */

    /* Pattern 6:
        int n;
        cout<<"Enter n ";
        cin>>n;

        int row = 1;

        while(row<=n) {

            int col = 1;
            int value = row;
            while(col <= row) {
                cout<<value;
                value = value + 1;
                col = col + 1;
            }
            cout<<endl;
            row = row + 1;
        }

    */

    /* Pattern 7 :

        int n;
        cin>>n;

        int i = 1;

        while(i <= n) {

            int j = 1;
            while(j <= i) {
                cout<<(i-j+1)<<" ";
                j = j + 1;
            }
            cout<<endl;
            i = i + 1;
        }

    */

    /* Pattern 8 :
        int n;
        cout << "Enter n";
        cin>>n;

        int row = 1;
        while(row <= n) {

            int col = 1;

            while(col <= n) {
                char ch = 'A' + row - 1;
                cout<< ch;
                col = col + 1;
            }
            cout<<endl;
            row = row + 1;
        }
        return 0;
    */

    /* Pattern 9 :
        int n;
        cout << "Enter n";
        cin>>n;

        int row = 1;

        while(row <= n) {

            int col = 1;

            while(col <= row) {
                char ch = ('A' + row + col - 2);
                cout<<ch;
                col = col + 1;
            }
            cout<<endl;
            row = row + 1;

        }
        */
    /* Pattern 10 :
         int n;
        cout << "Enter n";
        cin>>n;

        int row = 1;

        while(row <= n) {

            int col = 1;
            char start = 'A' + n - row;
            while(col <= row) {
                cout<< start;
                start = start + 1;
                col = col + 1;
            }
            cout<< endl;
            row = row + 1;
        }
    }
     */

    /*  Pattern 12 :
     int n;
     cout << "Enter n";
     cin>>n;

     int row = 1;

        while(row <= n) {

            //space print karlo
            int space = n - row;
            while(space) {
                cout<<" ";
                space = space - 1;
            }

            //stars print karlo
            int col = 1;
            while( col <= row ) {
                cout<<"*";
                col = col + 1;
            }
            cout<<endl;
            row = row + 1;

        */

    /* Pattern 12 :
        int n;
        cout << "Enter n";
        cin >> n;
        int i = 1;

        while (i <= n)
        {
            int j = 1;
            while (j <= i)
            {
                char ch = ('A' + i + j - 2);
                cout << ch;
                j = j + 1;
            }
            cout << endl;
            i = i + 1;
        }
        */

    /* Pattern 13 :
     int n;
        cout << "Enter n";
        cin >> n;
        int i = 1;

        while (i <= n)
        {
            int j = 1;
            char start = 'A'+ n -i;
            while (j <= i)
            {

                cout << start;
                start = start + 1;
                j = j + 1;
            }
            cout << endl;
            i = i + 1;
        }
    */

/* Pattern 14 :
    int n;
    cout << "Enter n";
    cin >> n;
    int i = 1;

    while (i <= n)
    {
        // Printing the space ;
        int space = n - i;
        while (space)
        {
            cout << " ";
            space = space - 1;
        }
        // Printing the stars;
        int j = 1;
        while (j <= i)
        {
            cout << "*";
            j = j + 1;
        }
        cout << endl;
        i = i + 1;
    }
*/ 

/* Pattern 15 :
    int n;
    cout << "Enter n";
    cin >> n;
    int i = 1;

    while (i <= n)
    {
        int j = n - i + 1;
        while (j)
        {
            cout << "*";
            j = j - 1;
        }
        cout << endl;
        i = i + 1;
    }
    */ 

    int n;
    cout << "Enter n";
    cin >> n;
    int i = 1;

    while (i <= n)
    {

    }