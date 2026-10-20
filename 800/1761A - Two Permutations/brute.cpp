#include <iostream>
using namespace std;
 
 
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n, a, b;
        cin >> n >> a >> b;
        
        
        if(n == a && a == b){
            cout << "Yes" << endl;
        }
        else{
            int total = n - (a + b);
            
            if(total <= 1){
                cout << "NO" << endl;
            }
            else{
                cout << "YES" << endl;
            }
        }
        
        
    }
    
}
