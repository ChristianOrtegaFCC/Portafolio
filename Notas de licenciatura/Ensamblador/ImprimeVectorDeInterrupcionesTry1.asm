.model small
.stack 64
.data
  
;declaramos las variables para ingresar los numeros a operar
AUXRES db 0

msjnMod db 10,13, "residuo de la division: ",'$'  

.code
inicio proc far; ==================

MOV SI,0
MOV AX,[SI]
PUSH AX
MOV DL, AH
;CALL IMP 2 DIG<<<<<<<<<<<<<<<<<<<<<<
    ;MOV DL, AUXRES              
    ;ADD DL, 30H     ;Sumamos 30h porque es la conversion correspondiente    
    ;MOV AUXRES,DL   ;guardamos el resultado en AUXRES    
    ;
    ;MOV DL, AUXRES      
    ;MOV AH, 02H     ;imprimimos el caracter que toca imprimir... el de la izquierda 
    ;INT 21H    
    ;JMP CONVRES2>>>>>>>>>>>>>>>>>>>>

POP AX
;MOVEMOS EL REGISTRO A DONDE IMRIMIMOS
MOV DL, AL
;CALL IMPRIMIR 2 DIG
INC SI
INC SI    
    
    

inicio endp; =========================
end