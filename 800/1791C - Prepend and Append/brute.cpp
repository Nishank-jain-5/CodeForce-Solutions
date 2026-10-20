#include <iostream>
using namespace std;
 
 
int main(){
    int t;
    cin >> t;
    
    while(t--){
        
        int n;
        cin >> n;
        
        string s;
        cin >> s;
        
        
        int i = 0;
        int j = s.size()-1;
        
        while(true){
            
            if(i > j){
                cout << 0 << endl;
                break;
            }
            else if(i == j){
                cout << 1 << endl;
                break;
            }
            
            if((s[i] == '1' && s[j] == '0') || (s[i] == '0' && s[j] == '1')){
                i++;
                j--;
            }
            else{
                cout << j-i+1 << endl;
                break;
            }
        }
        
    }
}
