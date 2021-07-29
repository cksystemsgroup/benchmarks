KLEE := klee
MONSTER := monster
SELFIE := $(shell which selfie)

ARR_SOURCES := $(sort $(wildcard array_sorting/*.c))
ARR_BINARIES := $(patsubst %.c,%.m,$(ARR_SOURCES))

# TODO: Remove entries from list once errors are fixed.
MONSTER_FILTER =
MONSTER_FILTER += svbench/EvenOdd01-1.monster         # triggers SLTU panic
MONSTER_FILTER += svbench/MultCommutative-2.monster   # triggers SLTU panic
MONSTER_FILTER += svbench/array_3-2.monster           # benchmark is borked
MONSTER_FILTER += svbench/count_up_down-1.monster     # takes very long
MONSTER_FILTER += svbench/fibo_2calls_25-2_1.monster  # triggers REMU panic
MONSTER_FILTER += svbench/id2_b5_o10.monster          # takes very long
MONSTER_FILTER += svbench/id_o1000.monster            # takes very long
MONSTER_FILTER += svbench/invert_string-3.monster     # takes very long
MONSTER_FILTER += svbench/invert_string-4.monster     # triggers REMU panic
MONSTER_FILTER += svbench/jain_1.monster              # takes very long
MONSTER_FILTER += svbench/jain_2.monster              # takes very long
MONSTER_FILTER += svbench/recHanoi03-1.monster        # triggers REMU panic
MONSTER_FILTER += svbench/simple_3-2.monster          # takes very long
MONSTER_FILTER += svbench/sum02-2.monster             # triggers SLTU panic
MONSTER_FILTER += svbench/sum_non_eq-1.monster        # takes very long

SV_SOURCES := $(sort $(wildcard svbench/*.c))
SV_BINARIES := $(patsubst %.c,%.m,$(SV_SOURCES))
SV_BYTECODE := $(patsubst %.c,%.bc,$(SV_SOURCES))
SV_OBJECTS := $(patsubst %.c,%.o,$(SV_SOURCES))
SV_MONSTER1 := $(patsubst %.c,%.monster,$(SV_SOURCES))
SV_MONSTER := $(filter-out $(MONSTER_FILTER),$(SV_MONSTER1))

.PHONY: monster all clean

monster: $(SV_MONSTER)

all: $(ARR_BINARIES) $(SV_BINARIES) $(SV_BYTECODE) $(SV_OBJECTS)

clean:
	rm -f $(ARR_BINARIES)
	rm -f $(SV_BINARIES)
	rm -f $(SV_BYTECODE)
	rm -f $(SV_OBJECTS)

array_sorting/%.m: array_sorting/%.c
	$(SELFIE) -c $< -o $@

%.m: %.c cstar-lib.c
	$(SELFIE) -c cstar-lib.c $< -o $@

%.o: %.c cstar-lib.c
	$(CC) -D'uint64_t=unsigned long' -w --include cstar-lib.c $< -o $@

%.monster: %.m
	$(MONSTER) execute $< --execution-depth 10000000

%.boolector: %.m
	$(MONSTER) execute $< --execution-depth 10000000 --solver boolector

%.bc: %.c
	clang -Werror -Wno-main-return-type -Wno-return-type -O0 \
	      -Xclang -disable-O0-optnone -I ../klee/include \
	      -include cstar-klee.h -emit-llvm -c $< -o $@

%.klee: %.bc
	$(KLEE) $<
