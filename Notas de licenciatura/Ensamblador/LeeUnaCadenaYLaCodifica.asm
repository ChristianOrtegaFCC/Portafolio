.MODEL SMALL
.STACK 64
.DATA
    INGRESAR DB 10,13,'Ingresa una frase (maximo 25 caracteres): ', 10,13,'$'
    MSJCADENA DB 10,13,'Cadena codificada: $'
    CADE DB 0AH, 00, 1AH DUP ('$') ;1AH ES LA LONGITUD MAXIMA DE CARACTERES EN LA CADENA

.CODE
MOV AX,@DATA
MOV DS,AX
; >>>> [" MAIN "] >>>>V
                     ;V
CALL INICIALIZA      ;V
CALL ENCRIPTA        ;V
CALL MUESTRA         ;V
                     ;V
; ENDP MAIN <<<<<<<<<<V

INICIALIZA PROC NEAR; <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<V  
LEA DX,INGRESAR                                                                        ;V
MOV AH,09                                                                              ;V
INT 21H                                                                                ;V
;INICIAMOS NUESTRO CONTEO DEL SI EN LA POSICION 0.                                     ;V
MOV SI,00H                                                                             ;V
RET                                                                                    ;V
INICIALIZA ENDP; >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>V                                                                        ;V
                                                                                       
                                                                                       
ENCRIPTA PROC NEAR; <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<;V
LEER:                                                                                  ;V
    MOV AX,0000                                                                        ;V
    MOV AH,01h                                                                         ;V
    INT 21h                                                                            ;V
    ;   >>> DEBEMOS CODIFICAR EL MENSAJE SUMANDO 1 A CADA CARACTER) <<<                ;V
    MOV CADE[SI],AL  ;GUARDAMOS EL CARACTER DADO EN LA POSICION [SI] DEL VECTOR        ;V
    ADD CADE[SI],01H ;SUMAMOS 1 A CADA CARACTER Y HA QUEDADO CODIFICADO!!              ;V
    ;                                                                                  ;V
    ;                                                                                  ;V
    ; DEBEMOS VERIFICAR SI EL CARACTER [SI] ES UN CASO ESPECIAL, COMO:________________.;V
    ; 'Z' , 'z' , '0' , 'SPACE' , 'ENTER'.                                            |;V
    ;                                                                                 |;V
    CMP CADE[SI],'['   ;ES EL CARACTER QUE SIGUE DESPUES DE LA 'Z' EN LA TABLA ASCII, |;V
    JE RESTA_Z         ;ENTONCES DEBEMOS RESTAR 1AH UNIDADES PARA OBTENER LA 'A'      |;V
    ;                                                                                 |;V
    CMP CADE[SI],'{'   ;ES EL CARACTER QUE SIGUE DESPUES DE LA 'z' EN LA TABLA ASCII, |;V
    JE RESTA_Z         ;ENTONCES DEBEMOS RESTAR 1AH UNIDADES PARA OBTENER LA 'a'      |;V
    ;                                                                                 |;V
    CMP CADE[SI],':'   ;ES EL CARACTER QUE SIGUE DESPUES DEL '0' EN LA TABLA ASCII,   |;V
    JE SUB_NINE        ;ENTONCES DEBEMOS RESTAR AH UNIDADES PARA OBTENER EL '1'       |;V
    ;                                                                                 |;V
    CMP CADE[SI],21H   ;ES EL VALOR QUE SIGUE DESPUES DEL VALOR DEL 'SPACE' EN LA     |;V
    JE SUB_ONE         ;TABLA ASCII, ENTONCES LE RESTAMOS 1 PARA CONSERVAR SU VALOR   |;V
    ;                                                                                 |;V
    CMP CADE[SI], 0EH  ;ES EL VALOR QUE SIGUE DESPUES DEL VALOR DEL 'ENTER' EN LA     |;V
    JE SUB_ONE         ;TABLA ASCII, ENTONCES LE RESTAMOS 1 PARA CONSERVAR SU VALOR   |;V
    ;                                                                                 |;V
    JMP CONTINUE   ;SI EL CARACTER NO FUE UN 'CASO ESPECIAL', CONTINUAMOS NORMAL...   |;V
    ;                                                                                 |;V
            ;______[ NO SE USARA 'NI RESTA_Z' NI 'SUB_ONE' SI NO SE REQUIERE ]____.   |;V
            RESTA_Z:   ;ES EL MODULO DE RESTA PARA LA 'Z' Y 'z'                   |   |;V
            SUB CADE[SI],1AH;                                                     |   |;V
            JMP CONTINUE; AL HACER LA CONVERSION CORRESPONDIENTE, CONTINUAMOS     |   |;V
            ;                                                                     |   |;V
            SUB_NINE:  ;ES EL MODULO DE RESTA PARA EL 0                           |   |;V
            SUB CADE[SI], 0AH;                                                    |   |;V
            JMP CONTINUE;                                                         |   |;V
            ;                                                                     |   |;V
            SUB_ONE:   ;ES EL MODULO DE RESTA PARA 'SPACE' Y 'ENTER'              |   |;V
            SUB CADE[SI],01H;                                                     |   |;V
            JMP CONTINUE;_AL HACER LA CONVERSION CORRESPONDIENTE, CONTINUAMOS_____|   |;V
    ;_________________________________________________________________________________|;V
                                                                                       ;V
CONTINUE:                                                                              ;V
INC SI   ;INCREMENTAMOS NUESTRO CONTADOR.                                              ;V
    CMP SI, 25 ; EL MAXIMO DE CARACTERES PERMITIDOS SERA DE 25decimal.                 ;V
    JE ENOF    ; SI SE SOBREPASA, TERMINAMOS DE LEER                                   ;V
        CMP AL,0DH  ;SE REPITE EL INGRESO DE DATOS HASTA QUE SE TECLEE UN ENTER.       ;V
        JA LEER                                                                        ;V
        JB LEER                                                                        ;V
ENOF:                                                                                  ;V
RET                                                                                    ;V
ENCRIPTA ENDP; >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>V
 
 
MUESTRA PROC NEAR; <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<V
LEA DX, MSJCADENA   ;IMPRIME "CADENA INGRESADA: "                                         ;V
MOV AH,09H                                                                                ;V
INT 21H                                                                                   ;V
                                                                                          ;V
MOV DX,OFFSET CADE;IMPRIME EL CONTENIDO DEL VECTOR CON LA MISMA INSTRUCCION DE UNA CADENA.;V
MOV AH,09H        ;Y LO IMPRIMIRA YA ENCRIPTADO                                           ;V
INT 21H                                                                                   ;V
                                                                                          ;V                     
MOV AH,4CH  ; FIN DEL PROGRAMA                                                            ;V
INT 21H                                                                                   ;V
RET                                                                                       ;V
MUESTRA ENDP; >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>V

END  