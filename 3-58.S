.globl _decode3
_decode3:
  subq  %rdx, %rsi
  imulq %rsi, %rsi
  movq  %rsi, %rax
  salq  $63, %rax
  sarq  $63, %rax
  xorq  %rdi, %rax
  ret
