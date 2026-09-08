.MODEL
.STACK 64
.DATA

;DECLARACION DE VARIABLES--------------------------------------

NUM1     DB ?
NUM2     DB ?
SIGNO    DB ?,'$'
SUMA     DB ?
RESTA    DB ?
MULTI    DB ?
DIVISION DB ?
MODULO   DB ?




;MENSAJES PARA PEDIR LOS DATOS---------------------------------
MSJN1 DB 10,13, "DAME EL PRIMER NUMERO: ",'$'
MSJOP DB 10,13, "DAME LA OPERACION QUE DESEAS HACER: ",'$'       
MSJN3 DB 10,13, "DAME EL SEGUNDO NUMERO: ",'$'
ERROR DB 10,13, "ERROR...OPERACION INVALIDA",13,10, '$'


;MENSAJES PARA MOSTRAR LOS RESULTADOS EN PANTALLA--------------    
MSJNS DB 10,13, "SUMA: ",'$'    
MSJNR DB 10,13, "RESTA: ",'$'
MSJNM DB 10,13, "MULTIPLICACION: ",'$'
MSJND DB 10,13, "DIVISION: ",'$'
MSJNMOD DB 10,13, "RESIDUO: ",'$' 



.CODE        
INICIO PROC FAR
    ;DIRECCIONAMIENTO DEL PROCEDIMIENTO 
OTRO:
    MOV AX, @DATA
    MOV DS,AX
    
    ;PEDIMOS EL NUMERO 1
    
    MOV AH, 09
    LEA DX, MSJN1
    INT 21H
    MOV AH, 01
    INT 21H 
    SUB AL, 30H
    MOV NUM1, AL
    MOV BL,NUM1   
    
    ;PEDIMOS EL SIGNO DE LA OPERACION
    MOV AH, 09
    LEA DX,MSJOP
    INT 21H
    MOV AH, 01
    INT 21H
    MOV SIGNO,AL
    
    
    ;PEDIMOS EL NUMERO 2
    MOV AH, 09
    LEA DX, MSJN3
    INT 21H
    MOV AH, 01
    INT 21H 
    SUB AL, 30H
    MOV NUM2, AL
    MOV BH,NUM2   
                 
                 
    ;HACEMOS LA VALIDACION
    CMP SIGNO,'+' 
    JE HACER_SUMA
     
    CMP SIGNO,'-' 
    JE HACER_RESTA
    
    CMP SIGNO,'*' 
    JE HACER_MULTIPLICACION 
    
    CMP SIGNO,'/' 
    JE HACER_DIVISION 
    
    CMP SIGNO, '#' ;FIN DEL PROGRAMA
    JE FIN
    
    MOV AH,09H
    LEA DX, ERROR
    INT 21H
    JMP OTRO  
    
                  
    ;HACEMOS LAS OPERACIONES 
         
HACER_SUMA:
    
        ADD SUMA,BL
        ADD SUMA,BH
        
        MOV AH,09
        LEA DX,MSJNS
        INT 21H
        MOV DL,SUMA
        ADD DL,30H
        MOV AH,02
        INT 21H 
        INT 20H
        
        ; =======
                
;        MOV AL,SUMA
 ;       AAM
 ;       MOV BX, AX
 ;       MOV AH, 02H
 ;       MOV DL,BH
 ;       ADD DL,30H
 ;       INT 21H
          
 ;       MOV AH, 02H
 ;       MOV DL, BL
 ;       ADD DL,30H
 ;       INT 21H 
 ;       INT 20H
        
        
HACER_RESTA:
    
        ADD RESTA,BL
        SUB RESTA,BH 
        
        MOV AH,09
        LEA DX,MSJNR
        INT 21H
        MOV DL,RESTA
        ADD DL,30H
        MOV AH,02
        INT 21H
        INT 20H

        
        
        
HACER_MULTIPLICACION:
     
        MOV AL,BL
        MUL BH
        MOV MULTI,AL 
        
        MOV AH,09
        LEA DX,MSJNM
        INT 21H
        MOV DL,MULTI
        ADD DL,30H
        MOV AH,02
        INT 21H 
        INT 20H

        
        

        
