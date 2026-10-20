#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
 
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        long long n, k;
        cin >> n >> k;
        
        vector<long long> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        
        if(n == 1){
            cout << 0 << "\n";
            continue;
        }
        
        sort(v.begin(), v.end());
        long long mini = INT_MAX;
        
        int i = 1;
        int j = i;
        
        for(i=1; i<n; i++){
            int cnt = 1;
            for(j=i; j<n; j++){
                long long diff = abs(v[j] - v[j-1]);
                if(diff <= k){
                    cnt++;
                }
                else{
                    break;
                }
            }
            i = j;
            mini = min(mini, n-cnt);
        }
        
        cout << mini << "\n";
        
        
    }
    
    
}
