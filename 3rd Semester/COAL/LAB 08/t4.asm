.MODEL SMALL
.STACK 100H
.DATA
		newline db 13,10,'$'
		msgC db "Capital $"
		msgS db "Small $"
		msgD db "Digit $"
		msgOth db "Other character $"

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    MOV AH, 1
    INT 21H

	mov dx,offset newline
	mov ah,09
	int 21h
	
    call check       

    MOV AH, 4CH
    INT 21H
MAIN ENDP

check proc
	
    CMP AL, 'A'
    JL NOT_CAPITAL
    CMP AL, 'Z'
    JG NOT_CAPITAL
    mov DX,offset msgC
    JMP PRINT_MSG

NOT_CAPITAL:
    CMP AL, 'a'
    JL NOT_SMALL
    CMP AL, 'z'
    JG NOT_SMALL
    mov DX,offset msgS
    JMP PRINT_MSG

NOT_SMALL:
    CMP AL, '0'
    JL OTHER
    CMP AL, '9'
    JG OTHER
    mov DX,offset msgD
    JMP PRINT_MSG

OTHER:
    mov DX,offset msgOth

PRINT_MSG:
    MOV AH, 9
    INT 21H
    RET
check ENDP

END MAIN
