ldi a,1
ldi b,255
sub a,b
jci good1
jmpi bad
bad:
halt
good1:
jzi bad
good2:
jsi bad
good3:
joi bad
good4:
jli bad
halt // if we end up here, we are good!