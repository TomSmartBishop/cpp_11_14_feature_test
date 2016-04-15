#ifndef __AUTO_TEST_H_
#define __AUTO_TEST_H_

namespace auto_decltype_rangefor
{

	auto test() -> void
	{
		//no more need to specify the type in most cases
		auto sum = 2 + 3 + 4 + 5;
		ASSERT(sum == 14);

		auto vec = std::vector<int32_t>{1,2,3,4,5,6,7,8};

		auto counter = 1;
		for (auto element : vec) //be aware that this will copy to 'element'
		{
			ASSERT(element == counter);
			counter++;
		}



		//let's create a vector of vectors... (and take a look at the new feature 'decltype')
		auto vec_of_vec = std::vector<decltype(vec)>{}; //same as std::vector<std::vector<int32_t>>
		vec_of_vec.push_back(vec);

		//and one more
		decltype(vec) vec2{ 9,7,6,5,4,3,2,1 }; //so we use the compiler to tell us the type with decltype
		//decltype makes it for sure shorter and the type is also clear,
		//I'm not sure if it is good to use it here or not...
		//there are other places (trailing return types) where this new keyword is needed.



		//and with range based for loops we can even make this simpler
		for (auto& vec_of_int : vec_of_vec) //now grab the reference (const or not const)
		{
			ASSERT(vec_of_int.size() == 8);
		}
		//if your contain implements a standard conform iterator you can also use the range for loops for your types

		//also this works, but is more error prone and much more typing... (so let's avoid it in the future)
		for (auto it = std::cbegin(vec_of_vec); it != std::cend(vec_of_vec); it++) //you can also use std::begin/std::end 
		{
			ASSERT(it->size() == 8); //both inner vectors have 8 elements...
		}



		//be careful, auto doesn't always get it right...
		auto bool_vec = std::vector<bool>{true, true, false, false, true};

		//what will be the type of these two variables...?
		auto bool_or_not_bool = bool_vec[3];
		bool will_be_a_bool = bool_vec[3];

		//let's check it out
		auto maybe_bool_typename = typeid(decltype(bool_or_not_bool)).name();
		auto bool_typename = typeid(decltype(will_be_a_bool)).name();

		//if they are the same the next assert should fail, right?
		ASSERT(std::strcmp(maybe_bool_typename, bool_typename) != 0);



		//remember std::vector whit it's custom behavior..?
		auto whats_this = { 1,2,3,4,5 };

		//so hewre we can see the type - std::vector has an own ctor for it
		auto list_type = typeid(decltype(whats_this)).name();
		//just use the debugger to figure out the type
	}

};

#endif // __AUTO_TEST_H_

