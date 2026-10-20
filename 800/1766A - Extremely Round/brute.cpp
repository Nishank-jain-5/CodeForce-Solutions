#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n; 
        cin >> n;
        
        int cnt = 0;
        
        if(n>=1 && n<=9){
            cnt += n;
        }
        else{
            cnt += 9;
            int con = 10;
            for(int i=10; i<=n; i = i + con){
                if(i == 100) con *= 10;
                else if(i == 1000) con *= 10;
                else if(i == 10000) con *= 10;
                else if(i == 100000) con *= 10;
                
                cnt++;
            }
            
        }
 
        
        cout << cnt << endl;
        
    }
    
}
