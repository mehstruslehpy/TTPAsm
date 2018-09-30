sub d,d
main:
dec d
dec d
ldi b,4
st (d),b
dec d
dec b
st (d),b
dec d
dec b
st (d),b
ldi b,main_ret1
dec d
st (d),b
jmpi sub1
main_ret1:
inc d
inc d
dec d
st (d),a
ldi b,main_ret2
dec d
st (d),b
jmpi sub1
main_ret2:
inc d
inc d
st (d),a
inc d
halt
sub1:
cpr b,d
inc b
ld a,(b)
inc b
ld b,(b)
sub a,b
ld b,(d)
inc d
jmp b
