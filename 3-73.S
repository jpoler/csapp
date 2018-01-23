  .global find_range
find_range:
  pushq   %rbx
  pushq   %r8
  pushq   %r9
  pushq   %r10

  vxorps   %xmm1, %xmm1, %xmm1
  ucomiss %xmm1, %xmm0
  pushf
  popq   %rbx
  movq    %rbx, %r8
  movq    %rbx, %r9
  movq    %rbx, %r10
  andq    $0x01, %r8 # carry flag
  andq    $0x40, %r9 # zero flag
  testq   %r8, %r8
  ja      .carry_one
.carry_zero:
  testq   %r9, %r9
  ja      .equal
.greater:
  movq    $0x2, %rax
  jmp     .out
.equal:
  movq    $0x1, %rax
  jmp     .out
.carry_one:
  testq   %r9, %r9
  ja      .unordered
.less:
  movq    $0x0, %rax
  jmp     .out
.unordered:
  movq    $0x3, %rax
  jmp     .out
.out:
  popq    %r10
  popq    %r9
  popq    %r8
  popq    %rbx
  retq
