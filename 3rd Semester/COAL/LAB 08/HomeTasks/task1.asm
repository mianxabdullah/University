.MODEL SMALL
.STACK 100H
.DATA
	newline db 13,10,'$'
	str1 db "good morning$"
	array db 30h,36h,32h,31h,38h,35h
	str2 db "level$"
	my_string DB "  this proc finds count of words in a string$"
.CODE
MAIN PROC
	mov ax, @data
    mov ds, ax
	
    MOV AX,offset str1        
    Call reverseSTR
	
	mov dx,offset newline
	mov ah,09
	int 21h
	
	mov cx,6
    mov ax,offset array    
    Call max
	mov dl, al
	mov ah, 02h
	int 21h
	
	mov dx,offset newline
	mov ah,09
	int 21h
	
	MOV AX, offset str2
    Call is_palindrom
	add al, 30h
	mov dl, al
	mov ah, 02h
	int 21h
	
	mov dx,offset newline
	mov ah,09
	int 21h
	
	MOV AX, 0007
    CALL bit_count
	add al, 30h
	mov dl, al
	mov ah, 02h
	int 21h
	
	mov dx,offset newline
	mov ah,09
	int 21h
	
	MOV AX, OFFSET my_string
    CALL wordCount
	ADD AL, 30H
    MOV DL, AL
    MOV AH, 02H
    INT 21H
	
	MOV AH, 4CH
    INT 21H
MAIN ENDP

reverseSTR proc ;hometask 1 
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

max proc		;hometask 2
    mov si, ax
    mov al, [si]
    inc si
    dec cx
    jz donee
next:
    mov bl, [si]
    cmp bl, al
    jbe skip
    mov al, bl
skip:
    inc si
    dec cx
    jnz next
donee:
    mov ah, 0
    ret
max endp


is_palindrom proc	;hometask 3
    mov si, ax
    mov di, ax

    mov cx, 0
countt:
    mov al, [si]
    cmp al, '$'
    je doneee
    inc cx
    inc si
    jmp countt
doneee:
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

bit_count proc		;hometask 4
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

wordCount PROC 	;hometask 5
    MOV SI, AX
    MOV DX, 0
    MOV BL, 0
start:
    MOV AL, [SI]
    
    CMP AL, '$'
    JE end_proc
    
    CMP AL, ' '
    JNE non_space
    
    MOV BL, 0 ;word completed
    JMP continue

non_space:
    CMP BL, 1 ;word is not completed yet
    JE continue
    
    MOV BL, 1
    INC DX
continue:
    INC SI
    JMP start
end_proc:
    MOV AX, DX
    RET
wordCount ENDP

END MAIN