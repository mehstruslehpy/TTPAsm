ldi a, 5
ldi b, 255
st (b), a
jmpi skip
add a, b
SKIP:
halt
