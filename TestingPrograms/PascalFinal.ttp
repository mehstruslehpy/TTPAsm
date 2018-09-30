//
//	This program 'prints' pascals triangle into ram for Taks CPU
//
	//load the locations of the initial values into memory
	ldi a, 96	//a=row, 96=MAX_SIZE
	ldi b, 16	//b=an offset
	ldi c, 1	//c is the starting value
	ldi d, 0    //d is unused for now

	//start the triangle
	st (a), c	//store a 1 at the tip
	add a, b	//add 16 to advance to the next row
	st (a), c	//store a 1
	add a, c	//add 1 to advance to the next col
	st (a), c	//store a 1
	dec a	//set a at start of col
	add a, b	//add 16 to advance to the next row
	st (a), c	//store a 1

	//reset row offsets
	sub a, b

	//save all important values
	ldi d, 255	//255=&lastrow
	st (d), a	//*(0xFF)=lastrow
	add a, b	// a+=16
	ldi d, 254	//254=&row
	st (d), a	//*(0xFE)=row

ROW1:
	//reset the column
	ldi d, 253	//253=&lastcol
	ldi b, 0
	st (d), b	//*(0xFD)=lastcol
	ldi d, 252	//*(0xFC)=col
	st (d), b

	//store first item of the column
	ldi d, 254
	ld a, (d)	//a=row
	ldi d, 1
	st (a), d	//row=1

	//while (row < MAX_SIZE)
	ldi d, 224	//d=maxsize
	cmp a,d
	jzi ROW2	//if a-d=0 we are done

COL1:
	//find operands
	ldi d, 255
	ld a, (d)	//a=lastrow
	ldi d, 253
	ld b, (d)	//b=lastcol

	//load to registers
	add a,b	//a=&ram[lastrow][lastcol]
	ld b, (a)	//b=ram[lastrow][lastcol]
	inc a
	ld c, (a)	//c=ram[lastrow][lastcol+1]

	//calculate next element
	//b=ram[lastrow][lastcol]+ram[lastrow][lastcol+1]
	add b, c

	//find write location
	ldi a, 254
	ld a, (a)	//a=row
	ldi d, 252
	ld d, (d)	//d=col
	inc d	//d+=1
	add a, d	//a=row+col+1

	//store the value
	st (a), b

	//if lastelem == 1 break
	ldi c, 1	//check if the last element stored is a 1
	cmp b, c	//which signifies the end of the row
	jzi COL2 	//if b-c=0 then b was 1 so exit

	//advance by column
	ldi d, 252
	ld a, (d)	//a=col
	inc a	//a=col++
	st (d), a	//store it
	ldi d, 253
	ld a, (d)	//a=lastcol
	inc a	//a=col++
	st (d), a	//store it

	jmpi COL1	//continue looping
COL2:

	//advance by row
	ldi d, 255
	ld a, (d)	//a=lastrow
	ldi b, 16
	add a, b	//a=lastrow++
	st (d), a	//store it
	ldi d, 254
	ld a, (d)	//a=row
	add a, b	//a=row++
	st (d), a	//store it

	jmpi ROW1	//continue looping
ROW2:
	halt
