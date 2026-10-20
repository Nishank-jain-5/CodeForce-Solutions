#include <iostream>
#include <vector>
using namespace std;
 
 
int main(){
    int t;
    cin >> t;
    
    while(t--){
        
       int n;
       cin >> n;
       
       vector<int>v(n);
       int xorop = 0;
       
       for(int i=0; i<n; i++){
           cin >> v[i];
           xorop ^= v[i];
       }
       
       if(n == 1){
           cout << v[0] << endl;
       }
       else if(n % 2 == 1){
           cout << xorop << endl;
       }
       else{
           if(xorop == 0){
               cout << xorop << endl;
           }
           else{
               cout << -1 << endl;
           }
       }
       
       
       
       
       
        
    }
}
