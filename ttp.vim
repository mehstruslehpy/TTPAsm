"Vim Syntax file for ttp assembly programs

if exists("b:current_syntax")
	finish
endif

"syntax elements
"could use a regex for a register too
syn match ttpComment '//\s*\p*'
syn keyword ttpMnemonic halt nop add sub cmp and or not rsh inc dec ldi ld st cpr jmp jmpi jc jci jz jzi js jsi jo joi jl jli byte addi stf
syn match ttpConstant ' [0-9]\{1,3} '
syn match ttpLabel '[0-9a-zA-z]*:'

"highlighting
"looks okay to me but requires some experimentation
let b:current_syntax = "ttp"
hi def link ttpMnemonic Statement
hi def link ttpConstant Constant
hi def link ttpLabel Delimiter
hi def link ttpComment Comment
