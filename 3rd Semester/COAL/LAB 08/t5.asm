.MODEL SMALL
.STACK 100H
.DATA
.CODE

MAIN PROC
    MOV AX, 5      
    MOV CX, 4      
    CALL MULTIPLY  ;4*5=20
    
    MOV AH, 4CH
    INT 21H
MAIN ENDP

MULTIPLY PROC
    MOV BX,0000h        
    MOV BX, AX       
    MOV AX, 0      

AGAIN:
    ADD AX, BX    
    DEC CX           
    JNZ AGAIN   
    RET
MULTIPLY ENDP

END MAIN
