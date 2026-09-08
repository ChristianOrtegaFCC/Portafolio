.model small
.stack 64
.data
  
;declaramos las variables para ingresar los numeros a operar
numero1 db 0
numero2 db 0

;ahora las variables en las que guardaremos nuestros resultados
suma db 0
resta db 0
multiplicacion db 0
division db 0
modulo db 0
     
; mensajes para pedir los datos     
msjn1 db 10,13, "Dame el primer numero: ",'$'
msjn2 db 10,13, "Dame el segundo numero: ",'$'

;mensajes para mostrar los resultados
msjnS db 10,13, "suma : ",'$'
msjnR db 10,13, "resta: ",'$'
msjnM db 10,13, "Multiplicacion : ",'$'
msjnD db 10,13, "division : ",'$' 
msjnMod db 10,13, "residuo de la division: ",'$'  

.code
inicio proc far
    
    ;direccionamiento del procedimiento
    mov ax, @data
    mov ds,ax
    
    ;pedimos numero 1
    
    mov ah, 09
    lea dx, msjn1
    int 21h
    mov ah, 01
    int 21h
    sub al, 30h
    mov numero1,al
    mov bl, numero1
    
    ;pedimos numero 2
    
    mov ah, 09
    lea dx, msjn2
    int 21h
    mov ah, 01
    int 21h
    sub al, 30h
    mov numero2,al
    mov bh, numero2
             
    ; hacemos las operaciones....         
                  
    ;SUMA             
    add suma,bl
    add suma,bh  
    
    ;RESTA
    add resta,bl
    sub resta,bh
    
    ;MULTIPLICACION
    mov al,bl
    mul bh
    mov multiplicacion,al
    
    ;DIVISION
    mov al,bl
    div bh
    mov division,al
    
    ;RESIDUO O MODULO
    mov al, bl
    div bh
    mov modulo,ah 
       
    ;Mostramos los resultados.... 
    
    ;suma
    mov ah,09
    lea dx,msjnS
    int 21h
    mov dl,suma
    add dl,30h 
    mov ah,02
    int 21h  
    
    ;resta
    mov ah,09
    lea dx,msjnR
    int 21h
    mov dl,resta
    add dl,30h 
    mov ah,02
    int 21h
    
    ;multiplicacion
    mov ah,09
    lea dx,msjnM
    int 21h
    mov dl,multiplicacion
    add dl,30h 
    mov ah,02
    int 21h
    
    ;division
    mov ah,09
    lea dx,msjnD
    int 21h
    mov dl,division
    add dl,30h 
    mov ah,02
    int 21h 
    
    ;modulo     
    mov ah,09
    lea dx,msjnMod
    int 21h
    mov dl,modulo
    add dl,30h 
    mov ah,02
    int 21h
  
    ;cierre del programa
    mov ah,4ch
    int 21h
    
    inicio endp
end