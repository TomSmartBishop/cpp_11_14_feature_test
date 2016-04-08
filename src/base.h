#ifndef __BASE_H_
#define __BASE_H_

#define ASSERT _ASSERTE

#ifdef NDEBUG
#	define VERIFY(expr) (expr)
#else
#	define VERIFY(expr) ASSERT(expr)
#endif

#endif // __BASE_H_