#ifndef __DEFAULT_OVERRIDE_H_
#define __DEFAULT_OVERRIDE_H_

namespace default_override
{

	class simple_base
	{
	public:
		//Let the compiler generate the special member functions with default:
		//(now we have 5 special member functions in C++: ctor, dtor, copy ctor, assignment op, move ctor, move assignment op)
		//The rules for automatic generation of these member functions are are not that simple.
		//I recommend to take a look at the book "Effective Modern C++" in Item 17 (by Scott Meyers)
		simple_base() noexcept = default;
		virtual ~simple_base() noexcept = default;
		simple_base(const simple_base& copy) noexcept = default;
		auto operator=(const simple_base& copy) noexcept -> simple_base& = default;
		simple_base(simple_base&& move) noexcept = default;
		auto operator=(simple_base&& move) noexcept -> simple_base& = default;

		virtual auto do_something() noexcept -> int32_t const
		{
			return 0;
		}
	};

	class specialized_class : public simple_base
	{
	public:
		//If you do not have any specif requirements for your class I recommend to
		//either specify all 5 special member functions (by implmenting them or via
		//defaul) - "Rule of five" or none "Rule of zero".
		specialized_class() noexcept = default;
		~specialized_class() noexcept = default;
		specialized_class(const specialized_class& copy) noexcept = default;
		auto operator=(const specialized_class& copy) noexcept -> specialized_class& = default;
		specialized_class(specialized_class&& move) noexcept = default;
		auto operator=(specialized_class&& move) noexcept -> specialized_class& = default;
		
		//In case you want to forbid eg. copying the object you can also delete the
		//special member functions that allow copies:
		//specialized_class(const specialized_class& copy) noexcept = delete;
		//auto operator=(const specialized_class& copy) noexcept -> specialized_class& = delete;
		
		//we let the compiler know that we intend to override do_something of the base class
		auto do_something() noexcept -> int32_t const override //a lot of typing :(
		{
			return 1;
		}
		//no more mismatches of the signature!

		//if try to do the same here the compiler will generate an error
		auto do_something(int32_t val) noexcept -> int32_t const //override
		{
			return val;
		}
		
		//but delet can be also used for non-special member functions
		//auto do_something(char val) noexcept -> char const = delete;
		//auto do_something(float32_t val) noexcept -> float32_t const = delete;
	};

	auto test() noexcept -> void
	{
		auto b = simple_base{};
		auto zero = b.do_something();
		ASSERT(zero==0);

		auto s = specialized_class{};
		auto one = s.do_something();
		ASSERT(one==1);
		
		auto surprise = s.do_something(0.0f); //which method will be executed..?
		auto surprise_again = s.do_something('s'); //and now..?
		
		//so we can actually delete methods to avoid this implicit conversion...
		//unfortunately it is again a lot of typing... :(
	}

};

#endif //__DEFAULT_OVERRIDE_H_
