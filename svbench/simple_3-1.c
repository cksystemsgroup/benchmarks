/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/loop-acceleration/simple_3-1.c
  Data Model: ILP32

  termination : true
  unreach-call: false
*/

uint64_t main() {
  uint64_t x;
  uint64_t N;

  x = 0;
  N = VERIFIER_nondet_ushort();

  while (x < N) {
    x = x + 2;
  }

  VERIFIER_assert(x % 2);
}
