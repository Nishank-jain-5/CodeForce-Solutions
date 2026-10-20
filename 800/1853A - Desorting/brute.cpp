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
        
        vector<long long> v(n);
        long long min_diff = INT_MAX;
        int index = -1;
        int cnt = 0;
        
        
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        
        for(int i=1; i<n; i++){
            long long diff = v[i] - v[i-1];
            
            if(diff < min_diff){
                index = i-1;
                min_diff = min(min_diff, diff);
            }
            
        }
        
        if(min_diff < 0){
            cout << 0 << endl;
        }
        else{
            
            long long diff = v[index+1] - v[index];
            
            long long ans = (diff / 2) + 1;
            
            cout << ans << endl;
        }
        
        
    }
    
    
    
}
