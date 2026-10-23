#include <iostream>
using namespace std;
 
int main(){
    int t;
    cin >> t;
 
    while(t--){
        long long n;
        cin >> n;
 
        long long min = -1;
        long long max = -1;
 
        if(n % 2 == 1 || n < 4){
            cout << -1 << "\n";
            continue;
        }
        else{
            if(n % 4 == 0){
                max = n / 4;
            }
            else{                       
                max = 1 + (n - 6) / 4;
            }
 
            if(n % 6 == 0){
                min = n / 6;
            }
            else if(n % 6 == 4){
                min = 1 + (n - 4) / 6;
            }
            else{               
                min = 2 + (n - 8) / 6;
            }
 
            cout << min << " " << max << "\n";
        }
    }
}
