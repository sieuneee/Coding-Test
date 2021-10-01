#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumLoss' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts LONG_INTEGER_ARRAY price as parameter.
 */
 
bool func(vector<long> a, vector<long> b){
    return a[0]<b[0];
}

int minimumLoss(vector<long> price) {
    vector<vector<long>> temp;
    
    for(int i=0;i<price.size();i++){
        vector<long> tmp;
        tmp.push_back(price[i]);
        tmp.push_back(i);
        temp.push_back(tmp);
    }
    
    long min = *max_element(price.begin(), price.end()) - *min_element(price.begin(), price.end());
    sort(temp.begin(), temp.end(), func);

    for(int i=0;i<temp.size()-1;i++){
        if(temp[i][1]>temp[i+1][1]){
            long diff = temp[i+1][0]-temp[i][0];
            if(diff>0 && diff<min) min = diff;
        }
    }
    return min;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string price_temp_temp;
    getline(cin, price_temp_temp);

    vector<string> price_temp = split(rtrim(price_temp_temp));

    vector<long> price(n);

    for (int i = 0; i < n; i++) {
        long price_item = stol(price_temp[i]);

        price[i] = price_item;
    }

    int result = minimumLoss(price);

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
