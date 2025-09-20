// Leetcode 950. Reveal Cards In Increasing Order

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> deckRevealedIncreasing(vector<int> &deck)
{
    sort(deck.begin(), deck.end());
    queue<int> q;
    vector<int> ans(deck.size());

    for (int i = 0; i < ans.size(); i++)
        q.push(i);

    for (int i = 0; i < deck.size(); i++)
    {
        ans[q.front()] = deck[i];
        q.pop();
        if (!q.empty())
        {
            q.push(q.front());
            q.pop();
        }
    }
    return ans;
}

int main()
{
    vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
    vector<int> ans = deckRevealedIncreasing(deck);
    cout << "The order of the deck is: ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}