MAIN:
sub d,d
dec d

ldi a,8
dec d
st (d),a

ldi a,RETADDR
dec d
st (d),a

jmpi FIB
RETADDR:
inc d
st (d),a
inc d
halt
ENDMAIN:

FIB:
ldi a,1
add a,d
ld a,(a)
ldi b,2
cmp a,b
jci CASE1
jmpi CASE2

CASE1:
ld b,(d)
inc d
jmp b

CASE2:
cpr b,a
dec b

dec d
st (d),b
ldi b, CASE2RETADDR1
dec d
st (d),b
jmpi FIB

CASE2RETADDR1:
inc d
cpr b,a

dec d
st (d),b

ldi a,2
add a,d
ld a,(a)
cpr c,a
dec c
dec c

dec d
st (d),c

ldi b, CASE2RETADDR2
dec d
st (d),b
jmpi FIB

CASE2RETADDR2:
inc d
ld b,(d)
inc d
add a,b

ld b,(d)
inc d
jmp b
ENDFIB:
