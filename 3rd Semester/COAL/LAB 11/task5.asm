.MODEL SMALL
.STACK 100h
.data
	arr1 db "abdullah$"
	arr2 db "abdulxyz$"	
	char db 13,10,"character: $"
	pos db 13,10,"position: $"
.Code
MAIN PROC
	mov ax,@data
	mov ds,ax
	mov es,ax
	mov di,offset arr1
	mov si,offset arr2
	mov cx,8
	mov dl,0
aa:
	dec cx
	jz exit
	inc dl
	cmpsb
	jnz done
	jmp aa
done:
	dec si
	mov bl,dl
	
	mov dx,offset char
	mov ah,9
	int 21h
	mov dl,[si]
	mov ah,02
	int 21h
	
	mov dx,offset pos
	mov ah,9
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