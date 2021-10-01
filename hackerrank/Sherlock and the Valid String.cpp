#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    vector<int> time(26);
    for(int i=0;i<s.size();i++){
        time[s[i]-97]++;
    }
    
    int num = time[s[0]-97];
    for(int i=0;i<26;i++){
        if(time[i]==0) continue;
        if(time[i]<num) num = time[i];
    }

    int fillNum = 0;
    int notMin = 0;
    bool first = true;
    int allNum = 0;
    for(int i=0;i<26;i++){
        if(time[i]==0) continue;
        if(time[i]!=num) {
            if(first == true) notMin = time[i];
            first = false;
            if(notMin==time[i]) fillNum++;
        }
        allNum++;
    }
    
    if(fillNum == allNum-1){
        if(num==1) return "YES";
    }

    int check = 0;
    for(int i=0;i<26;i++){
        if(time[i]==0) continue;
        int diff = time[i]-num;
        if(diff==0) continue;
        else if(diff==1){
            if(check>=1) return "NO";
            check++;
        }
        else return "NO";
        cout << i<<time[i] << diff << check << "\n";
    }
    
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
