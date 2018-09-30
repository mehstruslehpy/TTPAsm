main:
sub d,d
dec d
dec d
ldi a, 3
st (d),a
cpr c, d
inc c
ldi a,7
st (c),a
dec d
st (d),c
dec d
dec c
st (d),c
ldi a, main_retfromswap
dec d
st (d),a
jmpi swap
main_retfromswap:
inc d
inc d
inc d
inc d
halt

swap:
dec d

ldi a,2
add a,d
ld a,(a)
ld a,(a)
cpr b,d
st (b),a

ldi a,2
add a,d
ld a,(a)
ldi b,3
add b,d
ld b,(b)
st (a),b

cpr b,d
ldi a,3
add a,d
ld b,(b)

ld a,(a)
st (a),b
inc d

ld a,(d)
inc d
jmp a
