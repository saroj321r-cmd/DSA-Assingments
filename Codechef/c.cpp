#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> deck(n, 0);

        int card = k;
        int dir = 1;

        while (card > 0) {

            if (dir == 1) {
                for (int i = 0; i < n && card > 0; i++) {
                    deck[i] += card;
                    card--;
                }
            } else {
                for (int i = n - 1; i >= 0 && card > 0; i--) {
                    deck[i] += card;
                    card--;
                }
            }

            dir = - dir; 
        }

        int mx = 0;
        for (int i = 0; i < n; i++) {
            if (deck[i] > mx)
                mx = deck[i];
        }

        cout << mx << endl;
    }

    return 0;
}