/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/recursive/EvenOdd01-1.c
  Data Model: ILP32

  Modifications:
  - Switched from `int` to `uint` without loss of generality

  no-overflow : true
  termination : true
  unreach-call: true
*/

uint64_t is_odd(uint64_t n);
uint64_t is_even(uint64_t n);

uint64_t is_odd(uint64_t n) {
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return is_even(n - 1);
  }
}

uint64_t is_even(uint64_t n) {
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return 0;
  } else {
    return is_odd(n - 1);
  }
}

uint64_t main() {
  uint64_t n;
  uint64_t result;
  uint64_t mod;

  n = VERIFIER_nondet_uint();

  if (n < 0) {
    return 0;
  }

  result = is_odd(n);
  mod = n % 2;

  VERIFIER_assert(result == mod);
}
