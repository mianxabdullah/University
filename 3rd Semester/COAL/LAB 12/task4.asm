.model small
.386
.stack 100h
.data
str1 db "enter number of rows: $"
newline db 13,10,'$'
.code
main:
    mov ax, @data
    mov ds, ax
	
	mov dx,offset str1
    mov ah,09
    int 21h

	mov ah,01
	int 21h
	sub al,30h
	mov bh,al
	
	mov bl,2
	mov ah,0
	div bl
	
	cmp ah,0
	je exit
	
	mov bl,ah
	inc bl 
	
	mov ch,bh
aa:
	mov dx,offset newline
	mov ah,09
	int 21h

	mov cl,ah
	cmp ch,bl
	je row
spaces:
	mov dl,' '
	mov ah,02
	int 21h
	dec cl
	jnz spaces
	mov cl,1
star:
	mov dl,'*'
	mov ah,02
	int 21h
	dec cl
	jnz star
		
	dec ch
	jnz aa
	
	jmp exit
row:
	mov cl,bh
	jmp star
exit:
    mov ah, 4ch
    int 21h
end main

