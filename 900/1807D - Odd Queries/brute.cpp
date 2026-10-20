#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        long long n, q;
        cin >> n >> q;
        
        vector<long long> v;
        long long totalsum = 0;
        for(long long i = 0; i<n; i++){
            long long a;
            cin >> a;
            totalsum += a;
            v.push_back(totalsum);
        }
        
        while(q--){
            
            long long l, r, k;
            cin >> l >> r >> k;
            
            l -= 1;
            r -= 1;
            
            long long temp = totalsum;
            if(l == 0){
                temp -= v[r];
            }
            else{
                temp = temp - (v[r] - v[l-1]);
            }
            
            long long mult = (r-l+1)*k;
            temp += mult;
            
            if(temp % 2 == 1){
                cout << "YES" << "\n";
            }
            else{
                cout << "NO" << "\n";
            }
            
        }
        
    }
    
    
}
