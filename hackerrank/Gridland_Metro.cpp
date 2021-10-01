#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'gridlandMetro' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 *  3. INTEGER k
 *  4. 2D_INTEGER_ARRAY track
 */

long long gridlandMetro(int n, int m, int k, vector<vector<int>> track) {
    long long solution=0;
    sort(track.begin(), track.end());
   
   if(k==0) return n*m;
   long long num = track[0][0];
   long long size=1;
   for(int i=1;i<k;i++){
       if(num!=track[i][0]){
           num = track[i][0];
           size++;
       }
   }
   vector<int> chk(size);
   num = track[0][0];
   long long start = track[0][1];
   long long end = track[0][2];
   long long sum = track[0][2]-track[0][1]+1;
   long long idx=0;
   if(k>1){
        for(int i=1;i<k;i++){
            if(num==track[i][0]){
                if(track[i][2]<=end) continue;
                if(track[i][1]<=end) sum += track[i][2]-end;
                else sum += track[i][2]-track[i][1]+1;
                end = track[i][2];
            }
            else{
                chk[idx++] = sum;
                num = track[i][0];
                start = track[i][1];
                end = track[i][2];
                sum = track[i][2]-track[i][1]+1;
            }
        }
   }
   chk[size-1] = sum;
   
   for(int i=0;i<size;i++){
       solution += m-chk[i];
   }
   
   solution += m*(n-size);
   return solution;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    int k = stoi(first_multiple_input[2]);

    vector<vector<int>> track(k);

    for (int i = 0; i < k; i++) {
        track[i].resize(3);

        string track_row_temp_temp;
        getline(cin, track_row_temp_temp);

        vector<string> track_row_temp = split(rtrim(track_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int track_row_item = stoi(track_row_temp[j]);

            track[i][j] = track_row_item;
        }
    }

    long long result = gridlandMetro(n, m, k, track);

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
