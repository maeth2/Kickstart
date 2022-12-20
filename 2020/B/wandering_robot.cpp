    /*

    */
    #include <iostream>
    #include <algorithm>
    #include <queue>
    #include <cmath>
    #include <vector>
    #include <string>

    /*

    ***            
    *X*
    ***

    0 1 1 1
    1 2 2 2
    1 2 3 3
    1 2 3 4

            (0, 0)
        (0, 1)          (1, 0)
    (0, 2)   (1, 1) (2, 0)  (1, 1)

    */


    using namespace std;
    using ll = long long;

    int min(int a, int b){return a < b ? a : b;}
    int max(int a, int b){return a > b ? a : b;}

    void solve(int cn){
        int W, H, L, U, R, D;
        cin >> W >> H >> L >> U >> R >> D;  
        vector<vector<int>> a(H, vector<int>(W));
        vector<vector<float>> dp(H, vector<float>(W));
        dp[0][0] = 1;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(i == 0 && j == 0) continue;
                if(j != 0)dp[i][j] += (i != H - 1 ? 0.5 : 1) * dp[i][j - 1];
                if(i != 0)dp[i][j] += (j != W - 1 ? 0.5 : 1) * dp[i - 1][j];
                if(i >= U - 1 && i <= D - 1 && j >= L - 1 && j <= R - 1)dp[i][j] = 0;
            }
        }
        cout << "Case #" << cn << ": " << dp[H - 1][W - 1] << "\n";
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