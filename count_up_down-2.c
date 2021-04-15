/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/loops/count_up_down-2.c
  Data Model: ILP32

  termination : true
  unreach-call: false
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

uint64_t SIZEOFUINT32 = 4;

uint64_t VERIFIER_nondet_uint() {
  uint64_t *x;
  x = malloc(8);
  *x = 0;  // touch memory
  read(0, x, SIZEOFUINT32);
  return *x;
}

uint64_t main() {
  uint64_t n;
  uint64_t x;
  uint64_t y;

  n = VERIFIER_nondet_uint();
  x = n;
  y = 0;

  while (x > 0) {
    x = x - 1;
    y = y + 1;
  }

  VERIFIER_assert(y != n);
}
