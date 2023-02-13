declare i32 @printf(i8*, ...)

@msg = constant [9 x i8] c"got: %d\0A\00"

define i32 @fact2(i32 %a) {
  %cmp = icmp eq i32 %a, 1
  br i1 %cmp, label %exit, label %loop

loop:
  %t1 = sub i32 %a, 1
  %t2 = call i32 @fact2(i32 %t1)
  %t3 = mul i32 %a, %t2
  ret i32 %t3

exit:
  ret i32 1
}

; Definition of main function
define i32 @main() {   ; i32()*
  %t1 = getelementptr [9 x i8],[9 x i8]* @msg, i64 0, i64 0
  %t2 = call i32 @fact2(i32 5)
  %t3 = call i32 (i8*, ...) @printf(i8* %t1, i32 %t2)
  
  ret i32 0
}
