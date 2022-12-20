/*
    Instead of trying to find all possible combinations of additional sessions to find the min difficulty, it is faster to 
    go backwards and find the total # of additional sessions per difficulty.

    To calculate # of additional sessions per difficulty, use the formula d / m - 1 to calculate total # of additional 
    sessions needed per consecutive sessions to acheive the difficulty, where d is the difference between the two values
    and m is the desired difficulty. Add the values up to find total # of additional sessions needed to acheive the difficulty m.

    It is inefficient to try all possible difficulty from 1 to 10^9, or whatever the difficulty is without any extra sessions. 
    That is why by using binary search the program goes from O(10^9 * N) time to O(log(n)) time. If the number of additional 
    sessions for a given diffulty exceeds k, the difficulty is too small to acheive. If the number is less the k, the difficulty
    could be smaller. Given these perimeters, a binary search is performed on all values from 1 to the initial difficulty of the
    workout.

    Once the search is over the lower bound of the search is the smallest diffuclty possible using up to k additional sessions.
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int min(int a, int b){return a < b ? a : b;}
int max(int a, int b){return a > b ? a : b;}

void solve(int cn){
    int n, k;
    cin >> n >> k;
    int sessions[n];
    int diff = 0;
    for(int i = 0; i < n; i++){
        cin >> sessions[i];
        if(i != 0){
            int d = sessions[i] - sessions[i - 1];
            if(d > diff){
                diff = d;
            }
        }
    }
    int l = 1;
    int r = diff;
    while(l < r){
        int m = (r + l) / 2;
        int ks = 0;
        for(int i = 1; i < n; i++){
            int diff = sessions[i] - sessions[i - 1];
            int d = ceil((diff * 1.0) / m) - 1;
            ks += d;
        }
        if(ks > k){
            l = m + 1;
        }else{
            r = m;
        }
    }
    cout << "Case #" << cn << ": " << l << "\n";
}

int main(void){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve(i + 1);
    }
    return 0;
}