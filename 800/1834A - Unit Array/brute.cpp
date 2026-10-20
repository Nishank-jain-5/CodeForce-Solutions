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
        int minus = 0;
        int plus = 0;
        int cnt = 0;
 
        for(int i=0; i<n; i++){
            cin >> v[i];
            if(v[i] == 1){
                plus++;
            }
            else{
                minus++;
            }
        }
        
        while(plus < minus || minus % 2 == 1){
            plus++;
            minus--;
            cnt++;
        }
        
        cout << cnt << endl;
        
       
        
        
    }
    
}
