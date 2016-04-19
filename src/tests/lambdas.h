#ifndef __LAMBDA_H_
#define __LAMBDA_H_

namespace lambda
{

	auto test() noexcept -> void
	{
		//lambdas let us define unnamed functions
		auto smaller = [](auto a, auto b) { return a < b; };
		
		//and of course we can call them
		auto boolean_val = smaller(3, 5);
		
		ASSERT(boolean_val);
		
		//we can also 'capture' variables define outside of the lamdda
		auto select_a_or_b = [boolean_val] (auto a, auto b)
			{ return boolean_val ? a : b; };
		
		auto select_first = select_a_or_b(3, 5);
		ASSERT(select_first==3);
		
		//changing the vale later has no effect, since we captured by vale
		boolean_val = false;
		auto select_first_again = select_a_or_b(3, 5);
		ASSERT(select_first_again==3);
		
		//let's try that again by reference (since C++14 we can also use
		//default values for parameters):
		auto select_a_or_b_ref = [&boolean_val] (auto a = -1, auto b = 2)
			{ return boolean_val ? a : b; };
			//we can also specify a trailing return type if desired...
			
		auto select_ref_b = select_a_or_b_ref(1,2);
		ASSERT(select_ref_b==2);
		
		//change the boolean
		boolean_val = true;
		auto select_ref_a = select_a_or_b_ref(1,2);
		ASSERT(select_ref_a==1);
		
		//we can just capture all currently valid variables (copy)
		//no need to specify () if there are no parameters
		auto return_boolean = [=] { return boolean_val; };
		auto val_via_function = return_boolean();
		ASSERT(val_via_function);
		
		//or all variables [&], or the current class [this], you can also
		//change the behavior for specific variables: [=, &complexInst]
		
		//with C++17 we can also caputre [*this]
	}

};

#endif //__LAMBDA_H_
