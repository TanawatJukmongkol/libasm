bits 64

%define	EBADF		9
%define	EINVAL		22

section .text
	global	ft_write
	extern	__errno_location

ft_write:
	; ssize_t write(int fd, const void buf[.count], size_t count);

	mov		rax, 1						; write(...)
	;		rdi							  fd
	;		rsi							  &buf
	;		rdx							  count
	syscall

	cmp		rsi, 0						; if (buf == NULL) goto _null_error;
	je		_null_error

	cmp		rax, 0
	jl		_error

	ret

_error:
	neg		rax							; get return value as unsigned int
	mov		rdi, rax					; copy fd into rax

	; mov		rdi, EBADF
	call	__errno_location wrt ..plt	; call __errno_location() to get errno address
	mov		[rax], rdi					; set errno value

	mov		rax, -1						; return -1; 
	ret

_null_error:
	neg		rax							; get return value as unsigned int
	mov		rdi, rax					; copy fd into rax

	mov		rdi, EINVAL
	call	__errno_location wrt ..plt	; call __errno_location() to get errno address
	mov		[rax], rdi					; set errno value

	mov		rax, -1						; return -1;
	ret
