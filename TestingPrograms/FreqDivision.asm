//#include <stdint.h>
// f:
//   byte 10
// b:
//   byte 20
ldi d,0 // initialize stack pointer
main:
//int main()
//{
//  f = 10;// desired frequency of an action
ldi a,f
ldi b,10
st (a),b
//  b = 20;// base frequency of timer
ldi a,b
ldi b,20
st (a),b
//  t = 0;// counter for frequency division
ldi a,t
ldi b,0
st (a),b
//  c = 7;// how many times to perform the action
ldi a,c
ldi b,7
st (a),b
beginwhile:
//  while (c != 0)
ldi a,c
ld a,(a)
ldi b,0
cmp a,b
ldi a,endwhile
jz a
//  {
//    t += f;
ldi a,f
ld a,(a)
ldi b,t
ld c,(b)
add c,a
st (b),c
//    if (t >= b)
ldi a,t
ld a,(a)
ldi b,b
ld b,(b)
cmp a,b
ldi a,endif
jc a
//    {
//       --c;
ldi a,c
ld b,(a)
ldi c,1
sub b,c
st (a),b
//       t -= b;
ldi a,b
ld a,(a)
ldi b,t
ld c,(b)
sub c,a
st (b),c
//    }
endif:
//  }
ldi a,beginwhile
jmp a
endwhile:
//  return 0;
halt
//}
//uint8_t f, b, t, c;
f:
byte 0
b:
byte 0
t:
byte 0
c:
byte 0

