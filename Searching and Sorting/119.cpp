// Write your code here
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void bishu(vector<int> soliders, int power)
{
    int idx;
    int i = 0;
    while (i < soliders.size() && power >= soliders[i])
        i++;

    int sum = 0;
    int count = 0;
    for (int j = 0; j < i; j++)
    {
        sum += soliders[j];
        count++;
    }
    cout << i << " " << sum << endl;
    return;
}

int main()
{

    int n;
    cin >> n;
    vector<int> soliders;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        soliders.push_back(temp);
    }
    sort(soliders.begin(), soliders.end());
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int power;
        cin >> power;
        bishu(soliders, power);
    }
    return 0;
}