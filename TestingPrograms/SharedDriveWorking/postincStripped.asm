jmpi main

postinc:
cpr  c,d 
inc  c   
ld   b,(c) 
ld   a,(b) 
dec  d
st   (d),a 

inc  a     
st   (b),a 

ld   a,(d) 
inc  d
ld   b,(d) 
inc  d
jmp  b

main:

ldi d,0
dec d
ldi a,0
st  (d),a  

dec d      

cpr   c,d   
inc   c     
dec   d
st    (d),c 
ldi   a,main_retaddr1
dec   d
st    (d),a 
jmpi  postinc

main_retaddr1:
inc   d     
st    (d),a 

ldi   a,staticVar  
dec   d
st    (d),a        
ldi   a,main_retaddr2
dec   d
st    (d),a        
jmpi  postinc

main_retaddr2:
inc   d            

ld    b,(d)        
add   b,a          
st    (d),b        

inc   d            
inc   d            
halt

staticVar:
byte 30
