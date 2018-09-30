LDI D,0
main: // main() {
LDI A,x // x = 2;
LDI B,2
ST (A),B
LDI A,1 // f();
SUB D,A
LDI A,retAddr
ST (D),A
LDI A,f
JMP A
retAddr:
HALT // return 0;
// }

f: //f() {
LDI A,x // if (x>0)
LD B,(A)
LDI A,0
CMP B,A
LDI A,goReturn
JZ A
JL A
LDI A,1 // { x--;
SUB B,A
LDI A,x
ST (A),B
LDI A,1 // f()
SUB D,A
LDI A,retAddr1
ST (D),A
LDI A,f
JMP A // }
retAddr1:

goReturn:
LD A,(D) // return;
LDI B,1
ADD D,B
JMP A //}



x:
byte 0

