sub d,d
main:

ldi a,51
sub d,a
cpr c,d
ldi a,50
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
ldi a,51
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
cpr c,d
inc c
ld a,(c)
and a,a
//Logisim and my emulator hit this line a different amount of times
jzi endIf

inc c
ld b,(c)
dec d
st (d),b

inc a
//state differs between logisim and my emulation here after running ld a,(a)
//my emulator pushes a different value to the stack compared to logisim
//the first occurence looks up the value in ram at address 0x1c this corresponds
//to memory allocated by the byte N2 instruction in the source in emulation this 
//gets misread as 0x01 when in reality it should be 0x1e the following value from
//byte N3 gets read/writtes as 0x02 when it should be 0x21 and etc
ld a,(a) //!!!state differs?
dec d
st (d),a
ldi a,traRetFromTraL
dec d
st (d),a
jmpi traverse
traRetFromTraL:
inc d
inc d

cpr c,d
inc c
ld b,(c)
ld b,(b)
inc c
ld c,(c)
ld c,(c)
st (c),b

cpr c,d
inc c
inc c
ld c,(c)
ld b,(c)
inc b
st (c),b

cpr c,d
inc c
inc c
ld b,(c)
dec d
st (d),b
dec c
ld b,(c)
inc b
inc b
ld b,(b)
dec d
st (d),b
ldi a, traRetFromTraR
dec d
st (d),a
jmpi traverse
traRetFromTraR:
inc d
inc d
endIf:
ld b,(d)
inc d
jmp b

