
#include <iostream>

using namespace std;


int main() {

   int n;
   cin >> n;
   vector<int> v(n);
   for (int i = 0; i < n; i++) {
      cin >> v[i];
   }

   vector<int> ans(n, -1);

   stack<int> s;

   for (int i = 0; i < n; i++) {
      while (!s.empty() && s.top() <= v[i])s.pop();
      if (!s.empty()) {
         ans[i] = s.top();
      }
      s.push(v[i]);
   }

   for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
   }


   return 0;
}
