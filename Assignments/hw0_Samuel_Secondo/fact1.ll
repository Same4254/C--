declare i32 @printf(i8*, ...)

@msg = constant [9 x i8] c"got: %d\0A\00"

define i32 @fact1(i32 %a) {
entry:
  br label %loop

loop:
  %num = phi i32 [%a, %entry], [%next_num, %loop]
  %product = phi i32 [1, %entry], [%next_product, %loop]

  %next_num = sub i32 %num, 1
  %next_product = mul i32 %product, %num

  %cmp = icmp eq i32 %num, 1
  br i1 %cmp, label %exit, label %loop

exit:
  ret i32 %next_product
}

; Definition of main function
define i32 @main() {   ; i32()*
  %t1 = getelementptr [9 x i8],[9 x i8]* @msg, i64 0, i64 0
  %t2 = call i32 @fact1(i32 5)
  %t3 = call i32 (i8*, ...) @printf(i8* %t1, i32 %t2)
  
  ret i32 0
}
