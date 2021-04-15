/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/loops/sum01-2.c
  Data Model: ILP32

  Modifications:
  - Switched from `int` to `uint` without loss of generality

  termination : true
  unreach-call: true
*/

uint64_t a = 2;

uint64_t main() {
  uint64_t i;
  uint64_t n;
  uint64_t sn;

  n = VERIFIER_nondet_uint();
  sn = 0;

  if (n >= 1000)
    return 0;

  i = 1;
  while (i <= n) {
    sn = sn + a;
    i = i + 1;
  }

  if (sn == n*a)
    return 0;
  else if (sn == 0)
    return 0;
  else
    VERIFIER_error();
}
