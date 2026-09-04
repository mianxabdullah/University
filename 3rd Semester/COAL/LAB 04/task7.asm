.MODEL SMALL
.STACK 100H
.DATA
		newline db 13,10,'$'
		MSG1 db "enter a number:$"
		MSG2 db "enter another number:$"
		MSG3 db "overflow$"
		MSG4 db "Sum=$"
 .CODE
	MAIN PROC
		MOV AX,@DATA
		MOV DS,AX
		
		MOV DX,offset MSG1 
		MOV AH,9 
		INT 21h
		
		MOV AH,01
		INT 21H
		sub al,30h
		MOV BL,AL
		
		MOV DX,offset newline 
		MOV AH,9 
		INT 21h
		
		MOV DX,offset MSG2 
		MOV AH,9 
		INT 21h
		
		MOV AH,01
		INT 21H
		sub al,30h
		add bl,al
		
		cmp bl,0Ah
		jae abc    ; i used jae instead of jg to handle sum=10 case.
		jmp xyz
		
	xyz:
		MOV DX,offset newline 
		MOV AH,9 
		INT 21h
	
	
		MOV DX,offset MSG4 
		MOV AH,9 
		INT 21h
		
		add bl,30h
		mov dl,BL
		mov ah,02
		int 21h
		jmp res
		
		
	abc:
	
		MOV DX,offset newline 
		MOV AH,9 
		INT 21h
		
		MOV DX,offset MSG3 
		MOV AH,9 
		INT 21h
		jmp res
		

		
	res:
		MOV AH,4Ch 
		int 21h
		
	MAIN ENDP
	END MAIN