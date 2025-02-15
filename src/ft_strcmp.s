bits 64

section .text
	global	ft_strcmp

ft_strcmp:
	; I follow the BSD implimentation, where
	; the diff is the subtracted number, and
	; not linux -1, 0, and 1
	; int strcmp(const char *s1, const char *s2);
	mov		rax, 0
	mov		rdx, 0
	mov		rcx, -1						; i = -1
	jmp		_loop
	ret

_loop:									; while (true)
	inc		rcx							; i++

	mov		al, BYTE [rcx + rdi]		; tmp1  = (unsigned char)s1[i]
	mov		dl, BYTE [rcx + rsi]		; tmp2 -= (unsigned char)s2[i]

	cmp		BYTE [rcx + rdi], 0			; if (s1[i] == 0) return (tmp2 - tmp1);
	je		_exit
	cmp		BYTE [rcx + rsi], 0			; if (s2[i] == 0) return (tmp2 - tmp1);
	je		_exit

	cmp		al, dl						; if ( tmp1 != tmp2 ) return (tmp2 - tmp1);
	jne		_exit

	jmp		_loop

; _error:
; 	mov		rax, -1					; return -1; 
; 	ret

_exit:
	sub		rax, rdx
	ret
