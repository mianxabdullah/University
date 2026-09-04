.MODEL SMALL
.STACK 100H
.DATA
.CODE
MAIN PROC
	mov ax, @data
    mov ds, ax
	
    MOV AX, 0007
    CALL bit_count
	
	add al, 30h
	mov dl, al
	mov ah, 02h
	int 21h
    
    MOV AH, 4CH
    INT 21h
MAIN ENDP

bit_count proc
    mov cx, 16
    mov dx, 0
    check_bit:
    shr ax, 1
    jnc next_bit
    inc dx
next_bit:
    dec cx
    jnz check_bit
    
    mov ax, dx
    ret
bit_count endp
END MAIN