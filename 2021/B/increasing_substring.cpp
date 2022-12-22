/*
    Go through the entire string and keep track of previous character and current increasing substring count.

    If the previous character is smaller then current character, then substring is increasing, add to substring count.
    Otherwise, the substring is broken, set substring count to 0.
    
    Print out current count after checking each character.
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
    string s;
    cin >> s;
    int count = 0;
    char prev = ' ';
    cout << "Case #" << cn << ": ";
    for(int i = 0; i < s.size(); i++){
        if(s[i] <= prev){
            count = 0;
        }
        count++;
        cout << count << " ";
        prev = s[i];
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