/*
Go through the string and for every character which is an integer recurse to find displacement.
Since the graph is looping, any displacement larger then maxN can be shrunk down.
e.g.
2(N2(W))
-> recurse("(N2(W))", 2)
-> move N * 2
-> recurse(2(W), 2 * 2)
-> move W * 2 * 2
-> Back track
-> Backtract
-> Final answer: NNWWWW
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

ll min(ll a, ll b){return a < b ? a : b;}
ll max(ll a, ll b){return a > b ? a : b;}

const ll maxN = 1000000000;
ll r, c;

void move(ll r1, ll c1){
    r += r1;
    c += c1;
    r = ((r % maxN) + maxN) % maxN;
    c = ((c % maxN) + maxN) % maxN;
}

int decode(string a, ll mult){
    for(ll i = 0; i < a.size(); i++){
        if(a[i] == '('){
            continue;
        }else if(a[i] == ')'){
            return i + 1;
        }else if(a[i] - '0' < 10){
            i += decode(a.substr(i + 1, a.size() - i), ((a[i] - '0') * mult) % maxN);
        }else{
            if(a[i] == 'N'){
                move(-1 * mult, 0);
            }else if(a[i] == 'S'){
                move(1  * mult, 0);
            }else if(a[i] == 'E'){
                move(0, 1 * mult);
            }else if(a[i] == 'W'){
                move(0, -1 * mult);
            }
        }
    }
    return 0;
}

void solve(ll cn){
    string n;
    cin >> n;
    decode(n, 1);
    cout << "Case #" << cn << ": " << c + 1 << ' ' << r + 1 << "\n";
    r = 0;
    c = 0;
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