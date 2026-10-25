#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    while (n--) {
        string s, t;
        cin >> s >> t;
 
        int cs[26] = {0}; 
        int ct[26] = {0};  
 
        for (char c : s){ 
            cs[c - 'A']++;
        }
        for (char c : t){ 
            ct[c - 'A']++;
        }
 
        bool ok = true;
        for (int i = 0; i < 26; i++) {
            if (ct[i] > cs[i]) ok = false;
        }
 
        if (!ok) {
            cout << "NO\n";
            continue;
        }
 
        int del[26];
        for (int i = 0; i < 26; i++) {
            del[i] = cs[i] - ct[i];
        }
 
        string result = "";
        for (char c : s) {
            int i = c - 'A';
            if (del[i] > 0) {
                del[i]--;       
            } else {
                result += c;     
            }
        }
 
        if (result == t) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
