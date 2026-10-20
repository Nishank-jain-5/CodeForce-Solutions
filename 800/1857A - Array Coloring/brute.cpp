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
        int e = 0;
        int o = 0;
        
        for(int i=0; i<n; i++){
            cin >> v[i];
            if(v[i] % 2 == 0) e++;
            else o++;
        }
        
        if(e == 0 && o != 0){
            if(o % 2 == 0){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
            continue;
        }
        else if(o == 0 && e != 0){
            cout << "Yes" << endl;
            continue;
        }
        
        if(v.size() == 2){
            if(e == 2 || o == 2){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
        else if(e == o){
            if(e % 2 == 0){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
        else if(o % 2 == 0 && e % 2 != 0){
            cout << "Yes" << endl;
        }
        else if(o % 2 == 0 && e % 2 == 0){
            cout << "Yes" << endl;
        }     
        else{
            cout << "No" << endl;
        }    
        
        
    }
    
    
    
}
