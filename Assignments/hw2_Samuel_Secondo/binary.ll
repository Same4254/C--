declare i32 @printf(i8*, ...)

@msg = constant [9 x i8] c"got: %d\0A\00"
@data = constant [10 x i32] [i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 16, i32 17, i32 18, i32 19]

define i32 @binary_search(i32* %list, i32 %length, i32 %key) {
entry:
  br label %loop_check

loop_check:
  %left_index = phi i32 [0, %entry], [%next_left_index, %next]
  %right_index = phi i32 [%length, %entry], [%next_right_index, %next]

  %loop_condition = icmp sle i32 %left_index, %right_index
  br i1 %loop_condition, label %loop, label %exit

loop:
  %t1 = add i32 %left_index, %right_index
  %middle_index = sdiv i32 %t1, 2
  %middle_ptr = getelementptr inbounds i32, i32* %list, i32 %middle_index
  %middle_value = load i32, i32* %middle_ptr

  %less_than_cmp = icmp slt i32 %middle_value, %key
  %greater_than_cmp = icmp sgt i32 %middle_value, %key

  ; How do I avoid doing both branches of calculations here?
  %t2 = add i32 %middle_index, 1
  %t3 = add i32 %right_index, 0

  %t4 = add i32 %left_index, 0
  %t5 = sub i32 %middle_index, 1

  br i1 %less_than_cmp, label %next, label %other_compare
other_compare:
  br i1 %greater_than_cmp, label %next, label %exit

next:
  ; can't put the temporary calculations here because phi calls must be first

  %next_left_index = phi i32 [%t2, %loop], [%t4, %other_compare]
  %next_right_index = phi i32 [%t3, %loop], [%t5, %other_compare]

  br label %loop_check

exit:
  %ret_val = phi i32 [%middle_index, %other_compare], [-1, %loop_check]
  ret i32 %ret_val
}

define i32 @main() {
  %t0 = bitcast [10 x i32]* @data to i32*
  %t1 = call i32 @binary_search(i32* %t0, i32 10, i32 14)
  %t2 = getelementptr [9 x i8],[9 x i8]* @msg, i64 0, i64 0
  %t3 = call i32 (i8*, ...) @printf(i8* %t2, i32 %t1)

  ret i32 %t3
}
