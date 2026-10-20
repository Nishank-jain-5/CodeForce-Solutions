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
        double product = 1;
        
        
        for(int i=0; i<n; i++){
            cin >> v[i];
            product *= v[i];
        }
        
        int k = 0;
        double mult = 1;
        bool flag = true;
        for(int i=0; i<n; i++){
            k++;
            mult *= v[i];
            if(mult == (product/mult)){
                cout << k << endl;
                flag = false;
                break;
            }
        }
        
        if(mult == product && flag){
            cout << -1 << endl;
        }
        
    }
    
}
