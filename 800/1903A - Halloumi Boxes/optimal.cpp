#include <bits/stdc++.h>
using namespace std;

int main(){
  
    int t;
    cin >> t;
  
    while(t--){
      
        int n, k;
        cin >> n >> k;
        int arr[n];
        
      for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
      
        if(is_sorted(arr, arr+n) || k > 1){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}
