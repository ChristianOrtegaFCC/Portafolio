SUMAVECTORES MACRO  LIM

CALL ONE
CALL TWO
CALL OP          
JMP TERMINAR           
           
           
ONE PROC NEAR ; ===============================================================         
    ;INICIAMOS NUESTRO CONTEO DEL SI EN LA POSICION 0.                                
    MOV SI,00H   
LEEVEC1:   
    MOV AX,0000                       
    MOV AH,01h                                              
    INT 21h                                                                          
    MOV VEC1[SI],AL  ;GUARDAMOS EL CARACTER DADO EN LA POSICION [SI] DEL VECTOR  
    
    INC SI   ;INCREMENTAMOS EL SI
    MOV LIM, SI
    CMP SI, 9 ;EL MAXIMO DE ELEMENTOS PERMITIDOS SERA DE 9decimal.
    JE ENOF    ; SI SE SOBREPASA, TERMINAMOS DE LEER  
        CMP AL,0DH  ;SE REPITE EL INGRESO DE DATOS HASTA QUE SE TECLEE UN ENTER.    
        JA LEEVEC1                                                                        
        JB LEEVEC1                                                                          
ENOF:                                                                                    
RET   
ONE ENDP

TWO PROC NEAR ; ===============================================================     
    ;INICIAMOS NUESTRO CONTEO DEL SI EN LA POSICION 0.                                
    MOV SI,00H   
LEEVEC2:   
    MOV AX,0000                       
    MOV AH,01h                                              
    INT 21h                                                                          
    MOV VEC2[SI],AL  ;GUARDAMOS EL CARACTER DADO EN LA POSICION [SI] DEL VECTOR  
    
    INC SI   ;INCREMENTAMOS EL SI
    CMP SI, LIM ;EL MAXIMO DE ELEMENTOS PERMITIDOS SERA LO QUE TENGA EL OTRO VECTOR.
    JE ENOF2    ;SE REPITE EL PROCESO HASTA QUE OBTENGAMOS TODOS LOS ELEMENTOS 
                                                                                 
ENOF2:                                                                                    
RET   
TWO ENDP     

OP PROC NEAR ; ================================================================     
    ;INICIAMOS NUESTRO CONTEO DEL SI EN LA POSICION 0.                                
    MOV SI,00H   
SUMAVTS:   
    MOV AX,0000                       
    MOV AH,01h                                              
    INT 21h                                                                          
    MOV VECR[SI],VEC1[SI]  ;GUARDAMOS EL CARACTER DADO EN LA POSICION [SI] DEL VECTOR  
    ADD VECR[SI],VEC2[SI]
    
    
    INC SI   ;INCREMENTAMOS EL SI
    CMP SI, LIM ;EL MAXIMO DE CARACTERES PERMITIDOS SERA DE 9decimal.
    JE ENOF    ; REPETIMOS HASTA QU TODOS LOS ELEMENTOS SEAN SUMADOS      
                                                                         
ENOF3:                                                                                
RET   
OP ENDP

IMPRIMERES PROC NEAR
;LEA DX, MSJCADENA   ;IMPRIME "CADENA INGRESADA: "                                           
;MOV AH,09H                                                                                  
;INT 21H                                                                                     
                                                                                            
MOV DX,OFFSET VECR;IMPRIME EL CONTENIDO DEL VECTOR CON LA MISMA INSTRUCCION DE UNA CADENA.  
MOV AH,09H        ;Y LO IMPRIME...                                             
INT 21H                                                                                     
                                                                                                                 
;MOV AH,4CH  ; FIN DEL PROGRAMA                                                              
;INT 21H                                                                                     
RET             
IMPRIMERES ENDP

TERMINAR: 
SUMAVECTORES ENDM

.model small
.stack 64
.data  

VEC1X DB 0AH, 00, 09H DUP ('$') ;09H ES LA LONGITUD MAXIMA DE ELEMENTOS EN EL VECTOR
  VEC2X DB 0AH, 00, 09H DUP ('$')
  VECRX DB 0AH, 00, 09H DUP ('$')
 
  LIMX db 0

      
.code                                                         
      SUMAVECTORES LIMX
END