/*

*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int n;
vector<ll> d;

int min(int a, int b){return a < b ? a : b;}
int max(int a, int b){return a > b ? a : b;}

int check(){
    int ans = 0;
    for(int i = 0; i < n - 1; i++){
        int length = 0;
        //Checks for chunks of same differences
        for(int j = i; j < n - 1; j++){
            if(d[i] != d[j]){
                i = j - 1;
                break;
            }
            if(j == n - 2){
                i = n - 2;
            }else{
                length++;
            }
        }
        int count = 0;
        if(i + 1 > n - 2){
            length++;
        }
        for(int z = i + 1; z < n - 1; z++){
            if(z == i + 1){
                count = d[z];
                length++;
                continue;
            }
            count += d[z];
            if(count != d[i] * (z - i)){
                break;
            }
            length++;
        }
        ans = max(ans, length);
    }
    return ans;
}
void solve(int cn){
    cin >> n;
    ll ans = 0;
    ll a[n];
    d = vector<ll>(n - 1);
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n - 1; i++){
        d[i] = a[i + 1] - a[i];
    }

    ans = max(ans, check());
    reverse(d.begin(), d.end());
    ans = max(ans, check());
    cout << "Case #" << cn << ": " << ans + 1 << "\n";
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