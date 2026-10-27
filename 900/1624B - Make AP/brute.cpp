#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        
        //agr first wrong he to
        long long num = 2*b - c;
        if(num > 0 && num % a == 0){
            cout << "YES" << "\n";
            continue;
        }
        
        //agr second wrong ho to
        num = (a+c)/2;
        if((a+c) % 2 == 0 && num % b == 0){
            cout << "YES" << "\n";
            continue;
        }
        
        //agr third ho to
        num = 2*b - a;
        if(num > 0 && num % c == 0){
            cout << "YES" << "\n";
            continue;
        }
        
        cout << "NO" << "\n";
        
    }
}
