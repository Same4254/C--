# C--

This is a compiler for the language C-- made with Flex, Bison, and LLVM (See [The Language](#The Language)). This was an independent study done in one semester with Professor Laurent Michel. No starting code provided, everything here is of my own work and understanding from *Compilers: Principles, Techniques, & Tools" by Aho et al.  

I make no promise that this compiler is 100% correct nor do I attest to the quality of the code thereof. The intent of this project was to learn about how compilers work and the challenges an implementation faces. In the long-term I wish to gain a further understanding of compiler optimizations; this progject was the first step to that end. 

However, core features and concepts of the language to function properly. OOP inheritence of classes allows for a child class to inherit member variables and methods from its parent, while also allowing the child to overwrite the parent method. Basic computation such as calculating the fibonacci sequence recursively also works. Arrays of primitive values and classes also function similarly to how they behave in Java, where the list declares to store parent type, but does allow child instances to be inserted into the list. These objects each have a ***vtable*** to dispatch functions. 

## The Language

C-- is a very simple language with the grammar as shown below. The language is meant to allow classes, inheritence, arrays, and functions. Classes can inherit from another class to access the parent member variables and overwrite/use parent functions. This is accomplished with a vtable pointer that is at the starting address of every object which points to a list of function pointers that are the class' methods. 

![](/Language.png)

It's also worth noting that this language itself does not immediately allow for parsing with only 1 lookahead token. To allow Flex to generate a parser without conflicts, parts of the grammar had to be inlined, so to speak. In addition, associativity rules had to be given in order for it to resolve other conflicts. The only conflict that remains now is the infamous if-else ambiguity. This is conflict is automatically handled by the parser, however, so the langauge itself needs no change.

## Usage

After compiling with CMake, the compiler takes the input source code through stdin. Thus to run the compiler do the following:
```
./c-- < ./Tests/test2.txt
```
This will output the LLVM IR to stdout in all its glory. If you wish to skip this step, you make go into the Tests folder where there is a small Makefile which will compile the source of `test2.txt` and compile it into an executable with clang. This will only work on Linux, and perhaps Mac. It's also worth noting that this assumes LLVM-10. Using a newer version can cause issues. 

## Example

The following is an example program included in the project which demonstrates it can do the basic features set out by the language. It's worth noting as well that the entry point to the program is the Main class' constructor. For a valid C-- program, there must be a Main class present. 

```java
class Animal {
    int x;

    Animal() {
        this.x = 10;
    }

    void func() {
        PRINT_INT(x);
    }

    void speak() {
        PRINT_INT(0);
    }
};

class Dog extends Animal {

    Dog() {
        this.x = 100;
    }

    void speak() {
        PRINT_INT(1);
    }
};

class Cat extends Animal {
    
    Cat() {
        this.x = 200;
    }

    void speak() {
        PRINT_INT(2);
    }

    void inc() {
        x = x + 1;
    }
};

class X {
    int n;
    int[] arr;

    X(int n) {
        this.n = n;
        this.arr = new int[n];

        int i;
        i = 0;
        while (i < n) {
            arr[i] = i;
            i = i + 1; 
        }
    }

    void printArr() {
        int i;
        i = 0;

        PRINT_LN();
        while (i < n) {
            PRINT_INT(arr[i]);
            i = i + 1; 
        }
        PRINT_LN();
    }
};

class Y {
    int n;
    X[] xs;

    Y(int n) {
        this.n = n;
        this.xs = new X[n];

        int i;
        i = 0;
        while (i < n) {
            xs[i] = new X(i + 1);
            i = i + 1;
        }
    }

    void printArrs() {
        int i;
        i = 0;
        while (i < n) {
            xs[i].printArr();
            i = i + 1;
        }
    }
};

class Main {
    int fib(int n) {
        if (n == 0) {
            return 0;
        }

        if (n == 1) {
            return 1;
        }

        return fib(n - 1) + fib(n - 2);
    }

    Main() {
        Dog dog;
        dog = new Dog();

        dog.func();
        dog.speak();

        PRINT_LN();

        Cat cat;
        cat = new Cat();

        cat.func();
        cat.speak();
        cat.inc(); 
        cat.func();

        X x;
        x = new X(10);

        x.printArr();

        int n;
        n = 5;

        Y y;
        y = new Y(n);

        y.printArrs();

        Animal[] animals;
        animals = new Animal[2];

        animals[0] = new Dog();
        animals[1] = new Cat();

        animals[0].speak();
        animals[1].speak();

        PRINT_LN();

        int i;
        i = 0;
        while (i < 10) {
            PRINT_INT(fib(i));
            i = i + 1;
        }
    }
};
```
When compiled and ran, it has the following output:
```
100
1

200
2
201

0
1
2
3
4
5
6
7
8
9


0


0
1


0
1
2


0
1
2
3


0
1
2
3
4

1
2

0
1
1
2
3
5
8
13
21
34
```
The reader may comb through the code and verify that this is correct, but this demonstrates that classes can extend from a parent, overwrite functions, access member variables, access an object's content, and can generate the fibonacci sequence.
