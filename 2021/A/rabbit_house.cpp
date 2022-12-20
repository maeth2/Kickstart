/*
    Start at the highest point in the grid then update all adjacent cells to height - 1. Update answer by height - adj - 1.
    Repeat until all cells have been checked.
*/
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int min(int a, int b){return a < b ? a : b;}
int max(int a, int b){return a > b ? a : b;}

struct node{
    ll height;
    int r;
    int c;
};

struct compare {
    bool operator()(const node * p1, const node * p2)
    {
        return p1->height < p2->height;
    }
};

void solve(int cn){
    int R, C;
    cin >> R >> C;
    node * grid[R][C];
    priority_queue<node*, vector<node*>, compare> pq;
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            node * n = new node();
            cin >> n->height;
            n->r = r;
            n->c = c;
            grid[r][c] = n;
            pq.push(n);
        }
    }

    ll ans = 0;
    while(!pq.empty()){
        node * n = pq.top();
        pq.pop();
        if(grid[n->r][n->c] != n) continue;
        for(int i = 0; i < 4; i++){
            int nr = n->r + dir[i][0];
            int nc = n->c + dir[i][1];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(grid[nr][nc]->height < n->height){
                ans += n->height - grid[nr][nc]->height - 1;
                node * n1 = new node();
                n1->height = n->height - 1;
                n1->r = nr;
                n1->c = nc;
                grid[nr][nc] = n1;
                pq.push(n1);
            }
        }
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