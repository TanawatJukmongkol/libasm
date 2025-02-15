bits 64

section .text
	global	ft_strlen

ft_strlen:
	; size_t strlen(const char *s);
	; cmp		rdi, 0					; if(s == NULL) goto error;
	; je		_error
	; init counter
	mov		rax, -1					; i = 0
	jmp		_loop
	ret

_loop:								; while (true)
	inc		rax						; i++
	cmp		BYTE [rax + rdi], 0		; if (s[i] == '\0') break;
	jne		_loop
	ret

; _error:
; 	mov		rax, -1					; return -1; 
; 	ret
