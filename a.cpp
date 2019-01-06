#include <iostream>
#include <cstdint>
#include <vector>
#include <cassert>

using namespace std;
typedef int64_t i_t;

void read(i_t& N, vector<i_t>& V) {
  cin >> N;
  V.resize(N);
  for(size_t i=0; i<N; i++) {
    i_t x;
    cin >> x;
    V[i] = x;
  }
}

int solve(const vector<i_t>& V) {
  return 0;
}

void test() {
  {
    vector<i_t> V = {0,1,2};
    assert(solve(V)==0);
  }
  cerr << "OK" << endl;
}

int main() {
  /*
  vector<i_t> V;
  i_t N;
  read(N, V);
  int ans = solve(V);
  cout << ans << endl;
  */
  test();

  return 0;
}

