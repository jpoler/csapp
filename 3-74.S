  .global find_range
find_range:
  pushq   %r11
  vxorps  %xmm1, %xmm1, %xmm1
  ucomiss %xmm1, %xmm0
  movq    $0x2, %rax
  movq    $0x1, %r11  # zero case
  cmoveq  %r11, %rax
  movq    $0x0, %r11  # negative case
  cmovnaeq %r11, %rax
  movq    $0x3, %r11  # unordered case
  cmovpq  %r11, %rax
  popq    %r11        # cleanup
  retq
