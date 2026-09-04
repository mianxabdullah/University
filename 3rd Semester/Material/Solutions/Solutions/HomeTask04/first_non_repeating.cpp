#include <iostream>
#include <vector>
#include "Queue.h"

using namespace std;

struct Pair
{
    char alpha;
    int index;
};

int first_non_repeating(string s)
{
    vector<int> freq(26, 0);
    myQueue<Pair> q;

    for (int i = 0; i < s.size(); i++)
    {
        Pair temp;
        freq[s[i] - 'a']++;
        temp.alpha = s[i];
        temp.index = i;
        q.enqueue(temp);

        while (!q.isEmpty() && freq[q.queueFront().alpha - 'a'] > 1)
        {
            q.dequeue();
        }
    }

    return q.isEmpty() ? -1 : q.queueFront().index;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;
    int ans = first_non_repeating(s);
    cout << ans;
}