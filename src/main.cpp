//get generated constans from cmake
#include "generated/config.h"

#include <cstddef> //for std::size_t
#include <cstdint> //for std::int32_t and co
#include <limits>  //for std::numeric_limits
#include <algorithm> //for std::move
#include <stdexcept> //for some noexcept code

//basic stuff to get started
#include "base.h"
#include "float32.h"

//since C++11 we have better control over integer types..!
using std::size_t;
using std::int32_t;

//please look inside flaot32.h
using fp::float32_t;

//all out feature tests
#include "trailing_returntype_and_decltype.h"
#include "noexcept_test.h"
#include "static_assert_test.h"
#include "brace_initialization_test.h"
#include "constexpr_test.h"

auto main() -> int32_t
{
	//auto

	trailing_returntype_and_decltype::test();

	noexcept_test::test();

	static_assert_test::test();

	brace_initialization_test::test();

	constexpr_test::test();

	return 0;
}