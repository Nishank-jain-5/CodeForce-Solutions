#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    
    while(t--){
        
        long long n;
        cin >> n;
        
        long long e_cnt = 0;
        long long o_cnt = 0;
        
        vector<long long> v(n);
        for(long long i=0; i<n; i++){
            cin >> v[i];
            if(v[i] % 2 == 0){
                e_cnt++;
            }
            else{
                o_cnt++;
            }
        }
        
        if(n == 1){
            cout << "Moggity" << endl;
        }
        else{
            if(e_cnt != 0){
                if(e_cnt == 1 && o_cnt == 1){
                    cout << "Larpity" << endl;
                }
                else{
                    cout << "Moggity" << endl;
                }
            }
            else{
 
                if(o_cnt == 3){
                    cout << "Larpity" << endl;
                }
                else{
                    cout << "Moggity" << endl;
                }
            }
        }
    }
}
