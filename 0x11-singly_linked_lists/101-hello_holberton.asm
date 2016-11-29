        SECTION .data           ; data section
msg:	            db "Hello, Holberton",10, 0 ; the string to print, 10=cr
len:	            equ $-msg			; "$" means "here"
;;;   len is a value, not an address

	        SECTION .text	; code section

	        global main     ; make label available to linker
main:
	        mov     edx,len
	        mov     ecx,msg
	        mov     ebx,1
	        mov     eax,4	; write sysout command to int 80 hex
	        int     0x80	; interrupt 80 hex, call kernel

	        mov     ebx,0	; exit code
	        mov     eax,1	; exit command to kernel
	        int     0x80	; interrupt 80 hex, call kernel
