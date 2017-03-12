#include <iostream>
#include <set>
using namespace std;
long long ex_gcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long next_x, next_y;
  long long gcd = ex_gcd(b, a % b, next_x, next_y);
  x = next_y;
  y = next_x - (a / b) * next_y;
  return gcd;
}
int main() {
  long long start_A, start_B;
  long long jump_A, jump_B;
  long long L;
  cin >> start_A >> start_B >> jump_A >> jump_B >> L;

  long long a = jump_B - jump_A;
  long long b = L;
  long long c = start_A - start_B;
  if (a == 0) {
    cout << "Impossible" << endl;
    return 0;
  }

  long long x = 0;
  long long y = 0;
  long long gcd = ex_gcd(a, b, x, y);
  if (c % gcd) {
    cout << "Impossible" << endl;
    return 0;
  }

  long long times = c / gcd;

  long long ans = x * times - (times * x / b) * b;
  if (ans < 0) ans += b;
  cout << ans << endl;
  return 0;
};
