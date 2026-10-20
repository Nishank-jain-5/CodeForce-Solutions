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
        int sum = 0;
        
        for(int i=0; i<n-1; i++){
            cin >> v[i];
            sum += v[i];
        }
        
        cout << (-1)*sum << endl;
        
 
    }
    
}
