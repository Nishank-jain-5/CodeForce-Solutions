#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n, m;
        cin >> n >> m;
        
        string x, s;
        cin >> x >> s;
        
        int cnt = 0;
        
        if(x.find(s) != -1){
            cout << 0 << endl;
        }
        else{
            int i = 5;
            
            do{
                x += x;
                i--;
                cnt++;
                n *= 2;
                
                if(x.find(s) != -1){
                    cout << cnt << endl;
                    break;
                }
                
            }while(n <= m || i != 0);
 
            
            if(x.find(s) == -1){
                cout << -1 << endl;
            }
        }
        
 
    }
}
