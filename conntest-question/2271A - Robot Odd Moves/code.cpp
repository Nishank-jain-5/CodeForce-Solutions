#include <iostream>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    
    while(t--){
        int a, b;
        cin >> a >> b;
        
        if(a%2 == b%2){
            if(b<=a){
                cout << a << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
        else{
            if(b <= a+1){
                cout << a+1 << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
    }
}
