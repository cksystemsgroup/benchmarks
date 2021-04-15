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

void VERIFIER_error() {
  uint64_t x;
  x = 10 / 0;
}

uint64_t SIZEOFUINT32 = 4;

uint64_t VERIFIER_nondet_uint() {
  uint64_t *x;
  x = malloc(8);
  *x = 0;  // touch memory
  read(0, x, SIZEOFUINT32);
  return *x;
}

uint64_t VERIFIER_two_pow_n(uint64_t n) {
  if (n == 0)
    return 1;
  else if (n < 64)
    return 2 * VERIFIER_two_pow_n(n - 1);
  else
    return 0;
}

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
