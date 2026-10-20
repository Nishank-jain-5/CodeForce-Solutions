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
        vector<int> ans;
        int val = 0;
        
        for(int i=0; i<n; i++){
            cin >> v[i];
            
            
            if(i==0){
                if(v[i] == 1){
                    val = v[i] + 1;
                }
                else{
                    val = v[i];
                }
                ans.push_back(val);
            }
            else{
                if(v[i] == 1){
                    int cnt = 1;
                    while(((v[i]+cnt) % val) == 0){
                        cnt++;
                    }
                    val = v[i] + cnt;
                    ans.push_back(val);
                }
                else if(v[i] % val == 0){
                    val = v[i]+1;
                    ans.push_back(val);
                }
                else{
                    val = v[i];
                    ans.push_back(v[i]);
                }
            }
        }
        
        for(auto i :  ans){
            cout << i << " ";
        }
        cout << "\n";
        
    }
}
