/*
    The minimum amount of operations needed is proportional to the difference in points. For every point a minimum of one switch.
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
    int n, k;
    string s;
    cin >> n >> k >> s;
    int ans = 0;
    for(int i = 0; i < n / 2; i++){
        if(s[i] != s[n - i - 1]){
            ans++;
        }
    }
    ans = abs(ans - k);
    cout << "Case #" << cn << ": " << ans << "\n";
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