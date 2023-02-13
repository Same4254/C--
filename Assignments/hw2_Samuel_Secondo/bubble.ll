declare i32 @printf(i8*, ...)
declare i32* @malloc(i32)

%AIPair = type { i32*, i32*} 

declare void @initPair(%AIPair *, i32)
declare void @printPair(%AIPair *, i32)

@msg1 = constant [16 x i8] c"Initial Values\0A\00"
@msg2 = constant [2 x i8] c"\0A\00"
@msg3 = constant [15 x i8] c"Sorted Values\0A\00" 

define i32 @getKey(%AIPair* %pairs, i32 %index) {
  %keys_ptr_ptr = getelementptr inbounds %AIPair, %AIPair* %pairs, i32 0, i32 0
  %keys_ptr = load i32*, i32** %keys_ptr_ptr

  %ptr = getelementptr inbounds i32, i32* %keys_ptr, i32 %index
  %value = load i32, i32* %ptr

  ret i32 %value
}

define i32 @getValue(%AIPair* %pairs, i32 %index) {
  %values_ptr_ptr = getelementptr inbounds %AIPair, %AIPair* %pairs, i32 0, i32 1
  %values_ptr = load i32*, i32** %values_ptr_ptr

  %ptr = getelementptr inbounds i32, i32* %values_ptr, i32 %index
  %value = load i32, i32* %ptr

  ret i32 %value
}

define void @swap(%AIPair* %pairs, i32 %index_a, i32 %index_b) {
  %keys_ptr_ptr = getelementptr inbounds %AIPair, %AIPair* %pairs, i32 0, i32 0
  %values_ptr_ptr = getelementptr inbounds %AIPair, %AIPair* %pairs, i32 0, i32 1

  %keys_ptr = load i32*, i32** %keys_ptr_ptr
  %values_ptr = load i32*, i32** %values_ptr_ptr

  %key_a_ptr = getelementptr inbounds i32, i32* %keys_ptr, i32 %index_a
  %key_b_ptr = getelementptr inbounds i32, i32* %keys_ptr, i32 %index_b

  %value_a_ptr = getelementptr inbounds i32, i32* %values_ptr, i32 %index_a
  %value_b_ptr = getelementptr inbounds i32, i32* %values_ptr, i32 %index_b

  %key_a = load i32, i32* %key_a_ptr
  %key_b = load i32, i32* %key_b_ptr

  %value_a = load i32, i32* %value_a_ptr
  %value_b = load i32, i32* %value_b_ptr

  store i32 %key_a, i32* %key_b_ptr
  store i32 %key_b, i32* %key_a_ptr

  store i32 %value_a, i32* %value_b_ptr
  store i32 %value_b, i32* %value_a_ptr

  ret void
}

define i1 @pass(%AIPair* %pairs, i32 %length) {
entry:
  br label %range-check

range-check:
  %index_a = phi i32 [0, %entry], [%next_index, %loop]
  %did_swap = phi i1 [false, %entry], [%next_swap, %loop]

  %index_b = add i32 %index_a, 1

  %range-cmp = icmp sge i32 %index_b, %length
  br i1 %range-cmp, label %exit, label %iterate

iterate:
  %key_a = call i32 @getKey(%AIPair* %pairs, i32 %index_a)
  %key_b = call i32 @getKey(%AIPair* %pairs, i32 %index_b)

  %key_cmp = icmp sgt i32 %key_a, %key_b
  br i1 %key_cmp, label %swap, label %loop

swap:
  call void @swap(%AIPair* %pairs, i32 %index_a, i32 %index_b)
  br label %loop

loop:
  %next_swap = phi i1 [true, %swap], [%did_swap, %iterate]
  %next_index = add i32 %index_a, 1

  br label %range-check

exit:
  ret i1 %did_swap
}

define void @bubbleSort(%AIPair* %pairs, i32 %length) {
entry:
  br label %while-no-change

while-no-change:
  %any-change = call i1 @pass(%AIPair* %pairs, i32 %length)
  br i1 %any-change, label %while-no-change, label %exit

exit:
  ret void
}

define i32 @main() {
  %pairs = alloca %AIPair
  %keys_ptr = getelementptr inbounds %AIPair, %AIPair* %pairs, i32 0, i32 0
  %values_ptr = getelementptr inbounds %AIPair, %AIPair* %pairs, i32 0, i32 1

  %length = add i32 10, 0
  %byte_length = mul i32 %length, 32

  %t1 = call i32* @malloc(i32 %byte_length)
  %t2 = call i32* @malloc(i32 %byte_length)

  store i32* %t1, i32** %keys_ptr
  store i32* %t2, i32** %values_ptr

  %t3 = getelementptr [16 x i8],[16 x i8]* @msg1, i64 0, i64 0
  call i32 (i8*, ...) @printf(i8* %t3)

  call void @initPair(%AIPair* %pairs, i32 %length)
  call void @printPair(%AIPair* %pairs, i32 %length)

  %t4 = getelementptr [2 x i8],[2 x i8]* @msg2, i64 0, i64 0
  call i32 (i8*, ...) @printf(i8* %t4)

  call void @bubbleSort(%AIPair* %pairs, i32 %length)

  %t5 = getelementptr [15 x i8],[15 x i8]* @msg3, i64 0, i64 0
  call i32 (i8*, ...) @printf(i8* %t5)

  call void @printPair(%AIPair* %pairs, i32 %length)

  ret i32 0
}
