/*
  This file is a C* translation of the original implementation (inspired from github.com/sosy-lab/sv-benchmarks)
*/

uint64_t main() {
  uint64_t x;
  uint64_t y;
  uint64_t i;

  x = 1;
  y = 1;

  i = 0;
  while(i < 10000) {
    x = x + 2 * interval(0, -1, 1);
    y = y + 2 * interval(0, -1, 1);

    VERIFIER_assert(x + y != 1);
    i = i + 1;
  }
  return 0;
}