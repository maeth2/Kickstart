/*
    Solution to the problem is to first sort the students based on skill level Si*.
    Afterwards use the sorted list to calculate the prefix sums of students skills from Si to Si + P**
    Finally loop throught the list again using the equation below and find the minimum time required:
        time = Si * P - PS[i + P - 1]***

    *Si is the skill level of a student at index I.
    **P is the number of people per group.
    ***PS is the prefix sum array.

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
    int n, p;
    cin >> n >> p;
    vector<int> students(n);
    vector<int> ps(n);
    for(int i = 0; i < n; i++){
        cin >> students[i];
    }
    sort(students.begin(), students.end(), greater<int>());
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += students[i];
        if(i >= p){
            sum -= students[i - p];
        }
        ps[i] = sum;
    }
    int ans = INT32_MAX;
    for(int i = 0; i <= n - p; i++){
        ans = min(ans, students[i] * p - ps[i + p - 1]);
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