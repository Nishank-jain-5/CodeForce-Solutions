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
        
        vector<long long> ans;
        for(int i=0; i<n; i++){
            if(i == 0){
                ans.push_back(v[i]);
            }
            else if(v[i] >= v[i-1]){
                ans.push_back(v[i]);
            }
            else if(v[i] < v[i-1]){
                ans.push_back(v[i]);
                ans.push_back(v[i]);
            }
        }
        
        cout << ans.size() << endl;
        
        for(auto v : ans){
            cout << v << " ";
        }
        cout << endl;
        
        
        
    }
    
    
    
}
