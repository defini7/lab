#include <iostream>

int main()
{
	int a = 45;
	int b = 5;

	int result = 0;
	int remainder = 0;

	// sub - minus
	// add - plus
	// mul - multiply
	// div - division

	// https://www.aldeid.com/wiki/X86-assembly/Instructions/div#Example
	__asm
	{
		;; "a / b" and store result in "eax" and the remainder in "edx"

		mov edx, 0

		mov eax, a
		mov ecx, b

		div ecx

		mov result, eax
		mov remainder, edx

		;; memory cleaning
		mov eax, 0
		mov edx, 0
	}

	std::cout << "45 / 5 = " << std::endl;
	std::cout << "result: " << result << std::endl;
	std::cout << "remainder: " << remainder << std::endl;
	std::cout << std::endl;

	// https://www.aldeid.com/wiki/X86-assembly/Instructions/mul#Example
	__asm
	{
		;; "a * b" and store result in "edx"
		mov result, 0
		mov remainder, 0
		mov eax, a
		mov ebx, b

		mul ebx

		mov result, eax

		;; memory cleaning
		mov eax, 0
		mov ebx, 0
	}

	std::cout << "45 * 5 = " << std::endl;
	std::cout << "result: " << result << std::endl;
	std::cout << std::endl;

	// https://www.aldeid.com/wiki/X86-assembly/Instructions/add#Example
	__asm
	{
		;; "a + b" and store result in "eax"
		mov result, 0
		mov eax, a
		mov ebx, b

		add eax, ebx

		mov result, eax

		;; memory cleaning
		mov eax, 0
		mov ebx, 0
	}

	std::cout << "45 + 5 = " << std::endl;
	std::cout << "result: " << result << std::endl;
	std::cout << std::endl;

	// https://www.aldeid.com/wiki/X86-assembly/Instructions/sub#Example
	__asm
	{
		;; "a - b" and store result in "eax"
		mov result, 0
		mov eax, a
		mov ebx, b

		sub eax, ebx

		mov result, eax

		;; memory cleaning
		mov eax, 0
		mov ebx, 0
	}

	std::cout << "45 - 5 = " << std::endl;
	std::cout << "result: " << result << std::endl;
	std::cout << std::endl;

	// if statement
	__asm
	{
		mov result, 0

		mov eax, a
		mov ebx, b

		cmp eax, ebx
		jl LESS ;; a < b
		jg GREATER ;; a > b
		je EQUALS ;; a = b
		jne NOT_EQUALS ;; a != b

	LESS:
		mov result, 0
	GREATER:
		mov result, 1
	EQUALS:
		mov result, 2
	NOT_EQUALS:
		mov result, 3
	}

	switch (result)
	{
	case 0:
		std::cout << a << " < " << b;
		break;

	case 1:
		std::cout << a << " > " << b;
		break;

	case 2:
		std::cout << a << " = " << b;
		break;

	case 3:
		std::cout << a << " != " << b;
		break;

	default:
		break;
	}

	std::cout << std::endl;

	// While loop
	__asm
	{
		mov result, 0

		mov eax, a
		mov ebx, b
		mov ecx, result

		cmp eax, ebx
		jg WHILE_LOOP ;; a > b -> "while" loop

		WHILE_LOOP:
			inc ecx
			dec eax
			cmp eax, ebx
			jg WHILE_LOOP ;; a > b -> again "while" loop

		mov result, ecx
	}

	std::cout << "Count of decrement iterations before A = B: " << result << std::endl;
}
