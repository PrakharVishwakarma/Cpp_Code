// Leetcode 2327 : Number of People Aware of a Secret

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int peopleAwareOfSecret(int &n, int &delay, int &forget){
    const int M = 1e9 + 7;
    queue<pair<int, int>> forgetQ, delayQ;
    // {day, count}
    int active = 0;
    // number of people currently able to share the secret.
    int ans = 1;
    // total number of people who still know the secret.

    delayQ.push({1, 1});
    forgetQ.push({1, 1});

    for (int i = 1; i <= n; i++)
    {
        // Step 1 : Active spreader and person who know about secret
        if (!forgetQ.empty() && forgetQ.front().first + forget <= i)
        {
            auto front = forgetQ.front();
            forgetQ.pop();
            auto numberOfPeople = front.second;
            active = (active - numberOfPeople + M) % M;
            ans = (ans - numberOfPeople + M) % M;
        }

        // Step 2 : make new active spreader
        if (!delayQ.empty() && delayQ.front().first + delay <= i)
        {
            auto front = delayQ.front();
            delayQ.pop();
            active = (active + front.second) % M;
        }

        // Step 3 : spread the secret
        if (active > 0)
        {
            ans = (ans + active) % M;
            delayQ.push({i, active});
            forgetQ.push({i, active});
        }
    }
    return ans;
}

int main()
{
    int n = 6, delay = 2, forget = 4;
    cout << " people Aware Of Secret " << peopleAwareOfSecret(n, delay, forget);

    return 0;
}