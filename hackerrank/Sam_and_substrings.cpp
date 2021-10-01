#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

/*
 * Complete the 'substrings' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING n as parameter.
 */

long long substrings(string n) {
    int len = n.length();
    long long factor = 1, ans = 0;

    for (int i = len-1; i >= 0; --i) {
        long long tmp = (n[i]-'0') * (i+1) * factor % MOD;
        ans += tmp;
        ans %= MOD;
        factor = (factor * 10 + 1) % MOD;
        cout << tmp << "\n";
    }

    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n;
    getline(cin, n);

    long long result = substrings(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
