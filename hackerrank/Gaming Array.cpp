#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'gamingArray' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */
bool func(pair<int, int> a, pair<int, int> b){
    return a.first>b.first;
}
string gamingArray(vector<int> arr) {
    vector<pair<int, int>> tmp;
    for(int i=0;i<arr.size();i++) tmp.push_back({arr[i], i});
    sort(tmp.begin(), tmp.end(), func);
    
    
    // for(int i=0;i<arr.size();i++) cout << tmp[i].first << "  " << tmp[i].second << "\n";
    
    int cnt=0, start=0;
    int size = arr.size()-1;
    int idx=0;
    
    for(int i=0;i<arr.size();i++){
        if(size<0) break;
        if(tmp[i].second==start) {
            start = -1;
            size = -1;
            idx++;
        }
        else if(tmp[i].second==start+size) {
            size--;
            idx++;
        }
        else if(tmp[i].second>start && tmp[i].second<start+size){
            // size -= (tmp[i].second-start);
            size = tmp[i].second-start-1;
            idx++;
        }
    }
    if(idx%2==1) return "BOB";
    else return "ANDY";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string arr_count_temp;
        getline(cin, arr_count_temp);

        int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split(rtrim(arr_temp_temp));

        vector<int> arr(arr_count);

        for (int i = 0; i < arr_count; i++) {
            int arr_item = stoi(arr_temp[i]);

            arr[i] = arr_item;
        }

        string result = gamingArray(arr);

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
