.MODEL SMALL
.STACK 100h
.data
	array db "abcdabbad$"
	count db 13,10,"no of times repeated: $"
.Code
MAIN PROC
	mov ax,@data
	mov ds,ax
	mov es,ax
	mov ah,01
	int 21h
	mov di,offset array
	mov cx, 10
	mov dl,0
aa:
	dec cx
	jz next
	scasb
	jnz aa
	inc dl
	jmp aa
next:
	mov bl,dl
	mov dx,offset count
	mov ah,09
	int 21h
	
	mov dl,bl
	add dl,'0'
	mov ah,02
	int 21h
exit:
	mov ah,4Ch
	int 21h
MAIN endp
end main
