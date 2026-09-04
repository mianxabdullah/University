.model small
.stack 100h
.data
	num1 db 5
	num2 db 3
	andRes db ?
	orRes  db ?
	xorRes db ?
.code
	main proc
    mov ax,@data
    mov ds,ax

    mov al, num1
    mov bl, num2

    and al, bl
    mov andRes, al

    mov al, num1
    or al, bl
    mov orRes, al

    mov al, num1
    xor al, bl
    mov xorRes, al

    mov ah,4Ch
    int 21h
main endp
end main