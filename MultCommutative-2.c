/*
  The C* port of MultCommutative-2.c from github.com/sosy-lab/sv-benchmarks
  for any information about the LICENCE see github.com/sosy-lab/sv-benchmarks

  termination : true
  unreach-call: true
*/

void VERIFIER_error() {
  uint64_t x;
  x = 10 / 0;
}

// multiplies two integers n and m
uint64_t mult(uint64_t n, uint64_t m) {
  if (m < 0) {
    return mult(n, -m);
  }

  if (m == 0) {
    return 0;
  }

  return n + mult(n, m - 1);
}

uint64_t main() {
  uint64_t m;
  uint64_t n;
  uint64_t res1;
  uint64_t res2;

  interval(&m, 0, -1, 1);
  if (m < 0)
    return 0;
  else if (m > 46340)
    return 0;

  interval(&n, 0, -1, 1);
  if (n < 0)
    return 0;
  else if (n > 46340)
    return 0;

  res1 = mult(m, n);
  res2 = mult(n, m);

  if (res1 != res2) {
    if (m > 0)
      if (n > 0)
        VERIFIER_error();
  }

  return 0;
}