.MODEL SMALL
.386
.STACK 100H
.DATA
		newline db 13,10,'$'
		msg db "enter a 16-bit binary number: $"
		invalid_msg db "Invalid Input! enter only 0/1 Now,enter from start again $"
		input db 16 dup('?'),'$'
 .CODE
	MAIN PROC
		MOV AX,@DATA
		MOV DS,AX
	
	start:
		mov dx,offset msg
		mov ah, 9	
		int 21h
		
		mov bx,0000h ;16-bit register initialized with 00000000000000
		mov cx,16
		mov si,offset input
		
	reading:
		mov ah,01
		int 21h
		
		cmp al,'0'
		jl invalid
		cmp al,'1'
		jg invalid
		
		mov [si],al
		inc si
		
		sub al,30h
		shl bx,1 
		or bx,1 ;or new bit in LSB (or 0,al-30h) 		
		dec cx
		jnz reading
		
		mov dx,offset newline 
		mov ah,9 
		int 21h
		
		mov al,'$'
		mov [si],al
		
		mov dx,offset input 
		mov ah,09
		int 21h
		jmp exit
	
	invalid:
		mov dx,offset newline 
		mov ah,9 
		int 21h
		
		mov dx,offset invalid_msg
		mov ah,09
		int 21h
		
		mov dx,offset newline 
		mov ah,9 
		int 21h
		
		jmp start
		
	exit:
		mov ah,4Ch
		int 21h
		
		
		
	MAIN ENDP
	END MAIN