//uint8_t mult(register uint8_t a, register uint8_t b)
//{
//    uint8_t result;
//    result=(a&1)?b:0;
//    b <<= 1;
//    while ((a = a>>1) != 0)
//    {
//        result+=(a&1)?b:0;
//        b <<= 1;
//    }
//    return result; // as register a
//}
ldi d,0 // initialize stack pointer
main:
ldi a,1
sub d,a
ldi a,retAddr
st (d),a
ldi a,6
ldi b,7
ldi c, mult
jmp c
retAddr:
halt


mult:
ldi c,1
sub d,c  // reserve one byte for the result of the invocation
ldi c,0
st (d),c // initialize result to 0
ldi c,1
and c,a
ldi c,else1
jz c
// initialize result to 1
//  ldi c,1
st (d),b
else1:
add b,b
beginwhile:
ldi c,1
rsh a,c
//  jz endwhile oops, my bad!
ldi c,endwhile
jz c
//   result+=(a&1)?b:0;
ldi c,1
and c,a
ldi c,else2
jz c  // if a&1 is 0 branch to else2
// add b to the result
ld c,(d)
add c,b
st (d),c
else2:
//   b <<= 1;
add b,b
ldi c,beginwhile
jmp c// go back to the beginning of the loop
endwhile:
ld a,(d)               // result is pointed to by d
ldi b,1
add d,b              // d now points to the ret addr
ld c,(d)
add d,b// dealloc the ret addr
jmp c// return to the caller


