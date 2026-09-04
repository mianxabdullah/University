.MODEL SMALL
.STACK 100H
.DATA
		ARRAY1 db 41h,42h,43h,44h,45h,46h,47h,48h,'$' 
		ARRAY2 db 30h,31h,32h,33h,34h,35h,36h,37h,'$'
		newline db 13,10,'$'
 

.CODE
	MAIN PROC
		MOV AX,@DATA
		MOV DS,AX
		mov si,offset ARRAY1
		mov di,offset ARRAY2
		mov cx,8
	again:
		mov al,[si]
		mov bl,[di]
		mov	[si],bl
		mov	[di],al
		inc si 
		inc di 
		dec cx
		jnz again
		
		MOV DX,offset ARRAY1 
		MOV AH,9 
		INT 21h
		
		MOV DX,offset newline 
		MOV AH,9 
		INT 21h
		
		MOV DX,offset ARRAY2
		MOV AH,9 
		INT 21h
		
		
		MOV AH,4Ch 
		int 21h
		
	MAIN ENDP
	END MAIN
		