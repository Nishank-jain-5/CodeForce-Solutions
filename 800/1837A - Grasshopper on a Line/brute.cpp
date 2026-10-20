#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int x, k;
        cin >> x >> k;
        
        int maxi = -1;
        
        if(k > 0){
            for(int i=1; i<=x; i++){
                if(i % k == 0){
                    continue;
                }
                else{
                    if(i <= x){
                        maxi = i;
                    }
                }
            }
        }
        
        vector<int> ans;
        
        ans.push_back(maxi);
        
        for(int i=1; i<=x; i++){
            if(maxi + i == x){
                ans.push_back(i);
                break;
            }
        }
        
        cout << ans.size() << endl;
        for(auto i : ans){
            cout << i << " ";
        }
        cout << endl;
        
        
        
        
        
    }
    
    
}
