#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
 
        sort(a.begin(), a.end());
 
        int mx = 1, cur = 1;
        for(int i = 1; i < n; i++){
            if(a[i] == a[i-1]) cur++;
            else cur = 1;
            mx = max(mx, cur);
        }
 
        long long temp = mx;
        long long cnt = 0;  
 
        while(temp < n){
            cnt++;
            temp += min(temp, (long long)n - temp);
        }
 
        cout << cnt + (n - mx) << "\n";
    }
    return 0;
}
