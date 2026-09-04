.MODEL SMALL
.STACK 100H
.DATA
		newline db 13,10,'$'
		msg1 db "enter first number: $"
		msg2 db "enter second number: $"
		greaterr db "first is greater$"
		smallerr db "first is smaller$"
		equall db "both are equal$"
 .CODE
	MAIN PROC
		MOV AX,@DATA
		MOV DS,AX
		
		mov ah, 9	; print msg to enter number 1
		mov dx,offset msg1
		int 21h
		
		mov ah, 1
		int 21h
		sub al, 30h       ; convert ascii to number
		mov bl, al        ; store first char
		
		MOV DX,offset newline ;shifts cursor to newline
		MOV AH,9 
		INT 21h
		    
		mov ah, 9	; print msg to enter number 1
		mov dx,offset msg2
		int 21h
		
		mov ah, 1
		int 21h
		sub al, 30h
		mov bh, al        ; store second char
		
		MOV DX,offset newline 
		MOV AH,9 
		INT 21h
		
		; Compare and jump
		cmp bl, bh  		; bl=num1 , bh=num2
		je equal
		jg greater
		jl smaller

	equal:
		mov ah,9
		MOV dx,offset equall
		int 21h
		jmp Exit

	greater:
		mov ah,9
		mov dx,offset greaterr
		int 21h
		jmp Exit

	smaller:
		mov ah,9
		MOV dx,offset smallerr
		int 21h

	Exit:
		MOV AH,4Ch 
		int 21h
		
	MAIN ENDP
	END MAIN