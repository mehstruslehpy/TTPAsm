ldi d,0
main:
ldi a,5
dec d
st (d),a
ldi a,3
dec d
st (d),a
ldi a,retAddr
dec d
st (d),a
jmpi subtract
retAddr:
halt // now a should have -2, or 0xfe, or 254

subtract:
cpr c,d
ldi a,1
add c,a
ld a,(c)
inc c
ld b,(c)
sub a,b
ld b,(d)
inc d
jmp b

