/*
    This is a Dynamic Programming problem.

    To solve, you need to understand the Three rules:
        1. If note A is HIGHER then note B, then the converted note A also has to be HIGHER then Note B and vice versa
        2. If note A is EQUAL to note B, then the converted notes will also be EQUAL.
        3. The first note can be any converted note.

    There are N notes in total, so we have to dynamically build the minimum number of rule breaks per note, per conversion.

    We create a 2D array dp[i][j] where i is the note index and j is the converted note, and the value is the number of breaks.
    Then for each combination of notes and converted note, we test it against every combination of the previous note and converted 
    notes with the rules stated above.
    We then set the dp[i][j] to the minimum value of that search + the value of the searched combination.

    Continue this until the array is filled.

    To get the minimum number of breaks, we then go to i = n - 1 and find the smallest value among the 4 converted notes.
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int n;

int min(int a, int b){return a < b ? a : b;}
int max(int a, int b){return a > b ? a : b;}

int check(int i, int j, int j1, int notes[]){
    if(notes[i] > notes[i - 1]){
        if(j <= j1){
            return 1;
        }
    }else if(notes[i] < notes[i - 1]){
        if(j >= j1){
            return 1;
        }
    }else if(notes[i] == notes[i - 1]){
        if(j != j1){
            return 1;
        }
    }
    return 0;
}
void solve(int cn){
    cin >> n;
    int dp[n][4];
    int notes[n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            dp[i][j] = INT32_MAX;
        }
        cin >> notes[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            if(i == 0){
                dp[i][j] = 0;
            }else{
                for(int j1 = 0; j1 < 4; j1++){
                    dp[i][j] = min(dp[i][j], dp[i - 1][j1] + check(i, j, j1, notes));
                }
            }
        }
    }
    int count = INT32_MAX;
    for(int i = 0; i < 4; i++){
        count = min(dp[n - 1][i], count);
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