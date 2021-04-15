/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/loop-acceleration/simple_3-1.c
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

uint64_t SIZEOFUINT16 = 2;

uint64_t VERIFIER_nondet_ushort() {
  uint64_t *x;
  x = malloc(8);
  *x = 0;  // touch memory
  read(0, x, SIZEOFUINT16);
  return *x;
}

uint64_t main() {
  uint64_t x;
  uint64_t N;

  x = 0;
  N = VERIFIER_nondet_ushort();

  while (x < N) {
    x = x + 2;
  }

  VERIFIER_assert(x % 2);
}
