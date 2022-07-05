typedef char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

#if defined(_WIN32)
	#ifdef _M_X86
		#define PLATFORM_X86
	#endif
#endif

#if defined(__MINGW32__)
	#ifdef __i386__
		#define PLATFORM_X86
	#endif
#endif

#if defined(PLATFORM_X86)
typedef int isize;
typedef unsigned int usize;
#else
typedef long long isize;
typedef unsigned long long usize;
#endif

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef float f32;
typedef long float f64;
