/*
    Solved using trie structure

    Create a tree using nodes containing 2 perimeters:
        prefixes: # of strings that contains said prefix
        count: # of strings that ends with said prefix
    
    After finding all the nodes, traverse back up the tree by finding all nodes which has counts that can form groups of K,
    if there are excess or cannot form said group, add the count to the parent node up the tree. Calculate the score by multiplying
    the layer of the node with the # of groups formed then add that score to the parent node. Repeat the steps until reaching the
    root node
*/
#include <iostream>

using namespace std;
using ll = long long;

ll N, K;

struct node{
    node * child[26];
    ll prefixes;
    ll count;
};

void addStringtoTree(string s, node * root){
    node * n = root;
    n->prefixes++;
    for(int i = 0; i < s.size(); i++){
        if(n->child[s[i] - 'A'] == NULL){
            node * nn = new node();
            n->child[s[i] - 'A'] = nn;
        }
        n = n->child[s[i] - 'A'];
        n->prefixes++;
    }
    n->count++;
}

ll traverseTree(node * n, ll layer){
    ll score = 0;
    if(n->prefixes < K) return 0;
    ll here = n->count;
    for(ll i = 0; i < 26; i++){
        if(n->child[i] != NULL){
            score += traverseTree(n->child[i], layer + 1);
            here += n->child[i]->prefixes % K;
        }
    }
    score += here / K * layer;
    return score;
}

void solve(ll cn){
    cin >> N >> K;
    node* root = new node();
    for(ll i = 0; i < N; i++){
        string s;
        cin >> s;
        addStringtoTree(s, root);
    }
    cout << "Case #" << cn << ": " << traverseTree(root, 0) << "\n";
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