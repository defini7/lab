#pragma once

#pragma region LICENSE
/***
*	BSD 3-Clause License

	Copyright (c) 2021, Alex
	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions are met:

	1. Redistributions of source code must retain the above copyright notice, this
	   list of conditions and the following disclaimer.

	2. Redistributions in binary form must reproduce the above copyright notice,
	   this list of conditions and the following disclaimer in the documentation
	   and/or other materials provided with the distribution.

	3. Neither the name of the copyright holder nor the names of its
	   contributors may be used to endorse or promote products derived from
	   this software without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
	AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
	IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
	DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
	FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
	DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
	SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
	CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
	OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
***/
#pragma endregion

#pragma region EXAMPLE
/***
	#include "defGet.h"
	
	int main() 
	{
		int cows_count = get_int("Enter count of cows: ");
		std::cout << cows_count << std::endl;
		return 0;
	}
***/
#pragma endregion

#include <string>
#include <iostream>

namespace def
{
	int get_int(const char* text = "")
	{
		int input;
		printf(text);
		std::cin >> input;
		return input;
	}

	float get_float(const char* text = "")
	{
		float input;
		printf(text);
		std::cin >> input;
		return input;
	}

	double get_double(const char* text = "")
	{
		double input;
		printf(text);
		std::cin >> input;
		return input;
	}

	char get_char(const char* text = "")
	{
		char input;
		printf(text);
		std::cin >> input;
		return input;
	}

	char* get_cstring(const char* text = "")
	{
		char input[256];
		printf(text);
		std::cin >> input;
		return input;
	}

	std::string get_string(const char* text = "")
	{
		std::string input;
		printf(text);
		std::cin >> input;
		return input;
	}

	long get_long(const char* text = "")
	{
		long input;
		printf(text);
		std::cin >> input;
		return input;
	}

	long long get_longlong(const char* text = "")
	{
		long long input;
		printf(text);
		std::cin >> input;
		return input;
	}

	short get_short(const char* text = "")
	{
		short input;
		printf(text);
		std::cin >> input;
		return input;
	}

	unsigned long get_ulong(const char* text = "")
	{
		unsigned long input;
		printf(text);
		std::cin >> input;
		return input;
	}

	unsigned long long get_ulonglong(const char* text = "")
	{
		unsigned long long input;
		printf(text);
		std::cin >> input;
		return input;
	}

	unsigned short get_ushort(const char* text = "")
	{
		unsigned short input;
		printf(text);
		std::cin >> input;
		return input;
	}

	unsigned int get_uint(const char* text = "")
	{
		unsigned int input;
		printf(text);
		std::cin >> input;
		return input;
	}

	unsigned char get_uchar(const char* text = "")
	{
		unsigned char input;
		printf(text);
		std::cin >> input;
		return input;
	}

	unsigned char* get_ucstring(const char* text = "")
	{
		unsigned char input[256];
		printf(text);
		std::cin >> input;
		return input;
	}

	// current version is 0.1
	const char* version()
	{
		return "0.1";
	}
}
