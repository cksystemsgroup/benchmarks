/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/loop-new/count_by_nondet.c
  Data Model: ILP32

  Modifications:
  - Switched from `int` to `uint` without loss of generality
  - Defined `LARGE_INT` to be constant 2000

  termination : true
  unreach-call: true
*/

void  VERIFIER_error() {
  uint64_t x;
  x = 10 / 0;
}

void VERIFIER_assert(uint64_t cond) {
  if (cond == 0) {
    VERIFIER_error();
  }
  return;
}

uint64_t SIZEOFUINT32 = 4;

uint64_t VERIFIER_nondet_uint() {
  uint64_t *x;
  x = malloc(8);
  *x = 0;  // touch memory
  read(0, x, SIZEOFUINT32);
  return *x;
}

uint64_t LARGE_INT = 2000;

uint64_t main() {
  uint64_t i;
  uint64_t k;
  uint64_t j;

  i = 0;
  k = 0;

  while(i < LARGE_INT) {
    j = VERIFIER_nondet_uint()
    if (1 > j) {
      return 0;
    } else if (j >= LARGE_INT) {
      return 0;
    }

    i = i + j;
    k = k + 1;
  }

  VERIFIER_assert(k <= LARGE_INT);

  return 0;
}
