/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/loop-acceleration/phases_2-2.c
  Data Model: ILP32

  Modifications:
  - Changed `x = 1` to `x = 2` during initialization

  termination : false  // TODO: true now?
  unreach-call: true   // TODO: false now?
*/

uint64_t main() {
  uint64_t x;
  uint64_t y;

  x = 2;
  y = VERIFIER_nondet_uint();

  if (y <= 0) return 0;

  while (x < y) {
    if (x < y / x) {
      x = x * x;
    } else {
      x = x + 1;
    }
  }

  VERIFIER_assert(x == y);
}
