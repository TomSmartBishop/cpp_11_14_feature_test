#include "generated/config.h"

#include <cstddef>

#include "base.h"

#include "static_assert_test.h"
#include "constexpr_test.h"

auto main() -> int
{
	static_assert_test::test();

	brace_initialization_test::test();

	constexpr_test::test();

	return 0;
}