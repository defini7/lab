;; only for windows
null EQU 0
std_output_handle EQU -11

extern _GetStdHandle@4
extern _WriteFile@20
extern _ExitProcess@4

global Start

section .data

	Message db "Hello, World!", 0Dh, 0Ah
	MessageLength EQU $-Message

section .bss

	StandardHandle resd 1
	Written resd 1

section .text:
	
	Start:
		push std_output_handle
		call _GetStdHandle@4
		mov dword [StandardHandle], EAX

		push null
		push Written
		push MessageLength
		push Message
		push dword [StandardHandle]
		call _WriteFile@20

		push null
		call _ExitProcess@4
