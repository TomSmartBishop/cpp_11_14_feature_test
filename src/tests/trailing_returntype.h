#ifndef __TRAILING_RETURNTYPE_TEST_H_
#define __TRAILING_RETURNTYPE_TEST_H_

namespace trailing_returntype
{
	//traditionally I would define a function like this:
	int32_t calculate_something()
	{
		return 0;
	}

	//with C++11 we can now also use trailing return types
	auto calculate_something_new() -> int32_t
	{
		return 0;
	}

	//so why would you do that? (seems like more typing...)

	//let setup some demo class (also showing difference between C++11 and C++14)
	template<typename T>
	struct vec2 {
		T val[2];

		vec2(T x, T y) : val{ x, y} {}

		auto dot_cpp11_style(const vec2<T>& other) const -> T
		{
			return val[0]*other.val[0] + val[1]*other.val[1];
		}
		
		//in C++14 we even don't need to specify the return type at all,
		//unfortunately it could become tricky to use this function because
		//the signature doesn't give any clue about the return type (so
		//you would need to read the whole method - not really nice) and
		//that's we I currently prefer to write the return type
		auto dot_cpp14_style(const vec2<T>& other) const
		{
			return val[0]*other.val[0] + val[1]*other.val[1];
		}

		//this would allow us to write to and index element: vec2_inst[0] = 3.5f;
		auto operator[](const size_t index) -> T&
		{
			return val[index];
		}

		//and this to read (const): float32_t val = vec2_inst[1];
		auto operator[](const size_t index) const -> const T&
		{
			return val[index];
		}

		//wonder if this works on clang and/or gcc
		//using dot = auto dot_cpp11_style(const vec2<T>& other) -> T;
	};


	//So now we come to the point: Why is a trailing return type needed?
	//Answer: The (C++11) compiler doesn't know about the return type at
	//the beginning of the method (but we can find out after defining a and b.
	//As I already mentioned: C++14 style is unfortunately not user-friendly
	template<typename T>
	auto calculate_something_unknown_cpp11(const T& a, const T & b) -> decltype(a.dot_cpp11_style(b))
	{
		return a.dot_cpp11_style(b);
	}

	template<typename T>
	auto calculate_something_unknown_cpp14(const T& a, const T& b)
	{
		//In C++14 we don't need decltype here either in that place,
		//but it is still required in some cases and the concept is
		//also expanded to work with lambdas and other stuff.
		return a.dot_cpp14_style(b);
	}

	template<typename T>
	decltype(auto) memberAccess_dectype(T& a)
	{
		//We can also do this! The difference is that it also adds information
		//not present through auto type deduction. With auto alone we would lose the
		//information if the return type is actually a reference or not. Let's compare that
		//with the following almost identical method
		return a[0];
	}

	template<typename T>
	auto memberAccess_nodectype(T& a)
	{
		//Now we will never return a reference, but always a copy of a[0].
		//Nobody of course would use a function like this but, there are a lot of cases
		//were you will want to work on a reference instead of a copy of an object.
		//I recommend reading the whole story about 'auto' and 'dectype' in the book
		//"Effective Modern C++" in Item 3 (by Scott Meyers)
		return a[0];
	}

	//calling these methods stays the same of course...
	auto test() -> void
	{
		auto something = calculate_something();
		ASSERT(something == 0);

		something += calculate_something_new();
		ASSERT(something == 0);

		auto unknown = calculate_something_unknown_cpp11(
				vec2<float32_t>{ 3.0f, 4.0f },
				vec2<float32_t>{ -4.0f, 6.0f }
			);
		ASSERT(unknown == 12.0f);

		auto unknown14 = calculate_something_unknown_cpp14(
				vec2<float32_t>{ 3.0f, 4.0f },
				vec2<float32_t>{ -4.0f, 6.0f }
			);
		ASSERT(unknown14 == 12.0f);

		auto vec = vec2<float32_t>{ 3.0f, 4.0f };
		auto member_nodecltype = memberAccess_nodectype(vec); // returns float32_t
		ASSERT(member_nodecltype == 3.0f);
		//the following lines does not compile because with auto alone we never get the reference
		//memberAccess_nodectype(vec) = 2.0f;
		auto member_decltype = memberAccess_dectype(vec); //returns float32_t &
		ASSERT(member_decltype == 3.0f);
		//therefore we can write to it...
		memberAccess_dectype(vec) = 5.0f;
		ASSERT(vec[0] == 5.0f);
	}

};

#endif //__NOEXCEPT_TEST_H_

