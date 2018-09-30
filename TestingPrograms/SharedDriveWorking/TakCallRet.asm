ldi d,0 // initialize SP

dec d // allocate byte
ldi a,caller_cont // continuation point
st (d),a
jmpi sub1
caller_cont: // there is where main continues
halt // d should be back to 0, if we are here, we are good!

sub1: // this is the subroutine
nop // doesn't do anything
ld a,(d) // retrieve return address
inc d // deallocate storage of ret address
jmp a

halt // should never get here!

