.MODEL SMALL ;48 41
.STACK 100H
.DATA
	msg db "Enter a digit(0-9)  $"
	newline db 13,10,'$'
	table1  db 'zero ','one  ','two  ','three','four ',
                'five ','six  ','seven','eight','nine '

.CODE
MAIN PROC
	mov ax, @data
    mov ds, ax
	
    mov dx,offset msg
	mov ah,09
	int 21h
	
	mov ah,01
	int 21h
	
	sub al, '0'       
	mov cl,5	
	mul cl
	
	mov bx,offset table1
	XLAT
	
	mov dx,offset newline
	mov ah,09
	int 21h
	
	mov cx,5
aa:
	mov dl, al
	mov ah, 02
	int 21h
	inc al
	dec cx
	jnz aa
    
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN