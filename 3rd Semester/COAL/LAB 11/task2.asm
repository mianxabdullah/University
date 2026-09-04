.MODEL SMALL
.386
.STACK 100h
.DATA
    array  db 100 dup(?)
    newline db 13,10,'$'
.CODE
MAIN PROC
    mov ax, @data
    mov ds, ax
    mov es, ax

    mov di,offset array
	cld
	mov cx,0
reading:
    mov ah, 01
    int 21h        

    cmp al, 13    
    je done
	
    cmp al, 8      
    je back  
	
    stosb      
	inc cx
    jmp reading
	
back:
	dec di 
	dec cx
	jmp reading

done:
    mov dx,offset newline
    mov ah, 09
    int 21h
	mov di,offset array
print:      
    mov al, [di]    
    mov dl, al
    mov ah, 02
    int 21h 
	inc di
	dec cx 
	jnz print
	
    mov ah,4Ch
    int 21h
MAIN ENDP
END MAIN
