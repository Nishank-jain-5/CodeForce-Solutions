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
        
        
        int maxnum = v[n-1];
        
        if(v[0] == maxnum){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            cout << maxnum << " ";
            for(int i=0; i<n-1; i++){
                cout << v[i] << " ";
            }
            cout << endl;
        }
 
        
    }
}
