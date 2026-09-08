.MODEL
.STACK 64
.DATA

;DECLARACION DE VARIABLES--------------------------------------
NUM1     DB ?
NUM2     DB ?

SIGNO    DB ?,'$'
SIGNO2   DB ?,'$'
RESULTADO DB ?
BANDMOD DB ? 
MODULO DB ?
;MENSAJES PARA PEDIR LOS DATOS---------------------------------
MSJN1 DB 10,13, "DAME EL PRIMER NUMERO  : ",'$'
MSJOP DB 10,13, "DAME EL SIGNO          : ",'$'       
MSJN3 DB 10,13, "DAME EL SEGUNDO NUMERO: ",'$'
ERROR DB 10,13, "ERROR...OPERACION INVALIDA",13,10, '$'
SALIR DB 10,13, "PRESIONA '#' PARA SALIR O CUALQUIER OTRA TECLA PARA CONTINUAR",13,10,'$'
;MENSAJES PARA MOSTRAR LOS RESULTADOS EN PANTALLA--------------    
MSJNS DB " + ",'$'    
MSJNR DB " - ",'$'
MSJNM DB " * ",'$'
MSJND DB " / ",'$'
MSJNMOD DB "RESIDUO: ",'$'
MSJNIGUAL DB " = ",'$'
;AUXILIARES NECESARIOS EN LA EJECUCION
AUXENTER DB 10,13, "",'$'
AUXRES DB ?

NUM1R     DB ?
NUM2R     DB ?
NUM1L     DB ?
NUM2L     DB ?


.CODE        
INICIO PROC FAR ;=========================================================================
    ;DIRECCIONAMIENTO DEL PROCEDIMIENTO 
