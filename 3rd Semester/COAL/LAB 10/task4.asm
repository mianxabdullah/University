.MODEL SMALL
.STACK 100H

.DATA
    msg db "enter a digit (0-9) $"
    newline db 13,10,'$'
    table1 db "zero  one   two   three four  five  six   seven eight nine  "

.CODE

MAIN PROC
    mov ax, @data
    mov ds, ax

    mov dx, offset msg
    mov ah, 09
    int 21h

    mov ah, 01
    int 21h       

    sub al, 30h   

    mov bl, al  

    mov al, bl
    mov cl, 5
    mul cl      

    mov bx, offset table1
    add bx, ax  
	
    mov dx, offset newline
    mov ah, 09
    int 21h

    mov cx, 5
print:
    mov dl, [bx]
    mov ah, 02
    int 21h
    inc bx
	dec cx
    jnz print

    mov ah, 4Ch
    int 21h

MAIN ENDP
END MAIN
