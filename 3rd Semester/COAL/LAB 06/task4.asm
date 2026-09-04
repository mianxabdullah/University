.MODEL SMALL
.STACK 100H
.DATA
    msg     DB 'Enter a 4-digit hexadecimal number: $'
    invalid DB 13,10,'Invalid input! Please enter only hexadecimal digits (0–9, A–F, a–f): $'
    newline DB 13,10,'$'
    result  DB 4 DUP(?)      ; store 4 hex digits 
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

start_input:
    ; Display prompt message
    MOV DX, OFFSET msg
    MOV AH, 09H
    INT 21H

    MOV SI, OFFSET result    ; store input here
    MOV CX, 4                ; number of digits expected

read_input:
    MOV AH, 01H              ; read character
    INT 21H
    MOV BL, AL               

    ; --- Validate input ---
    CMP AL, '0'
    JB invalid_input
    CMP AL, '9'
    JBE store_char

    CMP AL, 'A'
    JB check_lower
    CMP AL, 'F'
    JBE store_char

check_lower:
    CMP AL, 'a'
    JB invalid_input
    CMP AL, 'f'
    JBE convert_upper

    JMP invalid_input

convert_upper:
    SUB AL, 20H              ; convert a–f → A–F

store_char:
    MOV [SI], AL             ; store valid character
    INC SI                   ; next memory location
    DEC CX                   ; one less character to read
    JNZ read_input           ; continue until CX = 0
    JMP display_result        ; all 4 read successfully

invalid_input:
    ; Show error and restart
    MOV DX, OFFSET invalid
    MOV AH, 09H
    INT 21H
    JMP start_input

display_result:
    ; Print newline
    MOV DX, OFFSET newline
    MOV AH, 09H
    INT 21H

    ; Display stored 4-digit HEX number 
    MOV CX, 4
    MOV SI, OFFSET result

print_loop:
    MOV DL, [SI]
    MOV AH, 02H
    INT 21H
    INC SI
    DEC CX
    JNZ print_loop

    ; Exit program
    MOV AH, 4CH
    INT 21H
MAIN ENDP
END MAIN


