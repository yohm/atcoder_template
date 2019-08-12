#include <iostream>
#include <cstdint>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <cassert>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

#define REP(i,n) for(LL i=0, i##_len=(n); i<i##_len; ++i)

LL gcd(LL a, LL b) {
  if( b == 0 ) { return a; }
  return gcd(b, a % b);
}

template <LL MOD=1000000007> class MODLL {
public:
  LL x;
  MODLL(const LL _x) : x(_x % MOD) {};
  MODLL operator+(const MODLL rhs) const { return MODLL(*this) += rhs; }
  MODLL operator-(const MODLL rhs) const { return MODLL(*this) -= rhs; }
  MODLL operator*(const MODLL rhs) const { return MODLL(*this) *= rhs; }
  MODLL operator/(const MODLL rhs) const { return MODLL(*this) /= rhs; }
  MODLL& operator+=(const MODLL rhs) { x += rhs.x; x %= MOD; return *this; }
  MODLL& operator-=(const MODLL rhs) { x -= rhs.x; x %= MOD; if(x<0) x += MOD; return *this; }
  MODLL& operator*=(const MODLL rhs) { x *= rhs.x; x %= MOD; return *this; }
  MODLL inv() const {
    if(x == 0) { throw "does not have inverse"; }
    LL a = x, b = MOD, u = 1, v = 0;
    while (b) {
      long long t = a / b;
      a -= t * b; swap(a, b);
      u -= t * v; swap(u, v);
    }
    u %= MOD;
    if (u < 0) u += MOD;
    return MODLL(u);
  }
  MODLL& operator/=(const MODLL rhs) { (*this) *= rhs.inv(); return *this; }
  MODLL pow(ULL n) const {
    MODLL res = 1;
    MODLL a = x;
    while (n > 0) {
      if (n & 1) res *= a;
      a = a * a;
      n >>= 1;
    }
    return res;
  }
};

typedef MODLL<> ML;

void test() {
  {
    ML x = 3;
    assert(x.pow(45).x == 644897553);
  }
  {
    for(int i=1; i<13; i++) {
      MODLL<13> x = i;
      assert( (x.inv().x * i) % 13 == 1 );
    }
  }
}


int main() {
  // test();

  return 0;
}

