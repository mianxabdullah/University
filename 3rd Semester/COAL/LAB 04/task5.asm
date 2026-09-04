.MODEL SMALL
.STACK 100H
.DATA
		newline db 13,10,'$'
		MSG1 db "ENTER A NUMBER:$"
		MSG2 db "THE NUMBER YOU ENTERED:$"
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
		
		MOV DX,offset MSG2 
		MOV AH,9 
		INT 21h
		
		MOV DL,BL
		MOV AH,02
		INT 21H
			
		MOV AH,4Ch 
		int 21h
		
	MAIN ENDP
	END MAIN
		