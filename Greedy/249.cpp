#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'boardCutting' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY cost_y
 *  2. INTEGER_ARRAY cost_x
 */

int boardCutting(vector<int> cost_y, vector<int> cost_x) {
    
    int m = cost_y.size();
    int n = cost_x.size();
    int vertical = 1;
    int horizontal = 1;
    long cost = 0;
    
    vector<pair<long,char>>v;
    for(int i=0;i<cost_y.size();i++) {
        v.push_back(make_pair((long)cost_y[i],'y'));
    }
    for(int i=0;i<cost_x.size();i++) {
        v.push_back(make_pair((long)cost_x[i],'x'));
    }
    
    sort(v.begin(),v.end(),greater<pair<long,char>>());
    for(int i = 0;i<v.size();i++) {
        if(v[i].second == 'y') {
            // printf("The element is %d and %c\n",v[i].first,v[i].second);
            vertical+=1;
            cost += horizontal * v[i].first;
        }
        else if(v[i].second == 'x') {
            // printf("The element is %d and %c\n",v[i].first,v[i].second);            
            horizontal+=1;
            cost += vertical * v[i].first;
        }
    }
    // printf("Cost is %d\n",(int)cost);
    cost = cost % (long)(pow(10,9) + 7);
    
    return (int)cost;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int m = stoi(first_multiple_input[0]);

        int n = stoi(first_multiple_input[1]);

        string cost_y_temp_temp;
        getline(cin, cost_y_temp_temp);

        vector<string> cost_y_temp = split(rtrim(cost_y_temp_temp));

        vector<int> cost_y(m - 1);

        for (int i = 0; i < m - 1; i++) {
            int cost_y_item = stoi(cost_y_temp[i]);

            cost_y[i] = cost_y_item;
        }

        string cost_x_temp_temp;
        getline(cin, cost_x_temp_temp);

        vector<string> cost_x_temp = split(rtrim(cost_x_temp_temp));

        vector<int> cost_x(n - 1);

        for (int i = 0; i < n - 1; i++) {
            int cost_x_item = stoi(cost_x_temp[i]);

            cost_x[i] = cost_x_item;
        }

        int result = boardCutting(cost_y, cost_x);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
                             
