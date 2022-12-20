/*
To calculate most houses bought sort all prices from low to high then find a point when cost > range
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
    long n, b;
    cin >> n >> b;
    long prices[n];
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }
    sort(prices, prices + n);
    long p = 0;
    int a = 0;
    for(int i = 0; i < n; i++){
        p += prices[i];
        if(p > b){
            break;
        }
        a++;
    }
    cout << "Case #" << cn << ": " << a << "\n";
}

int main(void){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve(i + 1);
    }
    return 0;
}