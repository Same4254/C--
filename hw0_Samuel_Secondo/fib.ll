declare i32 @printf(i8*, ...)

@msg = constant [9 x i8] c"got: %d\0A\00"

define i32 @fib(i32 %n) {
  %cmp_zero = icmp eq i32 %n, 0
  %cmp_one = icmp eq i32 %n, 1

  %cmp = or i1 %cmp_zero, %cmp_one

  br i1 %cmp, label %exit, label %loop

loop:
  %n_1 = sub i32 %n, 1
  %n_2 = sub i32 %n, 2

  %t1 = call i32 @fib(i32 %n_1)
  %t2 = call i32 @fib(i32 %n_2)

  %t3 = add i32 %t1, %t2
  ret i32 %t3

exit:
  ret i32 %n
}

; Definition of main function
define i32 @main() {   ; i32()*
  %t1 = getelementptr [9 x i8],[9 x i8]* @msg, i64 0, i64 0
  %t2 = call i32 @fib(i32 6)
  %t3 = call i32 (i8*, ...) @printf(i8* %t1, i32 %t2)
  
  ret i32 0
}
