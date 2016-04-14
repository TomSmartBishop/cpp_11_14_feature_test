#ifndef __NOEXCEPT_TEST_H_
#define __NOEXCEPT_TEST_H_

namespace noexcept_test
{
	//there won't be an exception thrown in here
	auto add(int32_t a, int32_t b) noexcept -> int32_t
	{
		return a + b;
	}

	//if we do throw the compiler will warn us (but still compiles + crashes)
	auto div_noexcept(float32_t a, float32_t b) noexcept -> float32_t
	{
		if (b == 0.0f)
			throw std::runtime_error("division by zero!");
		return a / b;
	}

	//can be expressed conditionally... (using templates we can do even smarter things here)
	auto div_except(float32_t a, float32_t b) noexcept(false) -> float32_t
	{
		//if we throw here the compiler will warn us (but still compiles)
		if (b == 0.0f)
			throw std::runtime_error("division by zero!");
		return a / b;
	}

	//Why use noexcept? Answer: The compiler can apply better optimizations and
	//since the compiler warns us in case of an abuse (see div_noexcept) it seems hard
	//to use it the wrong way... So let's use it from now on wherever we can!
	auto test() noexcept -> void
	{
		auto sum = add(32, 64);

		//let's not do this... it will blow up our program
		//auto div_by_zero = div_noexcept(32, 0);

		auto exception_thrown = false; //bool... another type that is not really specified :(
		try
		{
			auto div_by_zero = div_except(32, 0);
		}
		catch (std::runtime_error& e)
		{
			exception_thrown = e.what() != nullptr;
		}
		ASSERT(exception_thrown);
	}

};

#endif //__NOEXCEPT_TEST_H_
