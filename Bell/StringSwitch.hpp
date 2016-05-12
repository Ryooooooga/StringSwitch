//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#pragma once

#include <boost/utility/string_ref.hpp>

namespace Bell {

	/**
	 * @brief      BasicStringSwitch
	 *
	 * @tparam     CharType  文字型
	 * @tparam     Traits    トレイト
	 */
	template <typename ValueType, typename CharType, typename Traits = std::char_traits<CharType>>
	class BasicStringSwitch
	{
		using StringRefType = boost::basic_string_ref<CharType, Traits>;

		StringRefType		key_;
		const ValueType*	value_;

	public:
		/**
		 * @brief      BasicStringRef
		 *
		 * @param[in]  s
		 */
		explicit BasicStringSwitch(StringRefType s) noexcept
			: key_(s), value_(nullptr) {}


		/**
		 * @brief      case
		 *
		 * @param[in]  s
		 * @param[in]  value
		 *
		 * @return     *this
		 */
		BasicStringSwitch& _case(StringRefType s, const ValueType& value) noexcept
		{
			if (!value_ && key_ == s)
			{
				value_ = &value;
			}

			return *this;
		}

		/**
		 * @brief      default
		 *
		 * @param[in]  value
		 *
		 * @return
		 */
		const ValueType& _default(const ValueType& value) const noexcept
		{
			return value_ ? *value_ : value;
		}

		/**
		 * @brief
		 *
		 * @return
		 */
		const ValueType& value() const noexcept
		{
			assert(value_);
			return *value_;
		}
	};

	template <typename ValueType> using StringSwitch	= BasicStringSwitch<ValueType, char>;
	template <typename ValueType> using WStringSwitch	= BasicStringSwitch<ValueType, wchar_t>;
	template <typename ValueType> using U16StringSwitch	= BasicStringSwitch<ValueType, char16_t>;
	template <typename ValueType> using U32StringSwitch	= BasicStringSwitch<ValueType, char32_t>;

}	//	namespace Bell
