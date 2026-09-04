.MODEL SMALL
.386
.STACK 100H
.DATA
		newline db 13,10,'$'
		msgE db "Even $"
		msgO db "Odd $"
		msgP db "positive $"
		msgN db "negative $"
 .CODE
MAIN PROC
	MOV AX,@DATA
	MOV DS,AX
		
	mov ax,0002h
	call evenodd 
	
	mov dx,offset newline
	mov ah,09
	int 21h
	
	mov ax,00ffh
	call posneg

	Exit:			
		MOV AH,4Ch 
		int 21h
		
	MAIN ENDP
	
	
 	
evenodd PROC
	mov bx,0000h
	push bx
	push AX
	pop bx
	pop AX
	
	test bx,0001h
	jz zero
	mov dx,offset msgO
	jmp print
zero:
	mov dx,offset msgE
	jmp print
print:
	mov ah,09
	int 21h
	
ret
evenodd ENDP

posneg PROC
	mov bx,0000h
	push bx
	push AX
	pop bx
	pop AX
	
	cmp bx,0000h
	jge pos
	mov dx,offset msgN
	jmp prin
pos:
	mov dx,offset msgp
	jmp prin
prin:
	mov ah,09
	int 21h
	
ret
posneg ENDP
	
end MAIN




