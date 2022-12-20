/*
    Using a running prefix sum t, find all possible subarrays that form a perfect square. At each subarray a[0, i], there will be
    a sum of t. Store the running sum in a frequency list c[]. To find subarrays with perfect squares, Loop through all possible 
    integers j, where j * j > 0 and j * j < max sum. At any t, a subarray of sum t - j * j will leave a remaining subaaray of sum
    of j * j (perfect square). Therefore check if t - j * j exists in c[]. If it does add the number of occurences to final answer.
*/
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int min(int a, int b){return a < b ? a : b;}
int max(int a, int b){return a > b ? a : b;}

const int mxn = 1e5;
int n, a[mxn], c[2 * 100 * mxn + 1];

void solve(int cn){
    cin >> n;
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
    int mi = 0, mx = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < 0){
            mi -= a[i];
        }else{
            mx += a[i];
        }
    }
    int t = 0;
    int ans = 0;
    c[mi]++; //empty prefix add
    for(int i = 0; i < n; i++){
        t += a[i];
        for(int j = 0; j * j <= mx; j++){
            if((t - j * j) + mi >= 0){
                ans += c[(t - j * j) + mi];
            }
        }
        c[t + mi]++;
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