OTRO:
    MOV AX, @DATA
    MOV DS,AX 
    
    ;MOSTRAMOS EL MENSAJE DE SALIDA POR PRIMERA VEZ
    MOV AH, 09
    LEA DX,SALIR
    ;MOSTRAMOS EL MENSAJE DE SALIDA PERO DENTRO DEL BUCLE
    MOV AH, 09
    LEA DX,SALIR
    INT 21H
    MOV AH, 01
    INT 21H
    MOV SIGNO2,AL
    
        
    CMP SIGNO2, '#' ;FIN DEL PROGRAMA
    JE FIN
    
    MOV BANDMOD, 0H ; BANDMOD SE ACTIVARA SI SE HACE LA OPERACION DE DIVISION
    
    ;PEDIMOS EL NUMERO 1 ===========================================
    
    MOV AH, 09     ; servicio interrupcion 21h, que imprime cadenas
    LEA DX, MSJN1  ; imprimimos "dame numero 1" (o algo asi)
    INT 21H
    
    ; =============== NUM1LEFT
    MOV AH, 01H    ; servicio interrupcion 21h, que lee el dato 
    INT 21H        ; en este caso... NUM1
    
    CMP AL, 39H
    JBE RESN1LRAND  ; brincamos a "resta de numero 1 rango decimal"
    CMP AL, 41H
    JAE RESN1LRANH  ; brincamos a "resta de numero 1 rango hexadecimal"
       
        RESN1LRAND: ; aqui hacemos la "resta de numero 1 rango decimal" 
        SUB AL, 30H
        MOV NUM1L, AL
        JMP NUM1RIGHT ; Con "RETORNO1" vamos a la parte de leer el signo
        
        RESN1LRANH: ; aqui naturalmente hacemos lo mismo pero para el
        SUB AL,37H ; rango hexadecimal
        MOV NUM1L, AL 
        JMP NUM1RIGHT
    ; =============== NUM1RIGHT
    NUM1RIGHT:          
    MOV AH, 01H    ; servicio interrupcion 21h, que lee el dato 
    INT 21H        ; en este caso... NUM1
    
    CMP AL, 39H
    JBE RESN1RAND  ; brincamos a "resta de numero 1 rango decimal"
    CMP AL, 41H
    JAE RESN1RANH  ; brincamos a "resta de numero 1 rango hexadecimal"
       
        RESN1RAND: ; aqui hacemos la "resta de numero 1 rango decimal" 
        SUB AL, 30H
        MOV NUM1R, AL
        JMP RETORNO1 ; Con "RETORNO1" vamos a la parte de leer el signo
        
        RESN1RANH: ; aqui naturalmente hacemos lo mismo pero para el
        SUB AL,37H ; rango hexadecimal
        MOV NUM1R, AL 
        JMP RETORNO1
        
    RETORNO1:    
    
    MOV AL, NUM1L    ;AUN NO C COMO EXPLICAR ESTO
    MOV BL, 10
    MUL BL
    ADD AL,NUM1R
    MOV NUM1,AL
    
    ;PEDIMOS EL SIGNO DE LA OPERACION ==============================
    MOV AH, 09H
    LEA DX,MSJOP
    INT 21H
    MOV AH, 01
    INT 21H
    MOV SIGNO,AL
    
    
    ;PEDIMOS EL NUMERO 2 ===========================================
    
    MOV AH, 09H     ; servicio interrupcion 21h, que imprime cadenas
    LEA DX, MSJN3  ; imprimimos: "dame numero 2" (o algo asi jaja)
    INT 21H
    
    MOV AH, 01     
    INT 21H        ; servicio interrupcion 21h , lee NUM2...
    
    CMP AL, 39H
    JBE RESN2LRAND  ; brincamos a "resta de numero 1 rango decimal"
    CMP AL, 41H
    JAE RESN2LRANH  ; brincamos a "resta de numero 1 rango hexadecimal"
                
        RESN2LRAND: ; aqui hacemos la "resta de numero 2 rango decimal" 
        SUB AL, 30H
        MOV NUM2L, AL ; guardamos el dato en NUM2
        JMP NUM2RIGHT 
        
        RESN2LRANH: ; creo que ya se enendio la idea ;)
        SUB AL,37H 
        MOV NUM2L, AL  
        JMP NUM2RIGHT
    ; =============== NUM2RIGHT
    NUM2RIGHT:
    MOV AH, 01     
    INT 21H        ; servicio interrupcion 21h , lee NUM2...
    
    CMP AL, 39H
    JBE RESN2RAND  ; brincamos a "resta de numero 1 rango decimal"
    CMP AL, 41H
    JAE RESN2RANH  ; brincamos a "resta de numero 1 rango hexadecimal"
                
        RESN2RAND: ; aqui hacemos la "resta de numero 2 rango decimal" 
        SUB AL, 30H
        MOV NUM2R, AL ; guardamos el dato en NUM2
        JMP RETORNO2 ; con esto vamos a la parte de validacion del signo
        
        RESN2RANH: ; creo que ya se enendio la idea ;)
        SUB AL,37H 
        MOV NUM2R, AL  
        JMP RETORNO2
      
    RETORNO2:
    
    MOV AL, NUM2L    ;AUN NO C COMO EXPLICAR ESTO
    MOV BL, 10
    MUL BL
    ADD AL,NUM2R
    MOV NUM2,AL
    
    ; para ahorrar lineas, empezamos a escribir el numero 1 despues en los
    ; modulos de cada operacion se imprimira el signo correspondiente, el
    ; numero 2 y el signo de igual usando los saltos correspondientes
    MOV AH,09
    LEA DX,AUXENTER ; imprimimos salto de linea
    INT 21H
    
    JMP IMPRIMENUM1
    
    RETORNO3:             
    ;HACEMOS LA VALIDACION DEL SIGNO
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
        ; >>>>   todas las operaciones se manejaran de la forma    <<<<
        ; >>>>   que se muestra a continuacion...                  <<<<
        
        ; esto es para imprimir la segunda parte
        ; de la operacion con el formato bonito
        
        MOV AH,09       
        LEA DX,MSJNS   ; imprimimos signo, en este caso suma
        INT 21H
           
        JMP IMPRIMENUM2  ; SALTAMOS AL MODULO DE IMPRESION DE NUMEROS
        RETORNONS:       ; UNA VEZ IMPRESO EL NUMERO 2 (JUNTO CON EL SIGNO IGUAL), VOLVEMOS A AQUI
                         ; PARA EFECTUAR LA OPERACION CORRESPONDIENTE
        
        ;operamos suma
        MOV AL, NUM1        
        ADD AL, NUM2             
        MOV RESULTADO, AL      
        
        SHR AL,4H            ;Usamos "shift right" para obtener el digito de la izquierda  
        MOV AUXRES, AL            
        MOV BL, RESULTADO      
        AND BL,00001111B     ;Usamos "and "para obtener el digito de la derecha    
        MOV RESULTADO, BL
            
        JMP CONVRES1   ; CONVRES1 sera en donde empieze el proceso de imprimir el
                       ; resultado
                     
        
