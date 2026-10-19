#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        int prev = 0;   // pichla station (shuru me 0)
        int ans = 0;    // sabse bada gap

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;

            ans = max(ans, a - prev);  // 2 stations ke beech ka gap
            prev = a;                  // ab ye station "pichla" ban gaya
        }

        // last station se x tak jao aur wapas aao
        ans = max(ans, 2 * (x - prev));

        cout << ans << endl;
    }

    return 0;
}
