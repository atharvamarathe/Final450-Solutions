class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string prev = countAndSay(n - 1), ans;
        for (int i = 0; i < prev.size();)
        {
            int j = i + 1;
            for (; j < prev.size() && prev[j] == prev[i]; j++)
                ;
            ans += {char(j - i + '0'), prev[i]};
            i = j;
        }
        return ans;
    }
};