OFILES= fact1.o
OFILES1= fact2.o
OFILES2= fib.o
CPATH=/usr/bin/
LLVMASY=$(CPATH)llvm-as-10
LLVMOPT=$(CPATH)opt-10
LLVMLC=$(CPATH)llc-10
AS=clang -c -g
LD=clang -g

all: fact1 fact2 fib

fact1: $(OFILES)
	$(LD) $(OFILES) $(LIBS) -o $@

fact2: $(OFILES1)
	$(LD) $(OFILES1) $(LIBS) -o $@

fib: $(OFILES2)
	$(LD) $(OFILES2) $(LIBS) -o $@

%.o : %.s
	$(AS) $< -o $@

%.s : %.bc
	$(LLVMLC) $< -o $@

%.bc : %.ll
	$(LLVMASY) $< -o $@

clean:
	rm *.o *.s *.bc fact1 fact2 fib
