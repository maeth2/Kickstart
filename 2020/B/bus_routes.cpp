/*
After each stop check for nearest multiple of xi to see if route can be completed within d. 
To speed up for set 2 use binary search for latest starteing date.
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

ll min(ll a, ll b){return a < b ? a : b;}
ll max(ll a, ll b){return a > b ? a : b;}

const ll mxN = 1000;
ll routes[mxN];
ll n, d;

ll check(ll s){
    ll ans = s;
    for(ll i = 1; i < n; i++){
        ans = ceil((ans * 1.0) / routes[i]) * routes[i];
    }
    return ans;
}

void solve(ll cn){
    cin >> n >> d;
    for(ll i = 0; i < n; i++){
        cin >> routes[i];
    }
    ll ans = 0;
    ll l = 0, r = d / routes[0];
    while(l < r){
        ll m = (r + l) / 2;;
        ll ds = check(m * routes[0]);
        if(ds > d){
            r = m - 1;
        }else{
            l = m + 1;
        }
    }
    if(check(l * routes[0]) > d){
        l--;
    }
    cout << "Case #" << cn << ": " << l * routes[0] << "\n";
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    for(ll i = 0; i < t; i++){
        solve(i + 1);
    }
    return 0;
}