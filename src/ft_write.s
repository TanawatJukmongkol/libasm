bits 64

%define EBADF 9 ; invalid fd

extern __errno_location

section .text
	global	ft_write

ft_write:
	xor	rax, rax	; clear register
	mov	rax, 1		; write
	syscall
	
	; error check
	cmp	rax, 0		; if (write(...) < 0) goto error;
	jl	error
	
	jmp exit		; exit

error:
	neg		rax					; get return value as unsigned int
	mov		rdi, rax			; copy fd into rax
	
	; errno bullshit
	mov		rdi, 0				; sets arg0 to NULL
	call	__errno_location wrt ..plt	; call __errno_location() to get errno address
	mov		[rax], rdi			; set errno value
	
	mov		rax, -1				; return -1; 
	jmp		exit

exit:
	ret
