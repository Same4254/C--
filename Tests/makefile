OFILES= test2.o
CPATH=/usr/bin/
LLVMASY=$(CPATH)llvm-as-10
LLVMOPT=$(CPATH)opt-10
LLVMLC=$(CPATH)llc-10
AS=clang -c -g
LD=clang -g

all: test2

test2: $(OFILES)
	$(LD) $(OFILES) $(LIBS) -o $@

%.o : %.s
	$(AS) $< -o $@

%.s : %.bc
	$(LLVMLC) $< -o $@

%.bc : %.ll
	$(LLVMASY) $< -o $@

clean:
	rm *.o *.s *.bc test2
