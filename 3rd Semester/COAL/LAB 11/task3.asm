.MODEL SMALL
.386
.STACK 100h
.data
	array db "qwertyuio$"
	notFound db 13,10,"character not found$"
	fond db 13,10,"character found at index:$"
.Code
MAIN PROC
	mov ax,@data
	mov ds,ax
	mov es,ax
	mov ah,01
	int 21h
	mov di, offset array
	mov cl,0
	mov ch,10
aa:
	inc cl
	dec ch
	jz nfound
	
	scasb
	jnz aa
found:
	mov dx,offset fond
	mov ah,09h
	int 21h
print:	
	mov dl,cl
	add dl,'0'
	mov ah,02
	int 21h
	jmp exit
nfound:
	mov dx,offset notFound
	mov ah,09h
	int 21h
exit:
	mov ah,4Ch
	int 21h
MAIN endp
end main