/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/bitvector/jain_1-1.c
  Data Model: ILP32

  Modifications:
  - Limited endless loop to 10000 iterations instead
  - Changed termination property to `true`

  termination : true
  unreach-call: true
*/

uint64_t main() {
  uint64_t x;
  uint64_t i;

  x = 1;

  i = 0;
  while(i < 10000) {
    x = x + 2 * VERIFIER_nondet_uint();

    VERIFIER_assert(x != 0);

    i = i + 1;
  }

  return 0;
}
