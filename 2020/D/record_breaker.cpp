/*
    Loop through the days once and find all days that have a visitor count higher then all days prior.

    Then loop through the new found list of days to check whether or not the following day has less visitors.

    If both conditions are met, the day is a record day. Add to count.
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int min(int a, int b){return a < b ? a : b;}
int max(int a, int b){return a > b ? a : b;}

void solve(int cn){
    int n;
    cin >> n;
    int mx = -1;
    int days[n];
    int record[n];
    int count = 0;
    memset(record, -1, sizeof(record));
    for(int i = 0; i < n; i++){
        int j;
        cin >> j;
        days[i] = j;
        if(j > mx){
            mx = j;
            record[i] = j;
        }
    }
    for(int i = 0; i < n; i++){
        if(record[i] != -1){
            if(i == n - 1){
                count++;
            }else{
                if(days[i] > days[i + 1]){
                    count++;
                } 
            }
        }
    }
    cout << "Case #" << cn << ": " << count << "\n";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve(i + 1);
    }
    return 0;
}