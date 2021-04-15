/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/recursive-simple/fibo_2calls_25-2.c
  Data Model: ILP32

  Modifications:
  - Switched to non-deterministic initialization of `x` with `x <= 25`
  - Switched to different check `x < 15 || result > 610 || x == 15`

  termination : true
  unreach-call: true
*/

uint64_t fibo1(uint64_t n);
uint64_t fibo2(uint64_t n);

uint64_t fibo1(uint64_t n) {
  if (n < 1) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fibo2(n-1) + fibo2(n-2);
  }
}

uint64_t fibo2(uint64_t n) {
  if (n < 1) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    return fibo1(n-1) + fibo1(n-2);
  }
}

// fibo 1-30
// 1, 1, 2, 3, 5,
// 8, 13, 21, 34, 55,
// 89, 144, 233, 377, 610,
// 987, 1597, 2584, 4181, 6765,
// 10946, 17711, 28657, 46368, 75025,
// 121393, 196418, 317811, 514229, 832040

uint64_t main() {
  uint64_t x;
  uint64_t result;

  x = VERIFIER_nondet_uchar() % 26;
  result = fibo1(x);

  if (x < 15) {
    return 0;
  } else if (result > 610) {
    return 0;
  } else if (x != 15) {
    VERIFIER_error();
  }

  return 0;
}
