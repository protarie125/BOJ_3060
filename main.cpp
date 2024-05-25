#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;

ll t, n;
vl pre(6);
vl req(6, 0);

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> t;
  while (0 < (t--)) {
    cin >> n;
    for (auto&& x : pre) {
      cin >> x;
    }

    auto ans = 0LL;
    while (true) {
      ++ans;
      auto sum = 0LL;
      for (const auto& x : pre) {
        sum += x;
      }
      if (n < sum) {
        cout << ans << '\n';
        break;
      }

      for (auto i = 0; i < 6; ++i) {
        req[i] = pre[i];
        req[i] += pre[(i + 1) % 6];
        req[i] += pre[(i + 5) % 6];
        req[i] += pre[(i + 3) % 6];
      }

      pre = req;
    }
  }

  return 0;
}