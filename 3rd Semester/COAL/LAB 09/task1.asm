.MODEL SMALL
.STACK 100H
.DATA
newline db 13,10,'$'
userInput dw ?


msg1 db 'task1 8 bit decimal number display:  $'
val1  db 125

msg2 db 'task2 16 bit decimal number display:  $'
val2  dw 4567

msgD db 'distance:  $'
val3  dw 42335
msgKm db 13,10,'kilometers: $'
msgM db 13,10,'meters: $'

days  dw 800
msgDays db 13,10,'days:  $'
msgmonths db 13,10,'months: $'
msgyear db 13,10,'years: $'

salary dw 10000
msgtotal db 13,10,'total salary:  $'
msgBasic db 13,10,'basic:  $'
msgRent db 13,10,'HouseRent: $'
msgCon db 13,10,'Conveyance: $'
msgother db 13,10,'others: $'

pkr dw 5600
msgpkr db 13,10,'pkr:  $'
msgusd db 13,10,'usd:  $'
msgeuro db 13,10,'euro: $'
msggbp db 13,10,'gbp: $'

facto db 5
msgfact db 13,10,'factorial of 5 is :  $'

msgX db ' x $'
msgEq db ' = $'
num db 7

msgC db 'celsius: $'
msgF db 13,10,'fahrenheit: $'
msgK db 13,10,'kelvin: $'
cel dw 25

.CODE
main PROC
    mov ax, @data
    mov ds, ax
;task 1
    mov dx, offset msg1
    mov ah, 09h
    int 21h

    mov al, val1
    call task1_PrintDecimal
	
	mov dx,offset newline
    mov ah, 09h
    int 21h
	
	mov dx,offset newline
    mov ah, 09h
    int 21h
;task2
	mov dx, OFFSET msg2
    mov ah, 09h
    int 21h

    mov ax, val2
    call task2_PrintDecimal_16
	
	mov dx,offset newline
    mov ah, 09h
    int 21h
	
	mov dx,offset newline
    mov ah, 09h
    int 21h
;task3
	mov dx, OFFSET msgD
    mov ah, 09h
    int 21h
	
	mov ax,val3
	call task2_PrintDecimal_16
	
	mov ax,val3
	call task3_kmToM
	mov si,dx
	
	mov dx, OFFSET msgKm
    mov ah, 09h
    int 21h
	
	mov ax,cx
	call task2_PrintDecimal_16
	
	mov dx, OFFSET msgM
    mov ah, 09h
    int 21h
	
	mov ax,si
	call task2_PrintDecimal_16
	
	mov dx,offset newline
    mov ah, 09h
    int 21h
	
;task4:
	mov ax,days
	call task4_daystoyear
	mov si,dx
	
	mov dx, OFFSET msgyear
    mov ah, 09h
    int 21h
	mov ax,cx
	call task2_PrintDecimal_16
	
	mov dx,OFFSET msgmonths
    mov ah, 09h
    int 21h
	mov ax,bx
	call task2_PrintDecimal_16
	
	mov dx, OFFSET msgM
    mov ah, 09h
    int 21h
	mov ax,si
	call task2_PrintDecimal_16
	
	mov dx,offset newline
    mov ah, 09h
    int 21h
;task5:
	mov dx,OFFSET msgtotal
    mov ah, 09h
    int 21h
	mov ax,salary
	call task2_PrintDecimal_16

	mov ax,salary
	call task5_Salary
	mov di,dx
	
	mov dx, OFFSET msgBasic
    mov ah, 09h
    int 21h
	mov ax,cx
	call task2_PrintDecimal_16
	
	mov dx,OFFSET msgRent
    mov ah, 09h
    int 21h
	mov ax,di
	call task2_PrintDecimal_16
	
	mov dx, OFFSET msgCon
    mov ah, 09h
    int 21h
	mov ax,bx
	call task2_PrintDecimal_16
	
	mov dx, OFFSET msgother
    mov ah, 09h
    int 21h
	mov ax,si
	call task2_PrintDecimal_16
	
	mov dx,offset newline
    mov ah, 09h
    int 21h
	
;task6:
	mov dx,OFFSET msgpkr
    mov ah, 09h
    int 21h
	mov ax,pkr
	call task2_PrintDecimal_16
	
	mov ax,pkr
	call task6_pkrtoother
	
	mov dx, OFFSET msgusd
    mov ah, 09h
    int 21h
	mov ax,cx
	call task2_PrintDecimal_16
	
	mov dx, OFFSET msgeuro
    mov ah, 09h
    int 21h
	mov ax,di
	call task2_PrintDecimal_16
	
	mov dx, OFFSET msggbp
    mov ah, 09h
    int 21h
	mov ax,bx
	call task2_PrintDecimal_16
	
	mov dx,offset newline
    mov ah, 09h
    int 21h
