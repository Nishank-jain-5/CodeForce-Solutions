#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector<int>v(n);
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            cin >> v[i];
            if(v[i] > maxi){
                maxi = v[i];
            }
            if(v[i] < mini){
                mini = v[i];
            }
        }
        
        int ans = 0;
        
        ans = max(ans, maxi - v[0]);
        ans = max(v[n-1]-mini, ans);
        for(int i=0; i<n; i++){
            if(i == n-1){
                ans = max(ans, v[i]-v[0]);
            }
            else{
                ans = max(ans, v[i]-v[i+1]);
            }
        }
        
        cout << ans << "\n";
        
        
    }
}
