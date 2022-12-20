/*
    Wall must be built from ground up therefore the bottom block has to be built before top one. This order can be simplified
    to a directed graph. If the graph contains a cycle then the wall is not stable, otherwise use topological sort to find build
    order.
*/
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ll = long long;

int min(int a, int b){return a < b ? a : b;}
int max(int a, int b){return a > b ? a : b;}

int R, C;
char wall[30][30];
int contains[26];
bool adj[26][26];
vector<char> order;

bool search(int block, bool *visited, bool *trace){
    visited[block] = true;
    trace[block] = true;
    for(int i = 0; i < 26; i++){
        if(i == block) continue;
        if(adj[block][i]){
            if(!visited[i]){
                if(!search(i, visited, trace)){
                    return false;
                }
            }else{
                if(trace[i]){
                    return false;
                }
            }
        }
    }
    trace[block] = false;
    order.push_back(char(block + 'A'));
    return true;
}

void solve(int cn){
    cin >> R >> C;
    memset(adj, false, sizeof(adj));
    memset(contains, false, sizeof(contains));
    order.clear();
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            cin >> wall[r][c];
            contains[wall[r][c] - 'A'] = true;
        }
    }
    for(int r = 0; r < R - 1; r++){
        for(int c = 0; c < C; c++){
            if(wall[r + 1][c] != wall[r][c]){
                adj[wall[r][c] - 'A'][wall[r + 1][c] - 'A'] = true;
            }
        }
    }
    bool visited[26];
    bool trace[26];
    for(int i = 0; i < 26; i++){
        visited[i] = false;
        trace[i] = false;
    }
    bool isValid = true;
    for(int i = 0; i < 26; i++){
        if(!visited[i] && contains[i]){
            isValid = isValid && search(i, visited, trace);
        }
    }
    cout << "Case #" << cn << ": ";
    if(isValid){
        for(auto i : order){
            cout << i;
        }
    }else{
        cout << -1;
    }
    cout << "\n";
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