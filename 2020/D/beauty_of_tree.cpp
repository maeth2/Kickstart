/*
    This is problem requires you to construct and navigate a bi-directional tree.

    The tree is a simple adjecency list, where the parent appears at index Vi - 1 while the child is at i.

    Then traverse the tree using DFS starting from the root, i = 0, while keeping track of current path.

    Once the search reaches a node, add 1 to the counts a and b and add 1 + counts to the nodes i + a and i + b ahead 
    of the current node in the path.

    This gives the amount of times each node in the tree is reached by each players in all combinations.

    To calculate the true count of each node (Both players combined), use the inclusion-exclusion formula:
        Node Count = (ACount + BCount) * Number of Nodes - (ACount * B Count)
    
    Finally add up the counts of each node and divide by total number of combinations (N^2).
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
using ll = long long;

const int mxn = 5e5;
int n, a, b;
vector<vector<int>> children;
vector<int> ca, cb;

void dfs(int i, vector<int> &path){
    path.push_back(i);
    for(int j : children[i]){
       dfs(j, path);
    }
    ca[i]++;
    cb[i]++;
    int ja = (int)path.size() - a - 1;
    if(ja >= 0){
        ca[path[ja]] += ca[i];
    }
    int jb = (int)path.size() - b - 1;
    if(jb >= 0){
        cb[path[jb]] += cb[i];
    }
    path.pop_back();
}

void solve(int cn){
    cin >> n >> a >> b;
    children = vector<vector<int>> (n + 1);
    ca = vector<int> (n + 1);
    cb = vector<int> (n + 1);
    for(int i = 1; i < n; i++){
        int v;
        cin >> v;
        children[v - 1].push_back(i);
    }
    vector<int> path;
    dfs(0, path);
    double ans = 0;
    for(int i = 0; i < n; i++){
        ans += (double)(ca[i] + cb[i]) * n - (double)ca[i] * cb[i];
    }
    cout << fixed << setprecision(12) << "Case #" << cn << ": " << ans / n / n << "\n";
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
