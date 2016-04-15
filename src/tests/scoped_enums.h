#ifndef __SCOPED_ENUMS_H_
#define __SCOPED_ENUMS_H_

namespace scoped_enums
{

	//this how enums used to work... (we cannot forward-declare them)
	enum old_style { one, two, three };

	//and since C++11 scoped enums (we can forward-declare them)
	enum class new_style { four, five, six };

	auto test() noexcept -> void
	{
		//so we access the enum without scope...
		auto an_enum = one;
		//because the old enum is leaking it's items

		//we can specify the scope, but it is not legal
		//(depending on the compiler you might get a warning)
		auto another_enum = old_style::one;

		//and there was no strong typing
		int32_t implicit_conversion = another_enum;

		//so no more 'dirty' access
		//auto doesn_work = four;

		//always access via the enum's scope
		auto new_enum = new_style::four;

		//no we explicitly need to express our intentions
		int32_t no_implicit_conversion = static_cast<int32_t>(new_enum); //better
	}

};

#endif //__SCOPED_ENUMS_H_
