/*
    To find the largest product of consecutive prime numbers less than or equal to N, you have to find 3 numbers:
        1. The smallest prime larger than sqrt(n), l1
        2. The largest prime smaller than sqrt(n), s1
        3. The second largest prime smaller than sqrt(n), s2
    
    Then compare l1 * s1 and s1 * s2, whichever one is larger and less than or equal to N is the correct answer.
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int min(int a, int b){return a < b ? a : b;}
int max(int a, int b){return a > b ? a : b;}

ll findClosestPrime(ll n, int d){
    bool found = false;
    ll i = 0;
    while(!found){
        found = true;
        for(ll j = 2; j * j <= (n + i); j++){
            if((n + i) % j == 0){
                found = false;
                break;
            }
        }
        i += d;
    }
    return n + i - d;
}

void solve(int cn){
    ll n;
    cin >> n;
    ll ans = 0;
    ll s1 = findClosestPrime(sqrt(n), -1);
    ll s2 = findClosestPrime(s1 - 1, -1);
    ll l1 = findClosestPrime(sqrt(n) + 1, 1);
    
    if(l1 * s1 <= n){
        ans = l1 * s1;
    }else{
        ans = s1 * s2;
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