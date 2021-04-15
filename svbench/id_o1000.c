/*
  The C* port of a benchmark from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  Original: sv-benchmarks/c/recursive-simple/id_o1000.c
  Data Model: ILP32

  termination : true
  unreach-call: false
*/

uint64_t id(uint64_t x) {
  if (x == 0) return 0;
  return id(x-1) + 1;
}

uint64_t main() {
  uint64_t input;
  uint64_t result;

  input = VERIFIER_nondet_uint();
  result = id(input);

  if (result == 1000) {
    VERIFIER_error();
  }
}
