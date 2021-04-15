/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/loop-acceleration/array_3-2.c
  Data Model: ILP32

  termination : true
  unreach-call: false
*/

uint64_t N = 1024;

uint64_t main() {
  uint64_t* A;
  uint64_t  i;

  A = malloc(N * SIZEOFUINT64);

  i = 0;
  while (i < N) {
    *(A + i) = VERIFIER_nondet_int();
    i = i + 1;
  }

  i = 0;
  // TODO: Fix incorrect port of `for (i = 0; i < N && A[i] != 0; i++)`
  while (i < N) {
    if (*(A + i) != 0) {
      i = i + 1;
    }
  }

  VERIFIER_assert(i <= N / 2);
}
