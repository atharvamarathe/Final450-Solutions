// https://medium.com/@rushyab/aggressive-cows-spoj-75a155bfe749

#include <iostream>
#include <algorithm>
using namespace std;
int N, C;
long long A[100000];

bool chk(int x)
{
    int cows_placed = 1, last_pos = A[0];
    for (int i = 1; i < N; i++)
    {
        if ((A[i] - last_pos) >= x)
        {
            if (++cows_placed == C)
                return true;
            last_pos = A[i];
        }
    }
    return false;
}

void solve()
{
    cin >> N >> C;
    for (int i = 0; i < N; i++)
        cin >> A[i];
    sort(A, A + N);

    // binary search
    long long low = 0, high = 1000000000, mid, pos = 0;
    while (high >= low)
    {
        mid = (high + low) / 2;
        if (chk(mid))
        {
            low = mid + 1;
            pos = mid;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << pos << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}