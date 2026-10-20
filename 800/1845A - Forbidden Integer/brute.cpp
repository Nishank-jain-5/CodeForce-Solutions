#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    
    int t;
    cin >> t;
    
    while(t--){
        
        int n, k, x;
        cin >> n >> k >> x;
        
        int num = n;
        vector<int> v;
        
        if(x != 1){
            while(num--){
                v.push_back(1);
            }
        }
        else{
            if(n % 2 == 0){
                if(k >= 2){
                    int temp = num / 2;
                    while(temp--){
                        v.push_back(2);
                    }
                }
            }
            else{
                if(k ==1 || k == 2){
                    v.push_back(0);
                }
                else{
                    v.push_back(3);
                    num = num - 3;
                    int temp = num / 2;
                    
                    while(temp--){
                        v.push_back(2);
                    }
                }
                
            }
        }
        
        int sum = 0;
        for(auto i : v){
            sum += i;
        }
        
        if(sum != n){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            cout << v.size() << endl;
            for(auto i : v){
                cout << i << " ";
            }
            cout << endl;
        }
        
        
        
        
    }
    
    
}