HACER_DIVISION:
     
        MOV AL,BL
        DIV BH
        MOV DIVISION, AL 
        
        ;RESIDUO
        MOV AL,BL
        DIV BH
        MOV MODULO,AH  
        
        ;MOSTRAMOS RESULTADOS
        
        MOV AH,09
        LEA DX,MSJND
        INT 21H
        MOV DL,DIVISION
        ADD DL,30H
        MOV AH,02
        INT 21H 
        
        
        MOV AH,09
        LEA DX,MSJNMOD
        INT 21H
        MOV DL,MODULO
        ADD DL,30H
        MOV AH,02
        INT 21H
        INT 20H
     
;CIERRE DEL PROGRAMA
FIN:
MOV AH,4CH
INT 21H

INICIO ENDP 

END







; // ============================================================== codigo para xd
 ;COMPROBAMOS LOS VALORES: A,B,C,D,E,F
    CMP NUM1, 'A'
    JE  CNUM1A
    CMP NUM1, 'B'
    JE  CNUM1B
    CMP NUM1, 'C'
    JE  CNUM1C
    CMP NUM1, 'D'
    JE  CNUM1D
    CMP NUM1, 'E'
    JE  CNUM1E
    CMP NUM1, 'F'
    JE  CNUM1F
    
    CMP NUM1, 'a'
    JE  CNUM1A
    CMP NUM1, 'b'
    JE  CNUM1B
    CMP NUM1, 'c'
    JE  CNUM1C
    CMP NUM1, 'd'
    JE  CNUM1D
    CMP NUM1, 'e'
    JE  CNUM1E
    CMP NUM1, 'f'
    JE  CNUM1F   
    ; ==========
    CMP NUM2, 'A'
    JE  CNUM2A
    CMP NUM2, 'B'
    JE  CNUM2B
    CMP NUM2, 'C'
    JE  CNUM2C
    CMP NUM2, 'D'
    JE  CNUM2D
    CMP NUM2, 'E'
    JE  CNUM2E
    CMP NUM2, 'F'
    JE  CNUM2F
    
    CMP NUM2, 'a'
    JE  CNUM2A
    CMP NUM2, 'b'
    JE  CNUM2B
    CMP NUM2, 'c'
    JE  CNUM2C
    CMP NUM2, 'd'
    JE  CNUM2D
    CMP NUM2, 'e'
    JE  CNUM2E
    CMP NUM2, 'f'
    JE  CNUM2F
    
    ; cmp xdxd
    
    CNUM1A:
    mov al, jajajdiez
    MOV NUM1, al
    .exit
    
    CNUM1B:
    MOV NUM1, 11
    .exit
    CNUM1C:
    MOV NUM1, 12
    .exit
    CNUM1D:
    MOV NUM1, 13
    .exit
    CNUM1E:
    MOV NUM1, 14
    .exit
    CNUM1F:
    MOV NUM1, 15
    .exit
    
    CNUM2A:
    mov al, jajajdiez
    MOV NUM2, al
    .exit
    
    CNUM2B:
    MOV NUM2, 11
    .exit
    CNUM2C:
    MOV NUM2, 12
    .exit
    CNUM2D:
    MOV NUM2, 13
    .exit
    CNUM2E:
    MOV NUM2, 14
    .exit
    CNUM2F:
    MOV NUM2, 15
    .exit 
    
    ;=============
    ; CREO QUE YA XDXDXD
    ; :(



















; // ESTE ES EL ULTIMO CODIGO ENTERO DE MI NOVIA JAJAJ

.MODEL
.STACK 64
.DATA

;DECLARACION DE VARIABLES--------------------------------------

NUM1     DB ?
NUM2     DB ?
SIGNO    DB ?,'$'
SIGNO2   DB ?,'$'
SUMA     DB ?
RESTA    DB ?
MULTI    DB ?
DIVISION DB ?
MODULO   DB ?




;MENSAJES PARA PEDIR LOS DATOS---------------------------------
MSJN1 DB 10,13, "DAME EL PRIMER NUMERO: ",'$'
MSJOP DB 10,13, "DAME LA OPERACION QUE DESEAS HACER: ",'$'       
MSJN3 DB 10,13, "DAME EL SEGUNDO NUMERO: ",'$'
ERROR DB 10,13, "ERROR...OPERACION INVALIDA",13,10, '$'
SALIR DB 10,13, "PRESIONA '#' PARA SALIR O CUALQUIER OTRA TECLA PARA CONTINUAR",13,10,'$'

;MENSAJES PARA MOSTRAR LOS RESULTADOS EN PANTALLA--------------    
MSJNS DB 10,13, "SUMA: ",'$'    
MSJNR DB 10,13, "RESTA: ",'$'
MSJNM DB 10,13, "MULTIPLICACION: ",'$'
MSJND DB 10,13, "DIVISION: ",'$'
MSJNMOD DB 10,13, "RESIDUO: ",'$' 



.CODE        
INICIO PROC FAR
    ;DIRECCIONAMIENTO DEL PROCEDIMIENTO 
OTRO:
    MOV AX, @DATA
    MOV DS,AX 
    
    ;MOSTRAMOS EL MENSAJE DE SALIDA
    MOV AH, 09
    LEA DX,SALIR
;MOSTRAMOS EL MENSAJE DE SALIDA
    MOV AH, 09
    LEA DX,SALIR
    INT 21H
    MOV AH, 01
    INT 21H
    MOV SIGNO2,AL
    
        
    CMP SIGNO2, '#' ;FIN DEL PROGRAMA
    JE FIN
    
    ;PEDIMOS EL NUMERO 1
    
    MOV AH, 09
    LEA DX, MSJN1
    INT 21H
    MOV AH, 01
    INT 21H 
    SUB AL, 30H
    MOV NUM1, AL
    MOV BL,NUM1   
    
    ;PEDIMOS EL SIGNO DE LA OPERACION
    MOV AH, 09
    LEA DX,MSJOP
    INT 21H
    MOV AH, 01
    INT 21H
    MOV SIGNO,AL
    
    
    ;PEDIMOS EL NUMERO 2
    MOV AH, 09
    LEA DX, MSJN3
    INT 21H
    MOV AH, 01
    INT 21H 
    SUB AL, 30H
    MOV NUM2, AL
    MOV BH,NUM2   
                 
                 
    ;HACEMOS LA VALIDACION
    CMP SIGNO,'+' 
    JE HACER_SUMA
     
    CMP SIGNO,'-' 
    JE HACER_RESTA
    
    CMP SIGNO,'*' 
    JE HACER_MULTIPLICACION 
    
    CMP SIGNO,'/' 
    JE HACER_DIVISION 
    
    MOV AH,09H
    LEA DX, ERROR
    INT 21H
    JMP OTRO  
    
                  
    ;HACEMOS LAS OPERACIONES 
         
HACER_SUMA:
 ADD SUMA,BL
        ADD SUMA,BH
        
        MOV AH,09
        LEA DX,MSJNS
        INT 21H
        MOV DL,SUMA
        ADD DL,30H
        MOV AH,02
        INT 21H 
        JMP OTRO
                     
        
HACER_RESTA:
    
        ADD RESTA,BL
        SUB RESTA,BH 
        
        MOV AH,09
        LEA DX,MSJNR
        INT 21H
        MOV DL,RESTA
        ADD DL,30H
        MOV AH,02
        INT 21H
        JMP OTRO
        
        
        
HACER_MULTIPLICACION:
     
        MOV AL,BL
        MUL BH
        MOV MULTI,AL 
        
        MOV AH,09
        LEA DX,MSJNM
        INT 21H
        MOV DL,MULTI
        ADD DL,30H
        MOV AH,02
        INT 21H 
        JMP OTRO

        
HACER_DIVISION:
     
        MOV AL,BL
        DIV BH
        MOV DIVISION, AL 
        
        ;RESIDUO
        MOV AL,BL
        DIV BH
        MOV MODULO,AH  
        
        ;MOSTRAMOS RESULTADOS
        
        MOV AH,09
        LEA DX,MSJND
        INT 21H
        MOV DL,DIVISIO
;MOSTRAMOS RESULTADOS
        
        MOV AH,09
        LEA DX,MSJND
        INT 21H
        MOV DL,DIVISION
        ADD DL,30H
        MOV AH,02
        INT 21H 
        
        
        MOV AH,09
        LEA DX,MSJNMOD
        INT 21H
        MOV DL,MODULO
        ADD DL,30H
        MOV AH,02
        INT 21H
        JMP OTRO
     
;CIERRE DEL PROGRAMA
FIN:
MOV AH,4CH
INT 21H

INICIO ENDP 

END
