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
	mov cx,16
again:
	shl bx,1
	jc one
	mov dl,30h
	jmp disp
one:
	mov dl,31h
	jmp disp
disp:
	mov ah,02
	int 21h
	dec cx 
	jnz again
	
	ret
display ENDP

end MAIN