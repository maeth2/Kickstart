/*
    Start count if i is equal to k. Then check subsequent index for consecutive countdown. Once size of sequence is equal to
    k add one to the answer.
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
    int n, k, answer, prev, count;
    answer = 0;
    count = 0;
    cin >> n >> k;
    cin >> prev;
    if(prev == k) count = 1;
    for(int i = 0; i < n - 1; i++){
        int c;
        cin >> c;
        if(c == k){
            count = 1;
        }else{
            if(prev - c == 1 && count != 0){
                count++;
            }else{
                count = 0;
            }
            if(count == k){
                answer++;
                count = 0;
            }
        }
        prev = c;
    }
    cout << "Case #" << cn << ": " << answer << "\n";
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