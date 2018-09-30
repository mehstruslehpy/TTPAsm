ldi b, 4
ld a, (b)
jmpi skip
add a, b
SKIP:
halt
