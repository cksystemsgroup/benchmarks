/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/recursive/McCarthy91-1.c
  Data Model: ILP32

  Modifications:
  - Switched from `int` to `uint` without loss of generality

  termination : true
  unreach-call: false
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

uint64_t f91(uint64_t x) {
  if (x > 100)
    return x - 10;
  else
    return f91(f91(x+11));
}

uint64_t main() {
  uint64_t x;
  uint64_t result;

  x = VERIFIER_nondet_uint();
  result = f91(x);

  if (result == 91) {
    return 0;
  } else if (x > 102) {
    if (result == x - 10)
      return 0;
    else VERIFIER_error();
  } else {
      VERIFIER_error();
  }
}
