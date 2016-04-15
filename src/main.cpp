//get generated constans from cmake
#include "generated/config.h"

#include <cstddef> //for std::size_t
#include <cstdint> //for std::int32_t and co
#include <limits>  //for std::numeric_limits
#include <algorithm> //for std::move
#include <stdexcept> //for some noexcept code
#include <vector> //for std::vector
#include <typeinfo> //for typeid

//basic stuff to get started
#include "base.h"
#include "float32.h"

//since C++11 we have better control over integer types..!
using std::size_t;
using std::int32_t;

//please look inside flaot32.h
using fp::float32_t;

//all out feature tests
#include "tests/static_asserts.h"
#include "tests/brace_initialization.h"
#include "tests/auto_decltype_rangefor.h"
#include "tests/trailing_returntype.h"
#include "tests/noexcept_test.h"
#include "tests/constexpr_test.h"

auto main() -> int32_t
{
	static_asserts::test();

	brace_initialization::test();

	auto_decltype_rangefor::test();

	trailing_returntype::test();

	noexcept_test::test();
	
	constexpr_test::test();

	return 0;
}