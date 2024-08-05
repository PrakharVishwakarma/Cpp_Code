// Letter Combination of Keypad Phone Number.

#include <iostream>
#include <vector>
using namespace std;

void solution(string enterDigits, int index, vector<string> &mapping, string output, vector<string> ans)
{
    if (index >= enterDigits.length())
    {
        ans.push_back(output);
        cout<<output<<endl;
        return;
    }
    if (enterDigits.length() == 0)
    {
        return;
    }

    int digit = enterDigits[index] - '0';
    string value = mapping[digit];
    for (int i = 0; i < value.length(); i++)
    {
        char ch = value[i];
        output.push_back(ch);

        solution(enterDigits, index+1 , mapping, output, ans);

        output.pop_back();
    }
}

int main()
{

    string enterDigits;
    cout << "Enter the digits of the keypad phone : ";
    cin >> enterDigits;
    int index = 0;

    vector<string> ans;

    vector<string> mapping(10);
    mapping[2] = "abc";
    mapping[3] = "def";
    mapping[4] = "ghi";
    mapping[5] = "jkl";
    mapping[6] = "mno";
    mapping[7] = "pqrs";
    mapping[8] = "tuv";
    mapping[9] = "wxyz";

    string output;

    
    solution(enterDigits, index, mapping, output, ans);

    return 0;
}

// Without backtracking , code can be
/*
for (int i = 0; i < value.length(); i++)
    {
     solution(enterDigits, index+1 , mapping, output + ch, ans);
    }
*/