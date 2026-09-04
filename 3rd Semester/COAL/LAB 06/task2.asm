.MODEL SMALL
.386
.STACK 100H
.DATA
		newline db 13,10,'$'
		msg1 db "enter a character: $"
 .CODE
	MAIN PROC
		MOV AX,@DATA
		MOV DS,AX
		
		mov dx,offset msg1
		mov ah, 9	; print msg to enter number 1
		int 21h
		
		mov ah, 1
		int 21h
		mov bl, al        ; store first char
		
		MOV DX,offset newline 
		MOV AH,9 
		INT 21h
		
		mov bh,bl
		
		shr bl,4
		mov dl,bl
		add dl,30h
		mov ah,02
		int 21h
		
		shl bh,4
		shr bh,4
		mov dl,bh
		add dl,30h
		mov ah,02
		int 21h
		
		
		MOV AH,4Ch 
		int 21h
		
	MAIN ENDP
	END MAIN