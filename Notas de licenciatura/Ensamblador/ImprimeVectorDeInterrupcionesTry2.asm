.model small
.stack 64
.data
  
;declaramos las variables para ingresar los numeros a operar
N1 db 0
N2 db 0

;ahora las variables en las que guardaremos nuestros resultados
AUX db 0
R db 0

     
; mensajes para pedir los datos     
msjn1 db 10,13, "Dame el primer numero: ",'$'
  

.code
inicio proc far
;MOV AH, 01H
;INT 21H
;    SUB AL, 30H
;    MOV N1,AL 
             
;MOV AH, 01H
;INT 21H
;   SUB AL, 30H
;    MOV N2,AL
    
;XOR AX,AX

;MOV AL, 8
;ADD AL, 8
MOV AL,15
MOV R,AL

SHR AL,4H
MOV AUX,AL

MOV BL,R
AND BL,00001111B

MOV R,BL
MOV AL,AUX

MOV DL,AUX
ADD DL,30H
MOV AUX,DL
    MOV DL,AUX
    MOV AH,02H
    INT 21H
    
MOV DL,R
ADD DL,30H
MOV R,DL
    MOV DL,R
    MOV AH,02H
    INT 21H         

;cierre del programa
    mov ah,4ch
    int 21h
    
    inicio endp
end