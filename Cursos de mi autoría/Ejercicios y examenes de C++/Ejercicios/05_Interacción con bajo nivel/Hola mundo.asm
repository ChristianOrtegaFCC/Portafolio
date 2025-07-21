.386
.model flat, stdcall
.stack 4096

includelib kernel32.lib
includelib user32.lib
include kernel32.inc
include user32.inc

.data
mensaje db "Hola mundo!", 0

.code
main proc
    invoke MessageBoxA, 0, addr mensaje, addr mensaje, MB_OK
    invoke ExitProcess, 0
main endp
end