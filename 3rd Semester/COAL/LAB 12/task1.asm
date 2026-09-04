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
	mov bl,al
	mov dx,offset newline
	mov ah,09
	int 21h
	
    mov cl,0
aa:
	inc cl
	cmp cl,bl
	jg exit
	mov dx,offset newline
	mov ah,09
	int 21h
	mov ch,1
bb:
	mov dl,ch
	add dl,30h
	mov ah,02
	int 21h
	inc ch 
	cmp ch,cl
	jle bb
	jmp aa
exit:
    mov ah, 4ch
    int 21h
end main

