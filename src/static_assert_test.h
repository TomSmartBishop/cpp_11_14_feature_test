#ifndef __STATIC_ASSERT_TEST_H_
#define __STATIC_ASSERT_TEST_H_

namespace static_assert_test
{

constexpr auto test() noexcept -> void
	{
		static_assert(sizeof(int) == 4, "We didn't expect int of other size than 4...");

		// as we can see this is platform dependent and good thing to check in the code at compile time
#if defined(_MSC_VER)
		static_assert(sizeof(long) == 4, "Disappointing that long just has 4 bytes...");
#else
		static_assert(sizeof(long) == 8, "Disappointing that long just has 4 bytes...");
#endif

		static_assert(sizeof(long long) == 8, "Really?");
	}

};

#endif //__STATIC_ASSERT_TEST_H_