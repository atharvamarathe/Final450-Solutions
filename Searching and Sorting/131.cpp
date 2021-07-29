#include <bits/stdc++.h>
using namespace std;
int test, parata, cook, rnk[10000], cnt, i;
bool check(int t)
{
    cnt = 0;
    for (i = 0; i < cook; i++)
    {
        cnt = cnt + ((-1) + sqrt(1 + 8 * t / rnk[i])) / 2;
        if (cnt >= parata)
            return true;
    }
    return false;
}
int main()
{

    scanf("%d", &test);
    while (test--)
    {
        scanf("%d%d", &parata, &cook);
        for (i = 0; i < cook; i++)
            cin >> rnk[i];
        int hi = 10000000, lo = 0, mid;
        while (hi > lo)
        {
            mid = (hi + lo) / 2;
            if (check(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        cout << lo << endl;
    }
    return 0;
}