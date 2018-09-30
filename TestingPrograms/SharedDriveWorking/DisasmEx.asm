n:
ldi a,1
sub d,a

ldi a,retAddr1
st (d),a

ldi a,five
jmp a
retAddr1:


ldi b,1
sub d,b
st (d),a

ldi a,1
sub d,a

ldi a,retAddr2
st (d),a

ldi a,five
jmp a

retAddr2:





ld b,(d)
add a,b
ldi b,1
add d,b
halt

five:


ld b,(d)
ldi a,1
add d,a
ldi a,5
jmp b
