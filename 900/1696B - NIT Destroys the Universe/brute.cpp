#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        vector<int>v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        
        int block = 0;
        int i = 0;
        while(true){
            
            if(i >= n) break;
            
            if(v[i] != 0){
                block++;
                while(i<n && v[i] != 0){
                    i++;
                }
            }
            i++;
        }
        
        if(block == 0 || block == 1){
            cout << block << "\n";
        }
        else{
            cout << 2 << "\n";
        }
    }
}
