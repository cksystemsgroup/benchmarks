/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/loop-new/half.c
  Data Model: ILP32

  Modifications:
  - Replaced signed `a < b` comparison with call to `VERIFIER_slt(a, b)`
  - Defined `LARGE_INT` to be constant 2000

  termination : true
  unreach-call: true
*/

void VERIFIER_error() {
  uint64_t x;
  x = 10 / 0;
}

void VERIFIER_assert(uint64_t cond) {
  if (cond == 0) {
    VERIFIER_error();
  }
  return;
}

uint64_t SIZEOFINT32 = 4;
uint64_t INT32_MIN = 2147483648; // 1 << 31

uint64_t VERIFIER_nondet_int() {
  uint64_t *x;
  x = malloc(8);
  *x = 0;  // touch memory
  read(0, x, SIZEOFINT32);
  *x = *x - INT32_MIN;
  return *x;
}

uint64_t INT64_MIN = 9223372036854775808; // 1 << 63

uint64_t VERIFIER_slt(uint64_t a, uint64_t b) {
  return a + INT64_MIN < b + INT64_MIN;
}

uint64_t LARGE_INT = 2000;

uint64_t main() {
  uint64_t i;
  uint64_t n;
  uint64_t k;

  n = 0;
  k = VERIFIER_nondet_int();

  if (VERIFIER_slt(LARGE_INT, k) {
    return 0;
  } else if (VERIFIER_slt(k, -LARGE_INT)) {
    return 0;
  }

  i = 0;
  while (VERIFIER_slt(i, 2 * k)) {
    if (i % 2 == 0)
      n = n + 1;
    i = i + 1;
  }

  if (VERIFIER_slt(k, 0)) {
    VERIFIER_assert(n == 0);
    return 0;
  } else if (n == k) {
    return 0;
  } else {
    VERIFIER_error();
  }

  return 0;
}
