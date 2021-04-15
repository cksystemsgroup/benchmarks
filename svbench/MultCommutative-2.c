/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/recursive/MultCommutative-2.c
  Data Model: ILP32

  Modifications:
  - Switched from `int` to `uint` without loss of generality

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

// Multiplies two integers n and m
uint64_t mult(uint64_t n, uint64_t m) {
  if (m < 0) {
    return mult(n, -m);
  }

  if (m == 0) {
    return 0;
  }

  return n + mult(n, m - 1);
}

uint64_t main() {
  uint64_t m;
  uint64_t n;
  uint64_t res1;
  uint64_t res2;

  m = VERIFIER_nondet_uint();
  if (m < 0)
    return 0;
  else if (m > 46340)
    return 0;

  n = VERIFIER_nondet_uint();
  if (n < 0)
    return 0;
  else if (n > 46340)
    return 0;

  res1 = mult(m, n);
  res2 = mult(n, m);

  if (res1 != res2) {
    if (m > 0)
      if (n > 0)
        VERIFIER_error();
  }

  return 0;
}
