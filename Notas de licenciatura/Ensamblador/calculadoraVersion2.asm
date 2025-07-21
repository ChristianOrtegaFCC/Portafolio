; pedimos numero 1 y numero 2...
; pide simbolo...
; hace las comparaciones marcianas correctamente
; esto funciona bien

.model small
.stack 64
.data
    ; numeros
    num1 db 0
    num2 db 0
    
    sumar db 0
    restar db 0
    multiplicacionr db 0
    divisionr db 0
    modulor db 0
    
    ;simbolos
    sign db 0   ;variable
    sim1 db 1h ; +
    sim2 db 2h ; -
    sim3 db 3h ; *
    sim4 db 4h ; /
    sim5 db 5h ; %
    
    ;mensajes sencillos
    msg1 db 10,13, 'Numeros iguales ','$'
    msg2 db 10,13, 'Numero 1 mayor','$'
    msg3 db 10,13, 'Numero 2 mayor ','$'
    msg0 db 10,13,13, 'Signos: +=1 , -=2 , *=3 , /=4 , %=5 ','$'
    
        ;mensajes para mostrar
        mnsjmstr1 db 10,13, 'la suma es: ','$'
        mnsjmstr2 db 10,13, 'la resta es: ','$'
        mnsjmstr3 db 10,13, 'la multiplicacion es: ','$'
        mnsjmstr4 db 10,13, 'la division es: ','$'
        mnsjmstr5 db 10,13, 'el residuo es: ','$'
    
    ;mensajes para pedir
    msjpd1 db 10,13, 'dame el numero 1: ','$'
    msjpd2 db 10,13, 'dame el numero 2: ','$'
    msjpds db 10,13, 'dame el signo    : ','$'
    
    
.code
    main:
    mov ax,@data
    mov ds,ax
    
    ; indicamos notacion de signos
    mov ah, 09
    lea dx, msg0
    int 21h 
    
    ;pedimos numero 1
    
    mov ah, 09
    lea dx, msjpd1
    int 21h
    mov ah, 01
    int 21h
    sub al, 30h
    mov num1,al
    
    ;pedimos signo
    mov ah, 09
    lea dx, msjpds
    int 21h
    mov ah, 01
    int 21h
    sub al, 30h
    mov sign,al
    
    ;pedimos numero 2
    
    mov ah, 09
    lea dx, msjpd2
    int 21h
    mov ah, 01
    int 21h
    sub al, 30h
    mov num2,al
    
    ; xd
    ;je = iguales
    ; jz  = 'iguales'
    ; jc  = r mayor 
    ; jnz = r menor
    
    mov al,sim4
    cmp al,sign
    
    jz divide
    jc residuo
    jnz sig
    
    
.exit

sig:

    mov al,sim2
    cmp al,sign
    jz resta
    jc multiplica
    jnz suma

.exit

suma:

    add bh,num1
    add bh,num2
    mov sumar,bh
    
    mov ah,09
    lea dx,mnsjmstr1
    int 21h
    mov dl,sumar
    add dl,30h 
    mov ah,02
    int 21h  


.exit

resta:
    
    add bh,num1
    sub bh,num2
    mov restar, bh
    
    mov ah,09
    lea dx,mnsjmstr2
    int 21h 
    mov dl,restar
    add dl,30h 
    mov ah,02
    int 21h
.exit 

multiplica:
    mov al,num1
    mul num2
    mov multiplicacionr,al
    
    mov ah,09
    lea dx,mnsjmstr3
    int 21h
    mov dl,multiplicacionr
    add dl,30h 
    mov ah,02
    int 21h
.exit

divide:
; ayudame diosito me duele el corazon
; quizas deberia dormir 
    mov al,num1
    div num2
    mov divisionr,al
    
    mov ah,09
    lea dx,mnsjmstr4
    int 21h
    mov dl,divisionr
    add dl,30h 
    mov ah,02
    int 21h
.exit

residuo:
    mov al, num1
    div num2
    mov modulor,ah
    
    mov ah,09
    lea dx,mnsjmstr5
    int 21h
    mov dl,modulor
    add dl,30h 
    mov ah,02
    int 21h
.exit

END