LDI D,0
main:
LDI A,x // a=x
LDI B,2 // b=2
ST (A),B // *a=2
// start of call f
LDI A,1
SUB D,A  // decrement SP allocate a byte
LDI A,retAddr
ST (D),A  // store return address
LDI A,f  // goto f
JMP A
retAddr:
// end of call f
HALT

f:
LDI A,x  // a=x
LD B,(A) // b=*a
LDI A,0 // a=0
CMP B,A // 
LDI A,goReturn
JZ A
JL A
LDI A,1 // a=1
SUB B,A // b-=a
LDI A,x // a=x
ST (A),B // *a=b
LDI A,1 // a=1
SUB D,A // d-=1 SP decrements
LDI A,retAddr1 // a=retAddr1
ST (D),A // *d=a store retAddr1 to stack
LDI A,f // a=f
JMP A
retAddr1:

goReturn:
// begin return
LD A,(D)  // retrieve return address
LDI B,1
ADD D,B  // increment SP, deallocate
JMP A   // goto return address
// end return

x:
byte 0

