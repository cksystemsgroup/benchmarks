/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/bitvector/sum02-2.c
  Data Model: ILP32

  termination : true
  unreach-call: true
*/

uint64_t main() {
  uint64_t i;
  uint64_t n;
  uint64_t sn;
  uint64_t nl;
  uint64_t gauss;

  n = VERIFIER_nondet_uint();
  sn = 0;

  i = 0;
  while (i <= n) {
    sn = sn + i;
    i = i + 1;
  }

  nl = n;
  gauss = (nl*(nl+1))/2;

  if (sn == gauss)
    return 0;
  else if (sn == 0)
    return 0;
  else
    VERIFIER_error();
}
