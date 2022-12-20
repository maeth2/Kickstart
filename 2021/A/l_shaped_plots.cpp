/*
    Calculate length of segment in all cardinal dimensions and store it in an array (top[][], bot[][], left[][], right[][]). Then
    Loop through each cell and calculate # of L shape using the stored lengths. 

    To calculate the number of L shapes of 2 segments use the formula:

    num = min(a / 2, b) + min(a, b / 2) - 2;

    Where A and B are the lengths of the segments
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int min(int a, int b){return a < b ? a : b;}
int max(int a, int b){return a > b ? a : b;}

int calc(int a, int b){
    if(a < 2 || b < 2){
        return 0;
    }
    return min(a / 2, b) + min(b / 2, a) - 2;
}

void solve(int cn){
    int R, C;
    cin >> R >> C;
    int grid[R][C];
    int top[R][C];
    int bot[R][C];
    int left[R][C];
    int right[R][C];
    memset(grid, 0, sizeof(grid));
    memset(top, 0, sizeof(grid));
    memset(bot, 0, sizeof(grid));
    memset(left, 0, sizeof(grid));
    memset(right, 0, sizeof(grid));

    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            cin >> grid[r][c];
        }
    }

    for(int c = 0; c < C; c++){
        for(int r = 0; r < R; r++){
            if(grid[r][c]){
                top[r][c] = r == 0 ? 1 : top[r - 1][c] + 1;
                left[r][c] = c == 0 ? 1 : left[r][c - 1] + 1;
            }
        }
    }

    for(int c = C - 1; c >= 0; c--){
        for(int r = R - 1; r >= 0; r--){
            if(grid[r][c]){
                bot[r][c] = r == R - 1 ? 1 : bot[r + 1][c] + 1;
                right[r][c] = c == C - 1 ? 1 : right[r][c + 1] + 1;
            }
        }
    }

    int ans = 0;
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            if(!grid[r][c]) continue;
            ans += calc(top[r][c], left[r][c]);
            ans += calc(top[r][c], right[r][c]);
            ans += calc(bot[r][c], left[r][c]);
            ans += calc(bot[r][c], right[r][c]);
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