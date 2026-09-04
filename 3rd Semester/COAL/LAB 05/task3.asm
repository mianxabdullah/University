.MODEL SMALL
.STACK 100H
.DATA
    msg db 'enter a digit (0-9): $'
    newline db 13,10,'$'
    evenMsg db 'number is EVEN$'
    oddMsg db 'number is ODD$'

.CODE
MAIN PROC
    mov ax, @data
    mov ds, ax

    mov ah, 9
    mov dx,offset msg
    int 21h

    mov ah, 1
    int 21h
    sub al, 30h        ; Convert ascii to numeric 
    mov bl, al         ; Store number in BL

    mov ah, 9
    mov dx,offset newline
    int 21h

    ; Check even/odd using AND
    mov al, bl
    and al, 1          ; Isolate least significant bit
    cmp al, 0
    je equal
    jmp odd

equal:
    mov ah, 9
    mov dx,offset evenMsg
    int 21h
    jmp Exit

odd:
    mov ah, 9
    mov dx,offset oddMsg
    int 21h

Exit:
    mov ah, 4Ch
    int 21h
	
MAIN ENDP
END MAIN