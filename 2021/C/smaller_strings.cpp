/*

*/
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int n, k, m;
string s;

int min(int a, int b){return a < b ? a : b;}
int max(int a, int b){return a > b ? a : b;}

int recurse(char c, int p){
    int ans = 0;
    
}

void solve(int cn){
    cin >> n >> k >> s;
    int ans = 0;
    m = ceil(n / 2.0); 
    for(int i = m - 1; i >= 0; i--){
        int b = s[i] - 'a';
        ans += b;
        
    }
    cout << "Case #" << cn << ": " << recurse("") << "\n";
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