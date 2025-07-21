BUCLE MACRO L, R, CNT

MOV SI, 0 ; INICIALIZAMOS EL SI Y EL DATA SEGMENT EN 0        
MOV DS,SI

inicio proc NEAR; ==================
MOV AX,[SI]
PUSH AX
MOV DL, AH
    ;IMPRIMIMOS LOS PRIMEROS 2 DIGITOS
    CALL IMP2DIG
    ADD CNT,1
    
POP AX
;MOVEMOS EL REGISTRO A DONDE IMRIMIMOS
MOV DL, AL
    ;IMPRIMIMOS LOS 2 DIGITOS SIGUIENTES
    CALL IMP2DIG
    ADD CNT,1  
INC SI
INC SI
  
CMP CNT, 2
JE DOSPUNTOS
CMP CNT,4
JE IMPENTER  
             
    DOSPUNTOS:         
    MOV DL,3AH
    MOV AH,02H
    INT 21H
    JMP SIGUE
    
    IMPENTER:
    MOV CNT, 0
     
    MOV AH,02H
    MOV DL,0AH ;SALTO DE LINEA
    INT 21H

    MOV AH,02H
    MOV DL,0DH ;RETORNO DE CARRO
    INT 21H
     
    JMP SIGUE  

SIGUE:
;ESTA PARTE ES PARA DETENER EL PROCESO EN CASO DE QUE SE HAYAN ESCRITO LAS PRIMERAS 16 INTERRUPCIONES 
CMP SI,64
JE TERMINA

CALL INICIO     

inicio endP; =========================

IMP2DIG PROC NEAR
    MOV AL,DL
    MOV R,AL

    SHR AL,4H
    MOV L,AL

    MOV BL,R
    AND BL,00001111B

    MOV R,BL
    MOV AL,L
    ; ========[1]
    CMP L, 09H
    JBE SD1     ;Si el resultado esta en un rango decimal, hacemos el proceso decimal   
    JMP SH1     ;Si el resultado esta en un rango hexadecimal, lo hacemos en hexadecimal 
    
    SD1:

    MOV DL, L              
    ADD DL, 30H         ;Sumamos 30h porque es la conversion correspondiente  
    MOV L,DL      
    MOV DL, L     
    MOV AH, 02H        ; imprimimos el caracter que faltaba, el IZQUIERDO
    INT 21H    
    JMP VAL ; saltamos a la validacion de repetir el proceso


    SH1: 

    MOV DL, L 
    ADD DL, 37H         ;Sumamos 37h porque es la conversion correspondiente 
    MOV L,DL   
    MOV DL, L       
    MOV AH, 02H          ; imprimimos el caracter que faltaba, el IZQUIERDO
    INT 21H
    
    VAL:
    ; =========[2]
    CMP R, 09H
    JBE SD2     ;Si el resultado esta en un rango decimal, hacemos el proceso decimal   
    JMP SH2     ;Si el resultado esta en un rango hexadecimal, lo hacemos en hexadecimal 
    
    SD2:

    MOV DL, R              
    ADD DL, 30H        ;Sumamos 30h porque es la conversion correspondiente  
    MOV R,DL      
    MOV DL, R     
    MOV AH, 02H        ; imprimimos el caracter que faltaba, el derecho
    INT 21H    
    JMP VAL2           ; saltamos a la validacion de repetir el proceso


    SH2: 

    MOV DL, R 
    ADD DL, 37H        ;Sumamos 37h porque es la conversion correspondiente 
    MOV R,DL   
    MOV DL, R       
    MOV AH, 02H         ; imprimimos el caracter que faltaba, el derecho
    INT 21H
    
    VAL2: 
     
    RET
IMP2DIG ENDP

TERMINA: 

BUCLE ENDM

.model small
.stack 64
.data
  
;declaramos las variables para ingresar los numeros a operar
LX db 0
RX DB 0
CNTX DB 0
      
.code                                                         
      BUCLE LX,RX,CNTX
END
