.MODEL SMALL
.STACK 100h
.data
	string db "bs data science fall 2025 $"
	vowels db "AEIOUaeiou$"
	msg db "count of vowels: $"
	count db 0
.Code
MAIN PROC
	mov ax,@data
	mov ds,ax
	mov es,ax
	mov si,offset string
	lodsb
again:
	mov di,offset vowels
	mov cx, 11
scan:
	dec cx
	jz next
	scasb
	jnz scan
	inc count
	jmp scan
next:
	lodsb
	cmp al,'$'
	jne again
print:	
	mov dx,offset msg
	mov ah,9
	int 21h	
	mov dl,count
	add dl,30h
	mov ah,02
	int 21h
exit:
	mov ah,4Ch
	int 21h
MAIN endp
end main