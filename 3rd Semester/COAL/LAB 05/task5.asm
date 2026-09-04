.MODEL SMALL
.STACK 100H
.DATA
    msg1      db 'Enter 5-character password $'
    newline   db 13,10,'$'
    key       db 'abcde'              ; 5-character key
    input     db 5 dup(?)             ; user input
    encrypted db 5 dup(?)             ; encrypted password
    decrypted db 5 dup(?)             ; decrypted password

    showKey   db 13,10,'key: $'
    showEnc   db 13,10,'encrypted: $'
    showDec   db 13,10,'decrypted: $'

.CODE
MAIN PROC
    mov ax, @data
    mov ds, ax

    mov ah, 9
    mov dx, OFFSET msg1
    int 21h

    mov si, OFFSET input
    mov cx, 5           

inputt:
    mov ah, 1           ; read one character
    int 21h
    mov [si], al
    inc si
    dec cx
    jnz inputt       ; repeat until CX = 0

    mov ah, 9       ; shifts cusor to newlinw
    mov dx, OFFSET newline
    int 21h


    mov si, OFFSET input
    mov di, OFFSET key
    mov bx, OFFSET encrypted
    mov cx, 5

encryptt:
    mov al, [si]
    xor al, [di] ;bitwise xor , encrypts input
    mov [bx], al
    inc si
    inc di
    inc bx
    dec cx
    jnz encryptt

    mov si, OFFSET encrypted
    mov di, OFFSET key
    mov bx, OFFSET decrypted
    mov cx, 5

decryptt:
    mov al, [si]
    xor al, [di] 		;again bit wise xor will decrypted it
    mov [bx], al
    inc si
    inc di
    inc bx
    dec cx
    jnz decryptt


    ; Show Key
    mov ah, 9
    mov dx, OFFSET showKey  ;msg show key:
    int 21h
    mov ah, 9
    mov dx, OFFSET key  ;key
    int 21h

    ; Show Encrypted
    mov ah, 9
    mov dx, OFFSET showEnc  ;msg
    int 21h
    mov ah, 9
    mov dx, OFFSET encrypted   ;encrypted key
    int 21h

    ; Show Decrypted
    mov ah, 9
    mov dx, OFFSET showDec	;msg
    int 21h
    mov ah, 9
    mov dx, OFFSET decrypted 	;decrypted key
    int 21h

    ; newline
    mov ah, 9
    mov dx, OFFSET newline
    int 21h

    mov ah, 4Ch
    int 21h
MAIN ENDP
END MAIN
