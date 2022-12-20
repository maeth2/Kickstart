/*
Simple check for the adjacent heights at each elevation.
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int min(int a, int b){return a < b ? a : b;}
int max(int a, int b){return a > b ? a : b;}

void solve(int cn){
    int n;
    cin >> n;
    int height[n];
    for(int i = 0; i < n; i++){
        cin >> height[i];
    }
    int ans = 0;
    for(int i = 1; i < n - 1; i++){
        if(height[i - 1] < height[i] && height[i + 1] < height[i]){
            ans++;
        }
    }
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