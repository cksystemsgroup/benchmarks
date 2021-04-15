/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/recursive-simple/sum_non_eq-1.c
  Data Model: ILP32

  termination : true
  no-overflow : false
*/

void VERIFIER_error() {
  uint64_t x;
  x = 10 / 0;
}

uint64_t SIZEOFINT32 = 4;

uint64_t VERIFIER_nondet_int() {
  uint64_t *x;
  x = malloc(8);
  *x = 0;  // touch memory
  read(0, x, SIZEOFINT32);
  return *x;
}

uint64_t sum(uint64_t n, uint64_t m) {
  if (n == 0) {
    return m;
  } else {
    return sum(n - 1, m + 1);
  }
}

uint64_t main() {
  uint64_t a;
  uint64_t b;
  uint64_t result;

  a = VERIFIER_nondet_int();
  b = VERIFIER_nondet_int();

  result = sum(a, b);

  if (result != a + b) {
    VERIFIER_error();
  }

  return 0;
}
