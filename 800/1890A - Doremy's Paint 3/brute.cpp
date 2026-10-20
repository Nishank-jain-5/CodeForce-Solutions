#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        unordered_map<int,int> mpp;
        
        for(int i=1; i<=n; i++){
            int val;
            cin >> val;
            mpp[val]++;
        }
        
        if(mpp.size() > 2){
            cout << "NO" << endl;
        }
        else if(mpp.size() == 1){
            cout << "YES" << endl;
        }
        else{
            vector<int> v;
            for(auto it : mpp){
                v.push_back(it.second);
            }
            
            if(v[0] == v[1] || v[0] == v[1]+1 || v[1] == v[0]+1){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        
    }
    
}
