/*
  This file is a C* translation of the original implementation (inspired from github.com/sosy-lab/sv-benchmarks)
  done by Alireza Abyaneh.
*/

uint64_t main() {
  uint64_t x;
  uint64_t i;

  x = 1;

  i = 0;
  while(i < 10000) {
    x = x + 2 * input(0, -1, 1);

    assert_begin();
    assert(x != 0);
    assert_end();
    i = i + 1;
  }
  return 0;
}
