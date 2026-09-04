.MODEL SMALL
.STACK 100H
.DATA
		newline db 13,10,'$'
		MSG1 db "ENTER A DIGIT(0-9):$"
		MSG2 db "Digit$"
		MSG3 db "Not a Digit$"
 .CODE
	MAIN PROC
		MOV AX,@DATA
		MOV DS,AX
		
		MOV DX,offset MSG1 
		MOV AH,9 
		INT 21h
		
		MOV AH,01
		INT 21H
		MOV BL,AL
				
		MOV DX,offset newline 
		MOV AH,9 
		INT 21h
		
		cmp bl,30h
		jl not_dig
		cmp bl,39h
		jg not_dig
		
		MOV DX,offset MSG2 
		MOV AH,9 
		INT 21h
		
		jmp res
		
	not_dig:
	
		
		MOV DX,offset MSG3 
		MOV AH,9 
		INT 21h
		
		jmp res
		

	res:		
		MOV AH,4Ch 
		int 21h
		
	MAIN ENDP
	END MAIN
		
