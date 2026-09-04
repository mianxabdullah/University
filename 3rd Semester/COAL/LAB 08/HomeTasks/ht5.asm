.MODEL SMALL
.STACK 100H
.DATA
    my_string DB "  this proc finds count of words in a string$"
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
	
    MOV AX, OFFSET my_string
    CALL wordCount
	
    ADD AL, 30H
    MOV DL, AL
    MOV AH, 02H
    INT 21H
    
    MOV AH, 4CH
    INT 21H
MAIN ENDP
wordCount PROC 
    MOV SI, AX
    MOV DX, 0
    MOV BL, 0
start:
    MOV AL, [SI]
    
    CMP AL, '$'
    JE end_proc
    
    CMP AL, ' '
    JNE non_space
    
    MOV BL, 0 ;word completed
    JMP continue

non_space:
    CMP BL, 1 ;word is not completed yet
    JE continue
    
    MOV BL, 1
    INC DX
continue:
    INC SI
    JMP start
end_proc:
    MOV AX, DX
    RET
wordCount ENDP
END MAIN