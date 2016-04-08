#ifndef __CONSTEXPR_TEST_H_
#define __CONSTEXPR_TEST_H_

namespace constexpr_test
{
	//since C++11 we can use constexpr for methods and functions
	//(and with C++14 they can be more than one-liner)
	template<typename T>
	constexpr auto pow(const T base, std::size_t exp) -> T
	{
		return exp==0 ? 1 : base * pow(base, exp-1);
	}

	//also possible for member, for msvc however the constant
	//needs to be wrapped in a class or struct (not needed for clang and gcc)
	template<typename T>
	struct constants
	{
		static constexpr T pi{ static_cast<T>(3.1415926535897932384626433832795) };
	};

	constexpr auto test() noexcept -> void
	{
		static_assert(pow(3,3) == 27, "3 ^ 3 should be 27");
		
		static_assert(constants<float>::pi == 3.14159265358979f, "The two PIs should be the same");
	}
		
};

#endif // __CONSTEXPR_TEST_H_