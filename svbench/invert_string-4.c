/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/loops/invert_string-3.c
  Data Model: ILP32

  Modifications:
  - Completely different initialization and assertions of strings
  - Adapted induction variable of second loop to unsigned integers
  - Changed value of `max` from 5 to 1000

  termination : true
  unreach-call: false
*/

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
    *(str1 + i) = VERIFIER_nondet_ushort() % (max - i + 1);
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

  j = 0;
  while (j < max) {
    VERIFIER_assert(*(str2 + j) != max);
    j = j + 1;
  }

  return 0;
}