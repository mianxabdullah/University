.MODEL SMALL
.STACK 100H
.DATA
	array db 30h,36h,32h,31h,38h,35h
.CODE
MAIN PROC
	mov ax, @data
    mov ds, ax
	
	mov cx,6
    mov ax,offset array    
    Call max
	
	mov dl, al
	mov ah, 02h
	int 21h
    
    MOV AH, 4CH
    INT 21H
MAIN ENDP

max proc
    mov si, ax
    mov al, [si]
    inc si
    dec cx
    jz done
next:
    mov bl, [si]
    cmp bl, al
    jbe skip
    mov al, bl
skip:
    inc si
    dec cx
    jnz next
done:
    mov ah, 0
    ret
max endp
END MAIN

