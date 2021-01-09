void VERIFIER_error() {
  uint64_t x;
  x = 10 / 0;
}

void VERIFIER_assert(uint64_t cond) {
  if (cond == 0) {
    VERIFIER_error();
  }
  return;
}

uint64_t LARGE_INT = 100;

uint64_t main() {
  uint64_t n;
  uint64_t m;
  uint64_t k;
  uint64_t i;
  uint64_t j;

  interval(&n, 30, 100, 1);
  interval(&m, 30, 100, 1);
  k = 0;

  // i = 0;
  interval(&i, 0, 2, 1);
  while (i < n) {
    j = 0;
    while (j < m) {
      k = k + 1;
      j = j + 1;
    }
    i = i + 1;
  }

  VERIFIER_assert(k >= 80);

  return 0;
}
