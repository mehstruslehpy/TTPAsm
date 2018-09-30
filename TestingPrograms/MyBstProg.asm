sub d,d
main:

ldi a,6
sub d,a
cpr c,d
ldi a,5
add c,a
st (c),d

dec d
st (d),c
ldi a,N1
dec d
st (d),a
ldi a,mainRetFromTraverse
dec d
st (d),a
jmpi traverse
mainRetFromTraverse:
inc d
inc d

ldi a,6
add d,a
halt

N1:
byte 5
byte N2
byte N3
N2:
byte 3
byte 0
byte N4
N3:
byte 10
byte N5
byte 0
N4:
byte 4
byte 0
byte 0
N5:
byte 9
byte 0
byte 0

traverse:
ldi b,1
add b,d
ld b,(b)
and b,b
jzi traverseend

ldi b,2
add b,d
ld b,(b)
dec d
st (d),b

ldi b,2
add b,d
ld b,(b)
inc b
ld b,(b)
dec d
st (d),b

ldi b, traverseret1
dec d
st (d),b
jmpi traverse

traverseret1:
inc d
inc d
ldi b,1
add b,d
ld b,(b)
ld b,(b)

ldi c,2
add c,d
ld c,(c)
ld c,(c)
st (c),b

ldi c,2
add c,d
ldi b,2
add b,d
ld b,(b)
ld c,(c)
ld c,(c)
inc c
st (b),c

ldi b,2
add b,d
ld b,(b)
dec d
st (d),b

ldi b,2
add b,d
ld b,(b)
inc b
inc b
ld b,(b)
dec d
st (d),b

ldi b, traverseret2
dec d
st (d),b
jmpi traverse

traverseret2:
inc d
inc d

traverseend:
ld b,(d)
inc d
jmp b
halt
