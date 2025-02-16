bits 64

%define EBADF	9

section .text
	global	ft_write
	extern __errno_location

ft_write:
	; ssize_t write(int fd, const void buf[.count], size_t count);
	mov		rax, 1						; write(...)
	;		rdi							  fd
	;		rsi							  &buf
	;		rdx							  count
	syscall
	
	; error check
	cmp		rax, 0						; if (write(...) < 0) goto error;
	jl		_error
	ret

_error:
	neg		rax							; get return value as unsigned int
	mov		rdi, rax					; copy fd into rax
	
	; errno bullshit
	mov		rdi, EBADF					; sets arg0 to NULL
	call	__errno_location wrt ..plt	; call __errno_location() to get errno address
	mov		[rax], rdi					; set errno value
	
	mov		rax, -1						; return -1; 
	ret

