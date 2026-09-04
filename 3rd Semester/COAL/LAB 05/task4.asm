.MODEL SMALL
.STACK 100H
.DATA
    msg db 'enter a letter: $'
    newline db 13,10,'$'
    upperMsg db 'uppercase $'
    lowerMsg db 'lowercase $'
.CODE
MAIN PROC
    mov ax, @data
    mov ds, ax

    mov ah, 9
    mov dx,offset msg
    int 21h

    mov ah, 1
    int 21h            
    mov bl, al         

    ; newline
    mov ah, 9
    mov dx,offset newline
    int 21h

    mov al, bl
    and al, 11011111b  ; reset bit 5  ,make uppercase

    mov ah, 9
    mov dx,offset upperMsg
    int 21h

    mov dl, al
    mov ah, 2
    int 21h            ; display uppercase letter

    ; Newline
    mov ah, 9
    mov dx,offset newline
    int 21h

    mov al, bl
    or al, 00100000b   ; set bit 5 ,make lowercase

    mov ah, 9
    mov dx,offset lowerMsg
    int 21h

    mov dl, al
    mov ah, 2
    int 21h            ; display lowercase letter

    mov ah, 4Ch
    int 21h
MAIN ENDP
END MAIN
