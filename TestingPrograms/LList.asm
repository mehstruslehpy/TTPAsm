jmpi main
n3:
byte 2
byte 0

n2:
byte 5
byte n3

n1:
byte 16
byte n2

main:
sub d,d
ldi a,5
sub d,a
ldi a,n1
st (d),a
cpr c,d
ldi a,4
add c,a
sub a,a
st (c),a

whileBegin:
ld a,(d)
and a,a
jzi whileEnd
ld a,(a)
dec d
st (d),a
ldi a,5
add a,d
ld a,(a)
ldi b,2
add b,d
add a,b
ld b,(d)
inc d
st (a),b

ldi a,4
add a,d
ld b,(a)
inc b
st (a),b

ld a,(d)
inc a
ld a,(a)
st (d),a
jmpi whileBegin

whileEnd:
ldi a,0
ldi b,5
add d,b
halt
