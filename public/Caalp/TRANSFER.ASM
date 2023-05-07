org 100H
assume cs:code
code segment
start:
    MOV Cx, 08H
    MOV BX, 10H
    MOV DX, 21H
    mov si,bx
    mov di,dx
    mov al,cl
store:
    mov byte ptr[si],al
    dec al
    cmp al,0h
    jne store
again:
    MOV Al, byte ptr[si]
    MOV byte ptr[Di], Al
    loop again
    mov ah,4ch
    int 21H
code ENDS
END START