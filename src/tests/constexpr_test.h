#ifndef __CONSTEXPR_TEST_H_
#define __CONSTEXPR_TEST_H_

namespace constexpr_test
{
	//since C++11 we can use constexpr for methods and functions
	//(and with C++14 they can be more than one-liner)
	//so the compiler will evaluate during compile time if possible (not guaranteed)
	template<typename T>
	constexpr auto pow(const T base, std::size_t exp) noexcept -> T
	{
		return exp==0 ? 1 : base * pow(base, exp-1);
	}

	//also possible for member, for msvc however the constant
	//needs to be wrapped in a class or struct (not needed for clang and gcc)
	template<typename T>
#if defined(_MSC_VER)
	struct constants
	{
#endif
		static constexpr T pi{ static_cast<T>(3.1415926535897932384626433832795) };
#if defined(_MSC_VER)
	};
#endif

	//let's try a template class with a constexpr ctor
	template<typename T>
	struct template_class 
	{
		T m_member;
		constexpr template_class() : m_member {} {}
		constexpr auto get_member() const noexcept -> T //do we really need const here?
		{
			return m_member;
		}
	};

	//all good as long as we mark it as constexpr...
	template<>
	constexpr auto template_class<int>::get_member() const noexcept -> int
	{
		return m_member;
	};

	//when not declaring constexpr it depends on the compiler :'(
	//this seems to be a grey area of the C++ standard, see discussion here:
	//http://stackoverflow.com/questions/33993100/remove-constexpr-from-c14-template-specialization
	//maybe this improves with C++17 and constexpr_if
#if defined(__GNUC__)
	struct non_constexpr_type 
	{
	};

	template<>
	auto template_class<non_constexpr_type>::get_member() const noexcept -> non_constexpr_type
	{
		return m_member;
	};
#endif

	constexpr auto test() noexcept -> void
	{
		static_assert(pow(3,3) == 27, "3 ^ 3 should be 27");
		
#if defined(_MSC_VER)
		static_assert(constants<float>::pi == 3.14159265358979f, "The two PIs should be the same");
#else

		static_assert(pi<float> == 3.14159265358979f, "The two PIs should be the same");
#endif
		//constexpr template_class<int> int_test{};
		//static_assert(int_test.get_member()==0, "The integer should be 0");
	}

		
};

#endif // __CONSTEXPR_TEST_H_
