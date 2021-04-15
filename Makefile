SELFIE := $(shell which selfie)

ARR_SOURCES := $(sort $(wildcard array_sorting/*.c))
ARR_BINARIES := $(patsubst %.c,%.m,$(ARR_SOURCES))

SV_SOURCES := $(sort $(wildcard svbench/*.c))
SV_BINARIES := $(patsubst %.c,%.m,$(SV_SOURCES))
SV_OBJECTS := $(patsubst %.c,%.o,$(SV_SOURCES))

.PHONY: all clean

all: $(ARR_BINARIES) $(SV_BINARIES) $(SV_OBJECTS)

clean:
	rm -f $(ARR_BINARIES)
	rm -f $(SV_BINARIES)
	rm -f $(SV_OBJECTS)

array_sorting/%.m: array_sorting/%.c
	$(SELFIE) -c $< -o $@

svbench/%.m: svbench/%.c cstar-lib.c
	$(SELFIE) -c cstar-lib.c $< -o $@

svbench/%.o: svbench/%.c cstar-lib.c
	$(CC) -D'uint64_t=unsigned long' -w --include cstar-lib.c $< -o $@
