#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    vector<int> v(n);
    int mini = INT_MAX;
 
    for(int i=0; i<n; i++){
        cin >> v[i];
        
        if(v[i] == 0){
            mini = 0;
            break;
        }
        else{
            int a = abs(0-v[i]);
            if(a < mini){
                mini = a;
            }
        }
        
    }
    
    cout << mini;
    
}
