OFILES= binary.o
OFILES1= bubble.o misc.o
CPATH=/usr/bin/
LLVMASY=$(CPATH)llvm-as-10
LLVMOPT=$(CPATH)opt-10
LLVMLC=$(CPATH)llc-10
AS=clang -c -g
LD=clang -g

all: binary bubble

binary: $(OFILES)
	$(LD) $(OFILES) $(LIBS) -o $@

bubble: $(OFILES1)
	$(LD) $(OFILES1) $(LIBS) -o $@

%.o : %.s
	$(AS) $< -o $@

%.s : %.bc
	$(LLVMLC) $< -o $@

%.bc : %.ll
	$(LLVMASY) $< -o $@

%.o : %.c
	$(AS) $< -o $@

clean:
	rm *.o *.s *.bc binary bubble
