bits 64

section .text
	global	ft_strdup
	extern	ft_strlen
	extern	ft_strcpy
	extern	malloc

ft_strdup:
	push	rdi			; push rdi to stack

	call	ft_strlen	; len = ft_strlen(str)
	inc		rax

	mov		rdi, rax	; tmp = malloc(len)
	call	malloc wrt ..plt

	pop		rdi			; ft_strcpy(..., len)
	mov		rsi, rdi

	mov		rdi, rax	; ft_strcpy(tmp, ...)

	call	ft_strcpy

	ret
