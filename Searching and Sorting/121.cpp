#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<pair<long long int, long long int>> v;
        for (int i = 0; i < n; i++)
        {
            long long int x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }

        sort(v.begin(), v.end());
        int idx = 0;

        for (int i = 1; i < v.size(); i++)
        {
            if (v[idx].second >= v[i].first)
                v[idx].second = max(v[idx].second, v[i].second);
            else
            {
                idx++;
                v[idx] = v[i];
            }
        }

        while (q--)
        {
            long long int k;
            cin >> k;
            long long int ans = -1;
            for (int i = 0; i <= idx; i++)
            {
                if (v[i].second - v[i].first >= k)
                {
                    ans = v[i].first + k - 1;
                    break;
                }
                else
                {
                    k = k - (v[i].second - v[i].first + 1);
                }
            }

            cout << ans << endl;
        }
    }

    return 0;
}