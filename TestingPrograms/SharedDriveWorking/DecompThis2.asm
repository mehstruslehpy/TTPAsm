LDI D,0
main:
LDI A,x
LDI B,2
ST (A),B
// start of call f
LDI A,1
SUB D,A	// decrement SP allocate a byte
LDI A,retAddr
ST (D),A // store return address
LDI A,f	// goto f
JMP A
retAddr:
// end of call f
HALT
x:
byte 0

f:
LDI A,x
LD B,(A)
LDI A,0
CMP B,A
LDI A,goReturn
JZ  A
JL  A
LDI A,1
SUB B,A
LDI A,x
ST  (A),B
LDI A,1
SUB D,A
LDI A,retAddr1
ST (D),A
LDI A,f
JMP A
retAddr1:

goReturn:
// begin return
LD  A,(D) // retrieve return address
LDI B,1
ADD D,B	// increment SP, deallocate
JMP A // goto return address
// end return

