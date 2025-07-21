mov bl, 4
    mov bh, 2
    mov cx,0
          
    add cx,bl
    add cx,bh  
     
    mov cx,0
    
    add cx,bl
    sub cx,bh
    
    mov cx,0
    
    mov al,bl
    mul bh
    mov cx,al
    
    mov cx,0
    
    mov al,bl
    div bh
    mov cx,al
    
    mov al, bl
    div bh
    mov cx,ah 
       
 
    add dl,30h 
    mov ah,02
    int 21h  
    

    add dl,30h 
    mov ah,02
    int 21h

    add dl,30h 
    mov ah,02
    int 21h
    
    add dl,30h 
    mov ah,02
    int 21h 
    

    add dl,30h 
    mov ah,02
    int 21h