/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/loop-acceleration/phases_2-2.c
  Data Model: ILP32

  Modifications:
  - Changed `x = 1` to `x = 2` during initialization

  termination : false  // TODO: true now?
  unreach-call: true   // TODO: false now?
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
  uint64_t x;
  uint64_t y;

  x = 2;
  y = VERIFIER_nondet_uint();

  if (y <= 0) return 0;

  while (x < y) {
    if (x < y / x) {
      x = x * x;
    } else {
      x = x + 1;
    }
  }

  VERIFIER_assert(x == y);
}
