/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/loops/count_up_down-1.c
  Data Model: ILP32

  termination : true
  unreach-call: true
*/

uint64_t main() {
  uint64_t n;
  uint64_t x;
  uint64_t y;

  n = VERIFIER_nondet_uint();
  x = n;
  y = 0;

  while(x > 0) {
    x = x - 1;
    y = y + 1;
  }

  VERIFIER_assert(y == n);
}
