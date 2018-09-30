
// x_hi+=y_hi
ldi a,x_hi
ld c,(a)
ldi a,y_hi
ld d,(a)
add c,d
ldi a,x_hi
st (a),c


// x+=y
ldi a,x
ld c,(a)
ldi a,y
ld d,(a)
add c,d
ldi a,x
st (a),c




// if (x+y ends up with a carry)
ldi a,yesCarry
jc a
ldi a,end
jmp a
yesCarry:
// x_hi+=1
ldi a,x_hi // a=x_hi
ld a,(a)
ldi b,1 // a+=1
add a,b
ldi b,x_hi // x_hi=a
st (b),a


end:
halt
x: // 511: 0x100+0xff 0000 0001 1111 1111
byte 255
x_hi:
byte 1
y: // 1: 0x001 0000 0000 0000 0001
byte 1
y_hi:
byte 0

