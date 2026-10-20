#include <iostream>
#include <vector>
using namespace std;
 
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
 
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
        
        
        bool isgood  = false;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(gcd(v[i], v[j]) <= 2){
                    isgood = true;
                    break;
                }
            }
            if(isgood){
                break;
            }
        }
        
        if(isgood){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
