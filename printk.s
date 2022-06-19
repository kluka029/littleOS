global printk
extern serial_write
extern itos

%define END_OF_STRING       0x0
%define FORMAT_SPECIFIER    0x25
%define CHAR_TYPE           0x63
%define INT_TYPE            0x64
%define FLOAT_TYPE          0x66

; TODO: Why do we have to do mov esi, [ebp+8], then mov esi, [esi] to get the string data?

; WARNING: It's assumed the number of %<format> in the string to be printed 
; matches the number of arguments passed to the function. 
printk:      
    push ebp
    push esi
    push edi
    mov ebp, esp
    mov esi, [ebp+16]           ; stack address of str?
    mov edi, esp                
    add edi, 20                 ; address of first arg
    
loop:
    cmp BYTE[esi], END_OF_STRING
    je exit
    
    cmp BYTE[esi], FORMAT_SPECIFIER
    jne not_arg
    add esi, 1
    
    cmp BYTE[esi], INT_TYPE
    jne exit
    
    push dword[esp-1000]         ; TODO: there has to be a better way to do this...
    push dword[edi]
    call itos
    add edi, 4                   ; add size of int to get next arg
    
    push eax
    push dword[esp-1000]
    push 0x3F8
    call serial_write
    add esi, 1
    jmp loop
    
not_arg:
    push 0x1
    push esi
    push 0x3F8
    call serial_write
    add esi, 1
    jmp loop
    
exit:
    mov esp, ebp
    pop edi
    pop esi
    pop ebp
    ret
