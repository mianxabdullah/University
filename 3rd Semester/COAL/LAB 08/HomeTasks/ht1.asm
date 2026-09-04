.MODEL SMALL
.STACK 100H
.DATA
	str db "good morning$"
.CODE
MAIN PROC
	mov ax, @data
    mov ds, ax
	
    MOV AX,offset str        
    Call reverseSTR
    
    MOV AH, 4CH
    INT 21H
MAIN ENDP

reverseSTR proc
    mov si, ax
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
print:
    mov dl, [si]
    mov ah, 02h
    int 21h
    dec si
    dec cx
    jnz print
    ret
reverseSTR endp
END MAIN