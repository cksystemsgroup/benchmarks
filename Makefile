SELFIE := $(shell which selfie)

SV_SOURCES := $(shell grep -l 'sv-benchmarks' *.c | sort)
SV_BINARIES := $(patsubst %.c,%.m,$(SV_SOURCES))

.PHONY: all clean

all: $(SV_BINARIES)

clean:
	rm -f $(SV_BINARIES)

%.m: %.c
	$(SELFIE) -c $< -o $@