HACER_RESTA:        
        ;imprimir con formato bonito...              
        MOV AH,09
        LEA DX,MSJNR
        INT 21H
        
        ; De la etiqueta "HACER_SUMA es que sabemos como funcionan estas lineas ;)"
        JMP IMPRIMENUM2       
        RETORNONR:    
        
        ; operamos resta
        MOV AL, NUM1    
        SUB AL, NUM2    
        MOV RESULTADO, AL    
        
        SHR AL,4H             ;Usamos "shift right" para obtener el digito de la izquierda
        MOV AUXRES, AL      
        MOV BL, RESULTADO    
        AND BL,00001111B      ;Usamos "and "para obtener el digito de la derecha   
        MOV RESULTADO, BL
            
        JMP CONVRES1
        
        
HACER_MULTIPLICACION:
        ; imprimimos...       
        MOV AH,09
        LEA DX,MSJNM
        INT 21H
        
        JMP IMPRIMENUM2       
        RETORNONM:       
        
        ;Operamos multiplicacion...      
        MOV AL, NUM1    
        MOV BL, NUM2    
        MUL BL          
        MOV RESULTADO, AL      
        
        SHR AL,4H             ;Usamos "shift right" para obtener el digito de la izquierda
        MOV AUXRES, AL    
        MOV BL, RESULTADO   
        AND BL,00001111B      ;Usamos "and "para obtener el digito de la derecha
        MOV RESULTADO, BL
           
        JMP CONVRES1 

        
HACER_DIVISION:
        ; imprimimos signo...
        MOV BANDMOD, 01H ; ACTIVAMOS LA BANDERA DE MOD PARA INCLUIRLO EN LA OPERACION        
        MOV AH,09
        LEA DX,MSJND
        INT 21H
        
        JMP IMPRIMENUM2       
        RETORNOND:
        
        ; Operamos division  
        XOR AX, AX     ; XOR se usa para limiar el registro AX porque la division siempre presenta 
                       ; muchas dificultades por motivos que ignoro jajaj 
        MOV AL, NUM1
        MOV BL, NUM2
        DIV BL
        MOV RESULTADO, AL   
        SHR AL,4            ; usamos shift right...... 
        MOV AUXRES, AL    
        MOV BL, RESULTADO  
        AND BL,00001111B    ; usamos and....
        MOV RESULTADO, BL
               
        JMP CONVRES1 
HACER_MOD:
  
  MOV AH,09
  LEA DX,AUXENTER ; imprimimos salto de linea
  INT 21H
  
  ; OPERAMOS RESIDUO...
  XOR AX, AX
  MOV BL, NUM1
  MOV BH, NUM2
  
  MOV AL,BL
  DIV BH
  MOV MODULO,AH
        
  ; ahora lo imprimimos
  MOV AH,09
  LEA DX,MSJNMOD
  INT 21H
  MOV DL,MODULO
  ADD DL,30H
  MOV AH,02
  INT 21H
  
