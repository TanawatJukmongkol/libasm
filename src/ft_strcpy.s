bits 64

section .text
	global	ft_strcpy

ft_strcpy:
	mov		rdx, 0			; i = 0;

	cmp		rdi, 0			; if (dst[i] == NULL) return NULL;
	je		_error
	cmp		rsi, 0			; if (src[i] == NULL) return NULL;
	je		_error

	jmp		_loop
	ret

_loop:									; while (true)
	cmp		BYTE [rdx + rsi], 0			; if (src[i] == 0) return dst;
	je		_exit

	mov		al, BYTE [rdx + rsi]		; tmp = (unsigned char)src[i];
	mov		BYTE [rdx + rdi], al		; dst[i] = tmp;

	inc		rdx							; i++

	jmp		_loop


_exit:
	mov		BYTE [rdx + rdi], 0			; dst[i] = '\0'
	mov		rax, rdi
	ret

_error:
	mov		rax, 0
	ret
