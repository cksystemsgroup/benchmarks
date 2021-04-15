/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/bitvector-regression/recHanoi03-1.c
  Data Model: ILP32

  Modifications:
  - Switched from `int` to `uint` without loss of generality
  - Limited range of non-deterministic initialization to `n <= 63`
  - Replaced `1 << n` with call to `VERIFIER_two_pow_n(n)`

  termination : true
  unreach-call: true
*/

/*
 * This function returns the optimal amount of steps,
 * needed to solve the problem for n-disks
*/
uint64_t hanoi(uint64_t n) {
  if (n == 1) {
    return 1;
  }

  return 2 * (hanoi(n-1)) + 1;
}

uint64_t main() {
  uint64_t n;
  uint64_t result;

  n = VERIFIER_nondet_uint() % 64;
  if (n < 1)
    return 0;

  result = hanoi(n);

  if (result + 1 > 0) {
    if (result + 1 == VERIFIER_two_pow_n(n))
      return 0;
    else
      VERIFIER_error();
  } else {
    VERIFIER_error();
  }
}
