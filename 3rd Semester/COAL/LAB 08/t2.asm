.MODEL SMALL
.386
.STACK 100H
.DATA
		newline db 13,10,'$'
 .CODE
MAIN PROC
	MOV AX,@DATA
	MOV DS,AX
		
	mov ax,4567h
	call display 

	Exit:			
		MOV AH,4Ch 
		int 21h
		
	MAIN ENDP
	
	
 	
display PROC
	mov bx,0000h
	push bx
	push AX
	pop bx
	pop AX
	mov cx,4
again:
	rol bx,4
	mov dl,bl
	and dl,0Fh
	cmp dl,09
	jle dig
	add dl,37h
	jmp abc
dig:
	add dl,30h
abc:
	mov ah,02
	int 21h
	dec cx 
	jnz again
	
	ret
display ENDP
end MAIN




