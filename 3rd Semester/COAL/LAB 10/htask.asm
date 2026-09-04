.model small
.stack 100h
.data 
	newline db 13 ,10 ,'$'
  tableout db '0123456789ABCDEF'
  tablein db 48 dup('!')
            db 0,1,2,3,4,5,6,7,8,9
        db 7 dup('!')
            db 10,11,12,13,14,15
        db 26 dup('!')
            db 10,11,12,13,14,15
             db 153 dup('!')
  bin db 'enter binary num: $'
  oct db 'enter octal num: $' 
  deci db 'enter decimal num $'
  hex db 'enter hexadecimal num $'
  binout db 'binary= $'
  octout db 'octal= $'
  decout db 'decimal= $'
  hexout db 'hexadecimal= $'
  msgErr db 13,10,'Invalid Input Enter again from start $'
.code
take_input proc
   push bx
   push cx
   push dx
restart:
   mov dx , bx
   mov cx , 0
again:
    mov ah , 01h
    int 21h
    cmp al , 0dh
    je exit
    mov si,bx
    mov bx ,offset tablein
    XLAT
    mov bx,si 
	
	cmp al,33 ;33=!   
	je invalid
	
	cmp al,dl
	jae invalid


    mov ah,0
    push ax
    push dx 
    mov ax,cx ;New Decimal Value = (Current Decimal Value X Input Base) + New Digit Value
    mul dx
    mov cx,ax
    pop dx
    pop ax
    add cx,ax
    jmp again
invalid:
	mov dx,offset msgErr
	mov ah,09h
	int 21h	
	jmp restart
exit:
    mov ax , cx
       
    pop dx 
    pop cx
    pop bx
    ret 
take_input endp
      
display_output proc
   push ax          
   push bx          
   push cx         
   push dx
   mov cx , 0
againn:  
    xor dx,dx
    div bx          
    push dx         
    inc cx           
    cmp ax, 0        
    jne againn
print:
    pop ax           
    mov si,bx
    mov bx, offset tableout
    XLAT            
    mov bx,si
    mov dl, al
    mov ah, 02h
    int 21h
    dec cx 
    jnz print
	
	pop dx
	pop cx
	pop bx
	pop ax
	ret
display_output endp

main proc
   mov ax , @data
   mov ds , ax
;bin to others
   mov dx, offset bin
   mov ah, 09h
   int 21h
   
   mov bx, 2
   call take_input
   mov di,ax
   
   mov dx, offset octout
   mov ah, 09h
   int 21h
   mov ax,di
   mov bx, 8
   call display_output
   
   mov dx, offset newline
   mov ah, 09h
   int 21h
   
   mov dx, offset decout
   mov ah, 09h
   int 21h
   mov ax,di
   mov bx, 10
   call display_output
   
   mov dx, offset newline
   mov ah, 09h
   int 21h
   
   mov dx, offset hexout
   mov ah, 09h
   int 21h
   mov ax,di
   mov bx, 16
   call display_output
      
	mov dx, offset newline
    mov ah, 09h
    int 21h
;oct to oters
   mov dx, offset oct
   mov ah, 09h
   int 21h
   mov bx, 8
   call take_input
   mov di,ax
   
   mov dx, offset binout
   mov ah, 09h
   int 21h
   mov ax,di
   mov bx, 2
   call display_output
   
   mov dx, offset newline
   mov ah, 09h
   int 21h
   
   mov dx, offset decout
   mov ah, 09h
   int 21h
   mov ax,di
   mov bx, 10
   call display_output
   
   mov dx, offset newline
   mov ah, 09h
   int 21h
   
   mov dx, offset hexout
   mov ah, 09h
   int 21h
   mov ax,di
   mov bx, 16
   call display_output
   
    mov dx, offset newline
   mov ah, 09h
   int 21h
;decimal to others
   mov dx, offset deci
   mov ah, 09h
   int 21h
   mov bx, 10
   call take_input
    mov di,ax
   
   mov dx, offset binout
   mov ah, 09h
   int 21h
   mov ax,di
   mov bx, 2
   call display_output
   
   mov dx, offset newline
   mov ah, 09h
   int 21h
   
   mov dx, offset octout
   mov ah, 09h
   int 21h
   mov ax,di
   mov bx, 8
   call display_output
   
   mov dx, offset newline
   mov ah, 09h
   int 21h
   
   mov dx, offset hexout
   mov ah, 09h
   int 21h
   mov ax,di
   mov bx, 16
   call display_output
      
   mov dx, offset newline
   mov ah, 09h
   int 21h
;hexa to others
   mov dx, offset hex
   mov ah, 09h
   int 21h
   mov bx, 16
   call take_input
   mov di,ax
   
   mov dx, offset binout
   mov ah, 09h
   int 21h
   mov ax,di
   mov bx, 2
   call display_output
   
   mov dx, offset newline
   mov ah, 09h
   int 21h
   
   mov dx, offset octout
   mov ah, 09h
   int 21h
   mov ax,di
   mov bx, 8
   call display_output
   
   mov dx, offset newline
   mov ah, 09h
   int 21h
   
   mov dx, offset decout
   mov ah, 09h
   int 21h
   mov ax,di
   mov bx, 10
   call display_output
eend: 
   mov ah, 4ch
   int 21h
main endp
end main