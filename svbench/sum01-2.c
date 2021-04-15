/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/loops/sum01-2.c
  Data Model: ILP32

  termination : true
  unreach-call: true
*/

void VERIFIER_error() {
  uint64_t x;
  x = 10 / 0;
}

uint64_t SIZEOFINT32 = 4;

uint64_t VERIFIER_nondet_int() {
  uint64_t *x;
  x = malloc(8);
  *x = 0;  // touch memory
  read(0, x, SIZEOFINT32);
  return *x;
}

uint64_t a = 2;

uint64_t main() {
  uint64_t i;
  uint64_t n;
  uint64_t sn;

  n = VERIFIER_nondet_int();
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
