#include <iostream>
#include <vector>
using namespace std;
 
 
int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
 
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n;
        cin >> n;
        
        vector<int> v(n);
        for (int i=0; i<n; i++){
            cin >> v[i];
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            int val = v[i];
            int pos = i+1;
            int diff = abs(val-pos);
            
            if(diff == 0) continue;
            else{
                ans = gcd(ans,diff);
            }
        }
        
        cout << ans <<  "\n";
        
        
        
    }
    
    
    
}
