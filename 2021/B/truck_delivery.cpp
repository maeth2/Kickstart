/*

*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
using ll = long long;

struct edge{
    int x;
    int w;
    ll c;
};

struct query{
    int weight;
    int day;
};

int n, q;
vector<vector<edge>> adj;
vector<vector<query>> queries;
vector<ll> order;
const ll maxN = 5 * 10e4;
ofstream myfile;
ll sn, t[4 * maxN];
int mxw;

ll min(ll a, ll b){return a < b ? a : b;}
ll max(ll a, ll b){return a > b ? a : b;}

ll gcd(ll a, ll b){
    if(a == 0){
        return b;
    }
    return gcd(b % a, a);
}

/*
    Build the Segment tree.
    Children of index i will be at index i * 2 (left) and i * 2 + 1 (right).
*/
void build(ll a[], ll v, ll l, ll r){
    if(l == r){
        t[v] = a[l];
    }else{
        ll m = (l + r) / 2;
        build(a, v * 2, l, m);
        build(a, v * 2 + 1, m + 1, r);
        t[v] = gcd(t[v * 2], t[v * 2 + 1]);
    }
}

/*
    Build a blank segment tree from range
*/
void build(int size){
    sn = size;
    ll a[sn];
    memset(a, 0, sizeof(a));
    build(a, 1, 0, size);
}

/*
    Sum query for specific range in segment tree
    tl and tr are the current vertex ranges while l and r are the query ranges
*/
ll sum(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    ll tm = (tl + tr) / 2;
    ll a = sum(v * 2, tl, tm, l, min(r, tm));
    ll b = sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return gcd(a, b);
}

/*
    Shortcut function for sum()
*/
ll sum(ll l, ll r){
    return sum(1, 0, sn, l, r);
}

/*
    Update segmented tree given position and value
    Recursively search for desired position, change value, then update when traveling back
*/
void update(ll v, ll l, ll r, ll pos, ll new_sum){
    if(l == r){
        t[v] = new_sum;
    }else{
        ll m = (l + r) / 2;
        if(pos <= m){
            update(v * 2, l, m, pos, new_sum);
        }else{
            update(v * 2 + 1, m + 1, r, pos, new_sum);
        }
        t[v] = gcd(t[v * 2], t[v * 2 + 1]);
    }
}

/*
    Shortcut function for update()
*/
void update(ll pos, ll new_sum){
    update(1, 0, sn, pos, new_sum);
}

void dfs(int node, vector<bool> &searched){
    searched[node] = true;
    for(query i : queries[node]){
        order[i.day] = sum(1, i.weight);
    }
    for(edge i : adj[node]){
        if(searched[i.x]) continue;
        if(i.w <= mxw){
            update(i.w, i.c);
            dfs(i.x, searched);
            update(i.w, 0);
        }else{
            dfs(i.x, searched);
        }
    }
}

void solve(ll cn){
    cin >> n >> q;
    adj = vector<vector<edge>> (n + 1);
    queries = vector<vector<query>> (n + 1);
    order = vector<ll> (q);
    mxw = -1;
    for(int i = 0; i < n - 1; i++){
        int x, y, l;
        ll a;
        cin >> x >> y >> l >> a;
        adj[x].push_back({y, l, a});
        adj[y].push_back({x, l, a});
    }
    for(int i = 0; i < q; i++){
        int c, w;
        cin >> c >> w;
        mxw = max(mxw, w);
        queries[c].push_back({w, i});
    }
    build(mxw + 1);
    vector<bool> searched(n + 1);
    dfs(1, searched);
    cout << "Case #" << cn << ": ";
    for(ll i : order){
        cout << i << " ";
    }
    cout << "\n";
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