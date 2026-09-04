.MODEL SMALL
.STACK 100H
.DATA
		newline db 13,10,'$'
		MSG1 db "ENTER An ALPHABET:$"
		MSG2 db "CAPITAL$"
		MSG3 db "SMALL$"
		MSG4 db "Not An Alphabet$"
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
		
		CMP BL,41H
		JL Not_cap_small
		CMP BL,5Ah
		JG NOT_CAP
		MOV DX,offset MSG2
		JMP RES
		
	NOT_CAP:
	
		MOV DX,offset newline 
		MOV AH,9 
		INT 21h
		
		cmp BL,61
		JL Not_cap_small
		CMP BL,7Ah
		JG Not_cap_small
		MOV DX,offset MSG3 
		JMP RES
		
	Not_cap_small:
		MOV DX,offset newline 
		MOV AH,9 
		INT 21h
		
		MOV DX,offset MSG4 
		JMP RES
		
		

	RES:		
	
		MOV AH,9 
		INT 21h
			
		MOV AH,4Ch 
		int 21h
		
	MAIN ENDP
	END MAIN