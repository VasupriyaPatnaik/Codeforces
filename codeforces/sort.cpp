#include <bits/stdc++.h>
using namespace std; 

void solve(){
    int n, q;
    cin >> n >> q;

    vector<vector<int>> pre1(n + 1, vector<int>(26, 0));
    vector<vector<int>> pre2(n + 1, vector<int>(26, 0));

    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        pre1[i][c - 'a']++;

        for (int j = 0; j < 26; j++)
            pre1[i][j] += pre1[i - 1][j];
    }
    for (int i = 1; i <= n; i++){
        char c;
        cin >> c;
        pre2[i][c - 'a']++;

        for (int j = 0; j < 26; j++)
            pre2[i][j] += pre2[i - 1][j];
    }
    while (q--){
        int l, r;
        cin >> l >> r;

        int dif = 0;

        for (int c = 0; c < 26; c++){
            int v1 = pre1[r][c] - pre1[l - 1][c];
            int v2 = pre2[r][c] - pre2[l - 1][c];

            dif += abs(v1 - v2);
        }
        cout << dif / 2 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;

    while (tc--)
        solve();
}
