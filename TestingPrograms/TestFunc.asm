MAIN:
ldi d,0

ldi a,2 //a simple arg
dec d
st (d),a

ldi a, RETURN
dec d
st (d), a
jmpi FUNC

RETURN:
inc d
halt

FUNC:
//2
//ret <- d
ld a,(d) // a == ret
//and a,a
sub a,a
jzi ZERO
jmpi NOTZERO

ZERO:
ldi c, 170
ld b,(d)
inc d
jmp b

NOTZERO:
ldi c, 255
ld b,(d)
inc d
jmp b
