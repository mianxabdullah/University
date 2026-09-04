.MODEL SMALL
.STACK 100H
.DATA
    score db 85               
    newline db 13,10,'$'

    gradeA  db 'Grade: A$'
    gradeA_ db 'Grade: A-$'
    gradeBp db 'Grade: B+$'
    gradeB  db 'Grade: B$'
    gradeB_ db 'Grade: B-$'
    gradeCp db 'Grade: C+$'
    gradeC  db 'Grade: C$'
    gradeC_ db 'Grade: C-$'
    gradeDp db 'Grade: D+$'
    gradeD  db 'Grade: D$'
    gradeF  db 'Grade: F$'

.CODE
MAIN PROC
    mov ax, @data
    mov ds, ax

    mov al, score      

    cmp al, 85
    jge _GradeA          ; 85–100

    cmp al, 80
    jge _GradeA_         ; 80–84

    cmp al, 75
    jge _GradeBp         ; 75–79

    cmp al, 71
    jge _GradeB          ; 71–74

    cmp al, 68
    jge _GradeB_         ; 68–70

    cmp al, 64
    jge _GradeCp         ; 64–67

    cmp al, 61
    jge _GradeC          ; 61–63

    cmp al, 58
    jge _GradeC_         ; 58–60

    cmp al, 54
    jge _GradeDp         ; 54–57

    cmp al, 50
    jge _GradeD          ; 50–53

    jmp _GradeF          ; below 50 


_GradeA:
    mov ah, 9
    mov dx,offset gradeA
    int 21h
    jmp Exit

_GradeA_:
    mov ah, 9
    mov dx,offset gradeA_
    int 21h
    jmp Exit

_GradeBp:
    mov ah, 9
    mov dx,offset gradeBp
    int 21h
    jmp Exit

_GradeB:
    mov ah, 9
    mov dx,offset gradeB
    int 21h
    jmp Exit

_GradeB_:
    mov ah, 9
    mov dx,offset gradeB_
    int 21h
    jmp Exit

_GradeCp:
    mov ah, 9
    mov dx,offset gradeCp
    int 21h
    jmp Exit

_GradeC:
    mov ah, 9
    mov dx,offset gradeC
    int 21h
    jmp Exit

_GradeC_:
    mov ah, 9
    mov dx,offset gradeC_
    int 21h
    jmp Exit

_GradeDp:
    mov ah, 9
    mov dx,offset gradeDp
    int 21h
    jmp Exit

_GradeD:
    mov ah, 9
    mov dx,offset gradeD
    int 21h
    jmp Exit

_GradeF:
    mov ah, 9
    mov dx,offset gradeF
    int 21h


Exit:
    mov ah, 9
    mov dx,offset newline
    int 21h

    mov ah, 4Ch
    int 21h
MAIN ENDP
END MAIN