JMP OTRO

    ; MODULO DONDE IMPRIMIREMOS TANTO NUMERO 1 COMO NUMERO 2
    ;. .  . |\ |\ . .  . .__    .  .      .  . .__ |\ .__. .___
    ;| |\/| |/ |/ | |\/| |__    |\ | |  | |\/| |__ |/ |  | |__.
    ;| |  | |  |\ | |  | |__    | \| |__| |  | |__ |\ |__| ___|
    ;
    ; DEPENDIENDO DEL RANGO DEL NUMERO >> 1 << SERA COMO SE IMPRIMA
    IMPRIMENUM1:
    CMP NUM1L, 9H
    JBE IMP1LD       ; brincamos a "IMPRIMIR NUMERO 1 en rango decimal"
    CMP NUM1L, 10
    JAE IMP1LH       ; brincamos a "IMPRIMIR NUMERO 1 en rango hexadecimal"
       
    IMP1LD: ;Imprimimos numero 1 en rango decimal         
        MOV DL,NUM1L    
        ADD DL,30H
        MOV AH,02
        INT 21H
        JMP CONTINUEIMPN1R:
     
    IMP1LH: ;Imprimimos numero 1 en rango hexadecimal
        MOV DL,NUM1L    
        ADD DL,37H
        MOV AH,02
        INT 21H
        JMP CONTINUEIMPN1R:
            
            CONTINUEIMPN1R:
            CMP NUM1R, 9H
            JBE IMP1RD       ; brincamos a "IMPRIMIR NUMERO 1 en rango decimal"
            CMP NUM1R, 10
            JAE IMP1RH       ; brincamos a "IMPRIMIR NUMERO 1 en rango hexadecimal"
       
            IMP1RD: ;Imprimimos numero 1 en rango decimal         
            MOV DL,NUM1R    
            ADD DL,30H
            MOV AH,02
            INT 21H
            JMP RETORNO3
     
            IMP1RH: ;Imprimimos numero 1 en rango hexadecimal
            MOV DL,NUM1R    
            ADD DL,37H
            MOV AH,02
            INT 21H
            JMP RETORNO3
    
    ; DEPENDIENDO DEL RANGO DEL NUMERO >> 2 << SERA COMO SE IMPRIMA
    IMPRIMENUM2:
    CMP NUM2L, 9H
    JBE IMP2LD       ; brincamos a "IMPRIMIR NUMERO 2 en rango decimal"
    CMP NUM2L, 10
    JAE IMP2LH       ; brincamos a "IMPRIMIR NUMERO 2 en rango hexadecimal"
       
    IMP2LD: ;Imprimimos numero 2 en rango decimal         
        MOV DL,NUM2L    
        ADD DL,30H
        MOV AH,02
        INT 21H
        
        JMP CONTINUEIMPN2R
     
    IMP2LH: ;Imprimimos numero 2 en rango hexadecimal
        MOV DL,NUM2L    
        ADD DL,37H
        MOV AH,02
        INT 21H
        
        JMP CONTINUEIMPN2R
        
    ; =====
            CONTINUEIMPN2R:
            CMP NUM2R, 9H
            JBE IMP2RD       ; brincamos a "IMPRIMIR NUMERO 2 en rango decimal"
            CMP NUM2R, 10
            JAE IMP2RH       ; brincamos a "IMPRIMIR NUMERO 2 en rango hexadecimal"
       
            IMP2RD: ;Imprimimos numero 2 en rango decimal         
            MOV DL,NUM2R    
            ADD DL,30H
            MOV AH,02
            INT 21H
        
            JMP RETORNOs1
     
            IMP2RH: ;Imprimimos numero 2 en rango hexadecimal
            MOV DL,NUM2R    
            ADD DL,37H
            MOV AH,02
            INT 21H
        
            JMP RETORNOs1
          
    RETORNOs1:
    
     MOV AH,09       ; Imprimimos el signo
     LEA DX,MSJNIGUAL
     INT 21H
    ;HACEMOS EL RETORNO CORRESPONDIENTE:
    CMP SIGNO,'+' 
    JE RETORNONS
     
    CMP SIGNO,'-' 
    JE RETORNONR
    
    CMP SIGNO,'*' 
    JE RETORNONM 
    
    CMP SIGNO,'/' 
    JE RETORNOND
  
    ; .__ . .  .    . .  . |\ |\ . .  . .__
    ; |_  | |\ |    | |\/| |/ |/ | |\/| |__
    ; |   | | \|    | |  | |  |\ | |  | |__


