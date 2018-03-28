#ifndef _DEBUGMACRO_H_
#define _DEBUGMACRO_H_

// fund at https://stackoverflow.com/questions/14251038/debug-macros-in-c
#include <iostream>
#include <fstream>

template<typename... ArgTypes>
inline void print(ArgTypes... args)
{
#ifdef DEBUG_FILE
	#ifdef LOG_FILE
		std::ofstream log_file( LOG_FILE, std::ios::out | std::ios::app );
	#else
		std::ofstream log_file( "log_file.log", std::ios::out | std::ios::app );
	#endif
#endif

  // trick to expand variadic argument pack without recursion
  using expand_variadic_pack = int[];
  // first zero is to prevent empty braced-init-list
  // void() is to prevent overloaded operator, messing things up
  // trick is to use the side effect of list-initializer to call a function
  // on every argument.
  // (void) is to suppress "statement has no effect" warnings
#ifndef DEBUG_FILE
  (void)expand_variadic_pack{0, ((std::cout << args), void(), 0)... };
#else
	if( log_file.is_open() == true ) {
		(void)expand_variadic_pack{0, ( ( log_file << args ), void(), 0)... };
		log_file.flush();
		log_file.close();
	} else {
		(void)expand_variadic_pack{0, ( ( std::cout << args ), void(), 0)... };
	}
#endif
}


#ifndef DEBUG
#define DEBUG_PRT(...)
#else
#define DEBUG_PRT(...) print(__DATE__ , " at ", __TIME__, " : ", __FILE__, " : ",  __func__ , " : ", __VA_ARGS__,"\n")
#endif

#endif
