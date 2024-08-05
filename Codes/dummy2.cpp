#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Creating a vector to store the user input from sender side :
    int n1;
    cout << "Enter the lenth of message send by sender : ";
    cin >> n1;
    vector<int> v1(n1);

    // Prompt the user to enter a series of 0s and 1s in the form of messsage.
    cout << "Enter a message of sender : ";

    // Loop until the user enters a valid value.
    int i = 0;
    while (i < v1.size())
    {
        int input;
        cin >> input;

        // If the input is 0 or 1, add it to the vector.
        if (input == 0 || input == 1)
        {
            v1[i] = input;
        }
        // If the input is not 0 or 1, again take input and add it to the vector.
        else
        {
            cout << "Invalid input. Please enter 0 or a 1 at " << i + 1 << "th position ";
            cin >> input;
            v1[i] = input;
        }
        i++;
    }
    // Displaying sender's message here :

    cout << "Message send by sender is : ";

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }

    int count1 = 0;
    // checking even parity :
    for (i = 0; i < v1.size(); i++)
    {

        if (v1[i] == 1)
        {
            count1++;
        }
        else
        {
            count1 = count1;
        }
    }

    // Creating a vector to store the user input from receiver side :
    vector<int> v2(n1);
    // Loop until the user enters a valid value.
    cout << endl
         << "Enter a message received by receiver : ";
    int j = 0;
    while (j < v2.size())
    {
        int input;
        cin >> input;

        // If the input is 0 or 1, add it to the vector.

        if (input == 0 || input == 1)
        {
            v2[j] = input;
        }

        // else the input is not  0 or 1, again take input and add it to the vector.
        else
        {
            cout << "Invalid input. Please enter 0 or a 1 at " << j + 1 << "th position ";
            cin >> input;
            v2[j] = input;
        }
        j++;
    }

    // Displaying receiver's message here :
    cout << "Message received by receiver is : ";
    for (int i = 0; i < v2.size(); i++)
    {
        cout << v2[i] << " ";
    }

    // checking even parity :
    int count2 = 0;
    for (i = 0; i < v2.size(); i++)
    {

        if (v2[i] == 1)
        {
            count2++;
        }
        else
        {
            count2 = count2;
        }
    }

    // checking the receiver's parity is equal to the sender's parity.
    if (count1 == count2)
    {
        cout << endl
             << "Reciever got right message.";
    }
    else
    {
        cout << endl
             << "Receiver got wrong message.";
    }
    return 0;
}
