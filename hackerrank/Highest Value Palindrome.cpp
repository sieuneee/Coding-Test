#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'highestValuePalindrome' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER n
 *  3. INTEGER k
 */

string highestValuePalindrome(string s, int n, int k) {
    string sol = s;
    int time = k;
    vector<int> check(n);
        for(int i=0;i<n/2;i++){
            if(sol[i]!=sol[n-i-1]){
                if(time==0) return "-1";
                char max = (sol[i]>sol[n-i-1])?sol[i]:sol[n-i-1];
                if(max==sol[i]) {
                    check[n-i-1] = 1;
                    sol[n-i-1] = max;
                }
                else {
                    check[i] = 1;
                    sol[i] = max;
                }
                time--;
            }
        }
        if(time>=1){
            for(int i=0;i<n/2;i++){
                if(time==0) break;
                if(sol[i]<'9'){
                        if(check[n-i-1]==1 || check[i]==1){
                            if(time>=1){
                                sol[n-i-1] = '9';
                                sol[i] = '9';
                                time--;
                            }
                        }
                        else if(time>=2){
                            sol[n-i-1] = '9';
                            sol[i] = '9';
                            time-=2;
                        }
                }
            }
            if(time>0 && n%2==1){
                sol[n/2] = '9';
                time--;
            }
        }
    return sol;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

    fout << result << "\n";

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
