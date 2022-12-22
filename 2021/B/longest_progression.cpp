/*

*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int min(int a, int b){return a < b ? a : b;}
int max(int a, int b){return a > b ? a : b;}

void solve(int cn){
    int n;
    cin >> n;
    ll ans = 0;
    ll a[n];
    ll d[n - 1];
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n - 1; i++){
        d[i] = a[i + 1] - a[i];
    }

    //Check forwards
    for(int i = 0; i < n - 1; i++){
        int length = 0;
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
    //Check backwards
    for(int i = n - 2; i >= 0; i--){
        int length = 0;
        for(int j = i; j >= 0; j--){
            if(d[i] != d[j]){
                i = j + 1;
                break;
            }
            if(j == 0){
                i = 0;
            }else{
                length++;
            }
        }
        int count = 0;
        if(i - 1 < 0){
            length++;
        }
        for(int z = i - 1; z >= 0; z--){
            if(z == i - 1){
                count = d[z];
                length++;
                continue;
            }
            count += d[z];
            if(count != d[i] * (i - z)){
                break;
            }
            length++;
        }
        ans = max(ans, length);
    }
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