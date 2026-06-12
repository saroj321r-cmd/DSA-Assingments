#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        string a, b;
        cin >> a >> b;

        string ans = "";
        int x = min(n,m);

        for (int i = 0; i < x; i++) {
            if (a[i] == b[i]) {
                ans += a[i];
            } else {
                break;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
