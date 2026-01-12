// UID :- 24BCS10109 - Ansh Panwar

#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
int depth = 0;

void complexRec(int n)
{
    if (n <= 2)
    {
        return;
        cnt++;
    }

    int p = n;
    while (p > 0)
    {
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            temp[i] = i ^ p;
            cnt++;
        }
        p >>= 1;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++)
    {
        small[i] = i * i;
        cnt++;
    }

    if (n % 3 == 0)
    {
        reverse(small.begin(), small.end());
        cnt++;
    }
    else
    {
        reverse(small.begin(), small.end());
        cnt++;
    }

    depth++;
    complexRec(n / 2);
    complexRec(n / 2);
    complexRec(n / 2);
}

int main()
{

    int n;
    cin >> n;
    complexRec(n);

    cout << "The number of operations are :- " << cnt << endl;
    cout << "Depth is :- " << depth;
}

/**
 * Recurrence relation :-  T(n) = 3T(n/2) + logn + n + n/2 + n/2 + 1
 * Time complexity :- Using Master's therorem CASE-I is:-   O(nlog2 3)
 */