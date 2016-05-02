#ifndef __BRACE_INITIALIZATION_H_
#define __BRACE_INITIALIZATION_H_

namespace brace_initialization
{
	auto test() -> void
	{
		//new way of initialization since the 'old' way is not really uniform
		int32_t an_int{ 3 };
		float32_t a_float{ 3.14f };

		//so the brace initialization will match the types to find the right constructor
		std::vector<int32_t> vec{ 1,2,3,4,5 };
		ASSERT(vec.size() == 5);

		//but it doesn't prevent you from pitfalls..:
		std::vector<int32_t> vec2( 100, 2 ); //this constructor will create 100 elements with the value 2
		std::vector<int32_t> vec3{ 100, 2 }; //so actually this should do the same

		ASSERT(vec2.size() == 100); 
		ASSERT(vec3.size() == 2);
		//you wonder why..? A: std::vector has an own constructor for a std::initializer_list
		//and therefore bypasses that mechanism... you should never do this in your API!
	}

};

#endif // __BRACE_INITIALIZATION_H_

