#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n;
        cin >> n;
        
        vector<long long> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        
        if(n == 1){
            cout << 0 << endl;
        }
        else{
            int cnt = 1;
            int ans = 0;
            
            for(int i=1; i<n; i++){
                while(i < n && ((v[i] % 2 == 0 && v[i-1] % 2 == 0) || (v[i] % 2 != 0 && v[i-1] % 2 != 0))){
                    cnt++;
                    i++;
                }
                ans = ans + (cnt-1);
                cnt = 1;
            }
            
            cout << ans << endl;
        }
        
    }
    
}
