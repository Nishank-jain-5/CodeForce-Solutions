#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        
        vector<int> v(n);
        
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        
        bool got = false;
        for(int i=0; i<n; i++){
            if(v[i] == k){
                cout << "YES" << endl;
                got = true;
                break;
            }
        }
        
        if(!got){
            cout << "NO" << endl;
        }
    }
    
}
