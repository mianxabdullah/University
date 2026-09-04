.MODEL SMALL
.STACK 100H
.DATA
	table1 db 65 dup (?)
			db 'NOPQRSTUVWXYZABCDEFGHIJKLM'
			db 6 dup (?)
			db 'nopqrstuvwxyzabcdefghijklm'
	msg db "Enter a Character for encryption  $"
	newline db 13,10,'$'
.CODE
MAIN PROC
	mov ax, @data
    mov ds, ax
	
    mov dx,offset msg
	mov ah,09
	int 21h
	
	mov ah,01
	int 21h
	
	mov bx,offset table1
	XLAT

	mov dx,offset newline
	mov ah,09
	int 21h
	
	mov dl, al
	mov ah, 02h
	int 21h
    
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN