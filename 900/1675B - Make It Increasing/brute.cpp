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
        
        int cnt = 0;
        
        for(int i=n-1; i>=0; i--){
            int current = v[i];
            int prev = 0;
            if(i-1 >= 0){
                prev = v[i-1];
            }
            else{
                break;
            }
            
            while(prev >= current){
                if(current == 0 && prev == 0){
                    cnt = -1;
                    break;
                }
                cnt++;
                prev /= 2;
            }
            
            if (cnt == -1) break;
            
            v[i-1] = prev;
        }
        
        cout << cnt << "\n";
    }
}
