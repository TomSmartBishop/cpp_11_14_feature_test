#ifndef __DEFAULT_OVERRIDE_H_
#define __DEFAULT_OVERRIDE_H_

namespace default_override
{

	class simple_base
	{
	public:
		//let the compiler generate the special member functions with default:
		simple_base() noexcept = default;
		virtual ~simple_base() noexcept = default;

		virtual auto do_something() noexcept -> int32_t const
		{
			return 0;
		}
	};

	class specialized_class : public simple_base
	{
	public:
		//let the compiler generate the special member functions with default:
		specialized_class() noexcept = default;
		~specialized_class() noexcept = default;

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
	};

	auto test() noexcept -> void
	{
		auto b = simple_base{};

		auto s = specialized_class{};
	}

};

#endif //__DEFAULT_OVERRIDE_H_
