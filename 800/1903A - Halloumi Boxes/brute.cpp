// ye direct bhi ho skta tha simply condition laga kr pr phle mind me ese he aya (brute force}


#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){
    
    int t;
    cin >> t;
    
    for(int i=1; i<=t; i++){
        int n, k;
        cin >> n >> k;
        
        long long arr[n];
        
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        
        if(k == 1){
            if(n == 1){
                cout << "YES" << endl;
                continue;
            }
            else{
                bool flag = true;
                for(int i=1; i<n; i++){
                    if(arr[i] >= arr[i-1]){
                        continue;
                    }
                    else{
                        cout<<"NO" << endl;
                        flag = false;
                        break;
                    }
                }
                if (flag){
                    cout << "YES" << endl;
                }
            }
        }
        else{
            
            sort(arr, arr+n);
            
            bool flag = true;
            for(int i=1; i<n; i++){
                if(arr[i] >= arr[i-1]){
                    continue;
                }
                else{
                    cout<<"NO" << endl;
                    flag = false;
                    break;
                }
            }
            if (flag){
                cout << "YES" << endl;
            }
            
        }
        
        
    }
    
    
    
}
