#include <iostream>
#include <vector>
using namespace std;
 
 
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n;
        cin >> n;
        
        vector<int> v(n);
        
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        
        
        int maxi = 0;
        int cnt = 0;
        
        for(int i=0; i<n; i++){
            if(v[i] == 0){
                while(i<n && !v[i]){
                    cnt++;
                    i++;
                }
                maxi = max(maxi, cnt);
                cnt = 0;
            }
        }
        
        cout << maxi << endl;
        
        
    }
    
    
}
