.model small
.stack 100h
.data
str1 db "ABCDEFGHIJ$"
str2 db 11 dup(?)
.code
main:
    mov ax, @data
    mov ds, ax
    mov es, ax

    mov si, offset str1
    add si, 9                
    mov di, offset str2
    std
    mov cx, 10
aa:
	movsb
	add di,2
	dec cx
	jnz aa

    mov di, offset str2
    add di, 10              
    mov al, '$'
    mov [di], al             

    mov dx, offset str2
    mov ah, 09
    int 21h

    mov ax, 4ch
    int 21h
end main
