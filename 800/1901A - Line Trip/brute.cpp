#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n, x;
        cin >> n >> x;
        
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        
        int maxi = -1;
        int cnt = 0;
        
        for(int i=0; i<=x; i++){
            if(find(v.begin(), v.end(), i) != v.end()){
                maxi = max(maxi, cnt);
                cnt = 0;
            }
            cnt++;
        }
        
        while(x--){
            if(find(v.begin(), v.end(), x) != v.end()){
                maxi = max(maxi, cnt);
                cnt = 0;
                break;
            }
            cnt++;
        }
        
        cout << maxi << endl;
        
        
    }
    
    
}
