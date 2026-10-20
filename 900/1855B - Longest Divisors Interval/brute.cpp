#include <iostream>
using namespace std;
 
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        long long n;
        cin >> n;
        
        long long cnt = 0;
        while(n % (cnt+1) == 0){
            cnt++;
        }
        
        cout << cnt << endl;
 
 
    }
    
}
