NULL EQU 0
MB_DEFBUTTON EQU 100h
IDNO EQU 7
MB_YESNO EQU 4

extern _MessageBoxA@16 ; MessageBoxW for UNICODE
extern _ExitProcess@4

global Start

section .data
	
	MessageBoxMessage db "Hello World!", 0
	MessageBoxTitle db "Hello Title!", 0

section .text
	
	Start:

		push MB_YESNO | MB_DEFBUTTON
		push MessageBoxTitle
		push MessageBoxMessage
		push NULL
		call _MessageBoxA@16

		cmp EAX, IDNO ; comparison two values
		je Start ; go to je if first value equals second value

		push NULL
		call _ExitProcess@4
