/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/loops/invert_string-3.c
  Data Model: ILP32

  Modifications:
  - Switched from `char` to `uchar` without loss of generality
  - Adapted induction variable of second loop to unsigned integers
  - Changed value of `max` from 5 to 1000

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

uint64_t SIZEOFUINT8 = 1;

uint64_t VERIFIER_nondet_uchar() {
  uint64_t *x;
  x = malloc(8);
  *x = 0;  // touch memory
  read(0, x, SIZEOFUINT8);
  return *x;
}

uint64_t SIZEOFUINT64 = 8;

uint64_t main() {
  uint64_t  max;
  uint64_t* str1;
  uint64_t* str2;
  uint64_t  i;
  uint64_t  j;

  max = 1000;

  str1 = malloc(max * SIZEOFUINT64);
  str2 = malloc(max * SIZEOFUINT64);

  i = 0;
  while (i < max) {
    *(str1 + i) = VERIFIER_nondet_uchar();
    i = i + 1;
  }
  *(str1 + (max-1)) = 0;

  j = 0;
  i = max;
  while (i > 0) {
    *(str2 + j) = *(str1 + (i-1));
    i = i - 1;
    j = j + 1;
  }

  j = max-1;
  i = 0;
  while (i < max) {
    VERIFIER_assert(*(str1 + i) == *(str2 + j));
    i = i + 1;
    j = j - 1;
  }

  return 0;
}
