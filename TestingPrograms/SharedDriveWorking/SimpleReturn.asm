//uint8_t five()
//{
//    return 5;
//}

// convention is use a register to store the return value
// use register A

//uint8_t main()
//{
//    register uint8_t a;
//    a = five()+five();
//}

ldi d,0    // initialize the stack point to location "256"
main:
ldi a,1
sub d,a    // reserving a byte on the stack

ldi a,retAddr1
st  (d),a  // store retAddr1 to the stack

ldi a,five
jmp a

retAddr1:
// reg a has the return value of the first call to "five"

ldi b,1
sub d,b
st  (d),a  // the return value of the first call is saved on stack

ldi a,1
sub d,a    // reserving a byte on the stack

ldi a,retAddr2
st  (d),a  // store retAddr1 to the stack

ldi a,five
jmp a

retAddr2:
// returned from the second call to "five"
// reg A has the ret val from the second call
// *d has the ret val from the first call

// a+=(*d++)
ld  b,(d) // store the ret val of the first call in b
add a,b
ldi b,1
add d,b
halt


five:
// register D is the stack point
// register points to the return address on the stack right now
ld  b,(d)
ldi a,1
add d,a
ldi a,5 // specify the return value
jmp b

