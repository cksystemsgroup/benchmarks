/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/bitvector/sum02-2.c
  Data Model: ILP32

  termination : true
  unreach-call: true
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
