.MODEL SMALL
.STACK 100H
.DATA
    newline DB 13,10,'$'
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    MOV BL, 'A'          ; Start from 'A'

next_letter:
    CMP BL, 'Z'          ; Stop after 'Z'
    JA done

    ; Print the letter
    MOV DL, BL
    MOV AH, 02H
    INT 21H

    ; Print space
    MOV DL, ' '
    MOV AH, 02H
    INT 21H

    MOV BH, BL
    MOV CL, 8             

binary_loop:
    SHL BH, 1             ; Shift left, MSB to CF
    JNC print_zero        ; If CF=0 print 0
    MOV DL, '1'
    JMP print_bit

print_zero:
    MOV DL, '0'

print_bit:
    MOV AH, 02H
    INT 21H               ; Print bit
    DEC CL
    JNZ binary_loop       ; Repeat for 8 bits

    ; Newline
    mov DX,offset newline
    MOV AH, 09H
    INT 21H

    INC BL                ; Next letter
    JMP next_letter

done:
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN


