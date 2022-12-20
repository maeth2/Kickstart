/*
    Basic premise is that each sequence has 3 numbers in it. For it to be a arithmic progression,
        A + D = B
        B + D = C
    Therefore,
        B - A = D
        B + B - A = C
        2B - A = C
        C + A = 2B
        (A + C) / 2 = B

    Another observation is that there are 4 sequences that do not invlove the missing center square,
    leaving 4 that does involve it.

    First calculate all the arithmic progressions that do not involve the center square by checking if
        (A + C) / 2 = B

    Then to find the missing center number, calculate the B value using the two known value of each sequence.
        B = (A + C) / 2
    
    Once calculated, find the B value that appears the most within those 4 sequences. 
    That number creates the maximum amount of arithemic progressions.
    However, the question asks for the maximimum number of arithemic progressions, not the missing number which creates it.
    To do that simply find the amount of times said missing number appears within the 4 sequences and add it to 
    the number we found in the first step.
*/

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

void solve(int cn){
    long grid[3][3];
    long sequences[4];
    bool sb[4];
    int count = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == 1 && j == 1){
                continue;
            }
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i < 3; i++){
        count += (grid[i][0] + grid[i][2]) / 2 == grid[i][1] && !bool((grid[i][0] + grid[i][2]) % 2);
    }

    for(int i = 0; i < 3; i++){
        count += (grid[0][i] + grid[2][i]) / 2 == grid[1][i] && !bool((grid[0][i] + grid[2][i]) % 2);
    }
    
    sequences[0] = (grid[0][1] + grid[2][1]) / 2;
    sb[0] = !bool((grid[0][1] + grid[2][1]) % 2);
    sequences[1] = (grid[1][0] + grid[1][2]) / 2;
    sb[1] = !bool((grid[1][0] + grid[1][2]) % 2);
    sequences[2] = (grid[0][0] + grid[2][2]) / 2;
    sb[2] = !bool((grid[0][0] + grid[2][2]) % 2);
    sequences[3] = (grid[0][2] + grid[2][0]) / 2;
    sb[3] = !bool((grid[0][2] + grid[2][0]) % 2);

    int mc = 0;
    for(int i = 0; i < 4; i++){
        int c = 0;
        for(int j = 0; j < 4; j++){
            if(sequences[j] == sequences[i] && sb[j]){
                c++;
            }
        }
        if(c > mc){
            mc = c;
        }
    }

    count += mc;
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