;task7:
	mov dx,OFFSET msgfact
    mov ah, 09h
    int 21h
	
	mov ax,0000
	mov al,facto
	mov cx,0000
	call task7_fact
	
	call task2_PrintDecimal_16
	
	mov dx,offset newline
    mov ah, 09h
    int 21h
;task8:
	mov ax,0000
	mov al,num
	call task8_table
	
	mov dx,offset newline
    mov ah, 09h
    int 21h
;task9:
	
	mov dx, OFFSET msgC
	mov ah, 09h
	int 21h

	mov ax, cel
	call task2_PrintDecimal_16

	mov ax, cel
	call task9_temperature

	mov dx, OFFSET msgF
	mov ah, 09h
	int 21h
	
	mov ax, bx       
	call task2_PrintDecimal_16

	mov dx, OFFSET msgK
	mov ah, 09h
	int 21h

	mov ax, cx       
	call task2_PrintDecimal_16
	
    mov ah,4Ch
    int 21h
main ENDP
task1_PrintDecimal proc
    push ax
    push bx
    push cx
    push dx

    mov ah, 0
    mov bl, 10
    mov cx, 0
aa: 
	xor ah, ah
    div bl
    push ax
    inc cx
    cmp al, 0
    jne aa
bb: 
	pop ax
    mov dl, ah
    add dl, 30h
    mov ah, 02h
    int 21h
	dec cx
    jnz bb

    pop dx
    pop cx
    pop bx
    pop ax
    ret
task1_PrintDecimal endp
task2_PrintDecimal_16 proc
    push ax
    push bx
    push cx
    push dx

    mov bx, 10        
    mov cx, 0         
convert:
    xor dx, dx        
    div bx            
    push dx           
    inc cx
    cmp ax, 0
    jne convert
print:
    pop dx
    add dl,30h
    mov ah, 02h
    int 21h
	dec cx
    jnz print

    pop dx
    pop cx
    pop bx
    pop ax
    ret
task2_PrintDecimal_16 endp
task3_kmToM PROC
	mov bx, 1000 
	xor dx,dx
    div bx    ; meters are in dx     
	mov cx, ax     ; km
    ret
task3_kmToM ENDP
task4_daystoyear PROC
    mov bx, 365
    xor dx, dx
    div bx         
    mov cx, ax     ;years in cx

    mov ax, dx     ;remaining days after ax/bc 
    mov bx, 30
    xor dx, dx
    div bx         
    mov bx, ax     ;months in bx / dx=days reminder
    ret
task4_daystoyear ENDP
task5_Salary PROC
    mov bx, 10
    xor dx, dx
    div bx          
    
    mov cx, ax
    add cx, cx     
    add cx, cx   ;cx=40% of ax

    mov dx, ax	;dx=30% of ax
    add dx, dx      
    add dx, ax      

    mov bx, ax	;bx=20% of ax
    add bx, bx     

    mov si,ax	;si=40% of ax
    ret
task5_Salary ENDP
task6_pkrtoother PROC
	mov si,ax
	
    mov bx, 280
    xor dx, dx
    div bx		;cx=usd
    mov cx, ax    

    mov ax,si
    mov bx, 300
    xor dx, dx	;dx=euro
    div bx
    mov di, ax   

    mov ax, si
    mov bx, 350	;bx=gbp
    xor dx, dx
    div bx
    mov bx, ax    
	ret
task6_pkrtoother ENDP
task7_fact PROC
    mov cl, al      
    mov ax, 1   
fact:
    mul cl    
    dec cl
    jnz fact

    ret
task7_fact ENDP
task8_table PROC
	mov bx, ax        
    mov cx, 1         
table:          
    mov ax, bx
    call task2_PrintDecimal_16

    mov dx, offset msgX
    mov ah, 09h
    int 21h

    mov ax, cx
    call task2_PrintDecimal_16

    mov dx, offset msgEq
    mov ah, 09h
    int 21h

    mov ax, bx
    mul cl        

    call task2_PrintDecimal_16

    mov dx, offset newline
    mov ah, 09h
    int 21h

    inc cx
    cmp cl, 11
    jl table
    ret
task8_table ENDP
task9_temperature PROC
    push ax
    mov bx, ax        
    mov cx, 9
    mul cx           
    mov cx, 5
    xor dx, dx
    div cx            
    add ax, 32        
    mov bx, ax     
	
    pop ax            
    add ax, 273
    mov cx, ax        
    ret
task9_temperature ENDP
end main
