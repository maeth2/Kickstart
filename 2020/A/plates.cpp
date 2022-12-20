/*
Simple dynamic approach; Calculate all sums of plates then dynamically calculate best value per num of plates per stack
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int min(int a, int b){return a < b ? a : b;}
int max(int a, int b){return a > b ? a : b;}

void solve(int cn){
    int n, k, p;
    cin >> n >> k >> p;
    int plates[n + 1][k + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= k; j++){
            if(i == 0 || j == 0){
                plates[i][j] = 0;
                continue;
            }
            int v;
            cin >> v;
            if(j > 0){
                plates[i][j] = v + plates[i][j - 1];
            }else{
                plates[i][j] = v;
            }
        }
    }
    int dp[n + 1][p + 1];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= p; j++){
            dp[i][j] = 0;
            if(i == 0 || j == 0){
                continue;
            }
            for(int z = 0; z <= min(j, k); z++){
                dp[i][j] = max(dp[i][j], plates[i][z] + dp[i - 1][j - z]);
            }
        }
    }
    cout << "Case #" << cn << ": " << dp[n][p] << "\n";
}

int main(void){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve(i + 1);
    }
    return 0;
}