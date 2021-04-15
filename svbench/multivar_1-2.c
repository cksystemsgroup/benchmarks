/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/loop-acceleration/multivar_1-2.c
  Data Model: ILP32

  termination : true
  unreach-call: false
*/

uint64_t main() {
  uint64_t x;
  uint64_t y;

  x = VERIFIER_nondet_uint();
  y = x + 1;

  while (x < 1024) {
    x = x + 1;
    y = y + 1;
  }

  VERIFIER_assert(x == y);
}