; MODULO DE CONVERSION DEL RESULTADO
; .__ .__. .  .      . .__ |\ _|_ .__     |\ .__ .___
; |   |  | |\ | \  / | |__ |/  |  |__     |/ |__ |__
; |__ |__| | \|  \/  | |__ |\  |  |__     |\ |__ ___|

CONVRES1:  ; empezamos proceso de conversion del resultado 

MOV AL, AUXRES    
CMP AL, 09H          
JBE SRRAND1     ;Si el resultado esta en un rango decimal, hacemos el proceso decimal   
JMP SRRANH1     ;Si el resultado esta en rango hexadecimal, hacemos el hexadecimal
    
    SRRAND1:

    MOV DL, AUXRES              
    ADD DL, 30H     ;Sumamos 30h porque es la conversion correspondiente    
    MOV AUXRES,DL   ;guardamos el resultado en AUXRES    
    
    MOV DL, AUXRES      
    MOV AH, 02H     ;imprimimos el caracter que toca imprimir... el de la izquierda 
    INT 21H    
    JMP CONVRES2


    SRRANH1: 

    MOV DL, AUXRES  
    ADD DL, 37H     ;sumamos 37h porque es la conversion que corresponde 
    MOV AUXRES,DL   ;guardamos el resultado en AUXRES   

    MOV DL, AUXRES       
    MOV AH, 02H     ;imprimimos el caracter que toca imprimir... el de la izquierda
    INT 21H    
    
    

CONVRES2:

MOV AL, RESULTADO    
CMP AL, 09H          
JBE SRRAND2     ;Si el resultado esta en un rango decimal, hacemos el proceso decimal   
JMP SRRANH2     ;Si el resultado esta en un rango hexadecimal, lo hacemos en hexadecimal 
    
    SRRAND2:

    MOV DL, RESULTADO              
    ADD DL, 30H         ;Sumamos 30h porque es la conversion correspondiente  
    MOV RESULTADO,DL      
    MOV DL, RESULTADO     
    MOV AH, 02H        ; imprimimos el caracter que faltaba, el derecho
    INT 21H
    CMP BANDMOD, 1H    ; Si la operacion es division, se incluye el modulo
    JE HACER_MOD    
    JMP OTRO ; saltamos a la validacion de repetir el proceso


    SRRANH2: 

    MOV DL, RESULTADO 
    ADD DL, 37H         ;Sumamos 37h porque es la conversion correspondiente 
    MOV RESULTADO,DL   
    MOV DL, RESULTADO       
    MOV AH, 02H          ; imprimimos el caracter que faltaba, el derecho
    INT 21H
    CMP BANDMOD, 1H      ; Si la operacion es division, se incluye el modulo
    JE HACER_MOD
    JMP OTRO 
; .__ . .  .    .__ .__. .  .      . .__ |\ _|_ .__     |\ .__ .___
; |_  | |\ |    |   |  | |\ | \  / | |__ |/  |  |__     |/ |__ |__
; |   | | \|    |__ |__| | \|  \/  | |__ |\  |  |__     |\ |__ ___|
   
;CIERRE DEL PROGRAMA
FIN:
MOV AH,4CH
INT 21H

INICIO ENDP 

END