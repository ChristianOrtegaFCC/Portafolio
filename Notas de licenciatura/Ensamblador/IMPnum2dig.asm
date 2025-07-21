.MODEL SMALL ,C
.STACK
.DATA
    N DB 45
    S DB 2 DUP (''),'$'
    B DB 10
.CODE
    .STARTUP
    
    MOV AX,0
    MOV AL,N
    DIV B
    
    MOV S[0], AL
    MOV S[1], AH
    
    ADD S[0],48
    ADD S[1],48
    
    LEA DX,S
    MOV AH,9
    INT 21H
    
    .EXIT
END