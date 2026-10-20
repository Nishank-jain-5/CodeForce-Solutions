#include <iostream>
using namespace std;
 
 
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n;
        cin >> n;
        
        string s;
        cin >> s;
        
        
        
        int one = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                one++;
            }
        }
        
        if(one == 1){
            cout << 0 << endl;
        }
        else if(one == 2){
            cout << 1 << endl;
        }
        else{
            int l_index = -1;
            int r_index = -1;
            
            for(int i=n-1; i>=0; i--){
                if(s[i] == '1'){
                    r_index = i;
                    break;
                }
            }
            
            for(int i=0; i<n; i++){
                if(s[i] == '1'){
                    l_index = i;
                    break;
                }
            }
            cout << abs(r_index - l_index) << endl;
            
        }
 
        
    }
    
    
}
