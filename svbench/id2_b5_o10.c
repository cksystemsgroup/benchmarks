/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/recursive-simple/id2_b5_o10.c
  Data Model: ILP32

  termination : true
  unreach-call: true
*/

uint64_t id(uint64_t x);
uint64_t id2(uint64_t x);

uint64_t id(uint64_t x) {
  uint64_t ret;

  if (x == 0) return 0;

  ret = id2(x-1) + 1;

  if (ret > 5) return 5;

  return ret;
}

uint64_t id2(uint64_t x) {
  uint64_t ret;

  if (x == 0) return 0;

  ret = id(x-1) + 1;

  if (ret > 5) return 5;

  return ret;
}

uint64_t main() {
  uint64_t input;
  uint64_t result;

  input = VERIFIER_nondet_uint();
  result = id(input);

  if (result == 10) {
    VERIFIER_error();
  }
}
