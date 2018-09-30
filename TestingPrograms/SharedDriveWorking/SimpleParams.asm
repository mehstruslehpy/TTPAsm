//uint8_t sum(register uint8_t a, register uint_8 b)
//{
//    return a+b;
//}

sum:
// reg A and B contain the parameters
add a,b // reg A has the return value now
ld  b,(d) // retrieve the ret addr
ldi c,1
add d,c   // reclaim the space on stack for ret addr
jmp b

//uint8_t main()
//{
//    a = sum(6,7);
//}

ldi d,0 // initialize stack pointer
main:
ldi a,1
sub d,a // decrement stack point, reserve space
ldi a,retAddr1
st  (d),a // store ret address
ldi a,6
ldi b,7
ldi c,sum
jmp c

retAddr1:
halt
sum:
// reg A and B contain the parameters
add a,b // reg A has the return value now
ld  b,(d) // retrieve the ret addr
ldi c,1
add d,c   // reclaim the space on stack for ret addr
jmp b



