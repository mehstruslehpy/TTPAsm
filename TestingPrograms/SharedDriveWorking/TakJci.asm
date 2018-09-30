sub a,a // c should be cleared
jci L1
ldi b,1
sub a,b // c should be set
jci L2
halt // we should not be here
L1:
halt // we should not be here!
L2:
halt // we should be here

