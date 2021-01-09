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

uint64_t SIZE = 5000;

uint64_t main(uint64_t argc, uint64_t* argv) {
  uint64_t index;
  uint64_t* arr;
  uint64_t r;

  arr = malloc(SIZE * 8);

  index = 0;
  while (index < SIZE) {
    interval(&r, 0, 1000, 1);
    if (r <= index) return 0;
    *(arr+index) = r;
    index = index + 1;
  }
  index = 0;
  while (index < SIZE) {
    VERIFIER_assert(*(arr+index) > index);
    index = index + 1;
  }

  return 0;
}