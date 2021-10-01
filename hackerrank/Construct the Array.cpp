#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'countArray' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER x
 */

long long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.
    vector<vector<long long>> dp(n, vector<long long>(2));

    dp[0][0] = 1; dp[0][1] = 0;
    for(int i=1;i<n-1;i++){
        dp[i][0] = (dp[i-1][1]*(k-1))%1000000007;
        if(i%2==0) dp[i][1] = (dp[i][0]-1)%1000000007;
        else dp[i][1] = (dp[i][0]+1)%1000000007;
    }
    
    if(x==1) return (dp[n-2][1]*(k-1))%1000000007;
    return (dp[n-2][0]+dp[n-2][1]*(k-2))%1000000007;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    int x = stoi(first_multiple_input[2]);

    long long answer = countArray(n, k, x);

    fout << answer << "\n";

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
