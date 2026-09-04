.MODEL SMALL
.STACK 100H
.DATA
	str db "level$"
.CODE
MAIN PROC
	mov ax, @data
    mov ds, ax
	
    MOV AX, offset str
    Call is_palindrom
	
	add al, 30h
	mov dl, al
	mov ah, 02h
	int 21h
    
    MOV AH, 4CH
    INT 21H
MAIN ENDP

is_palindrom proc
    mov si, ax
    mov di, ax

    mov cx, 0
count:
    mov al, [si]
    cmp al, '$'
    je done
    inc cx
    inc si
    jmp count
done:
    dec si

    mov bx, cx
    shr bx, 1

check:
    mov al, [si]
    mov dl, [di]
    
    cmp al, dl
    jne nott

    dec si
    inc di
    
    dec bx
    jnz check

    mov ax, 1
    jmp endd
nott:
    mov ax, 0
endd:
    ret
is_palindrom endp
END MAIN