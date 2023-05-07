Data ends
Code segment

Assume cs: code, ds:data
    Begin:
        mov ax,data
        mov ds,ax
        mov cx,10
        mov dl,48

    L1:
        MOV ah,2
        int 21h
        inc dl
        loop l1
        
        mov ah,4ch
        int 21h
    code ends
end begin
