//=====================================================================
// Copyright (c) 2015-2016 Ryooooooga.
// https://github.com/Ryooooooga
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=====================================================================

#include <gtest/gtest.h>
#include "../../../Source/Bell/Util/StringSwitch.hpp"

TEST(Bell_StringSwitch, StringSwitch)
{
	using namespace Bell;

	EXPECT_EQ(
		2,
		StringSwitch<int>(u8"b")
			._case(u8"a", 1)
			._case(u8"b", 2)
			._case(u8"c", 3)
			.value()
	);

	EXPECT_EQ(
		2,
		StringSwitch<int>(u8"b")
			._case(u8"a", 1)
			._case(u8"b", 2)
			._case(u8"c", 3)
			._default(-1)
	);

	EXPECT_EQ(
		-1,
		StringSwitch<int>(u8"z")
			._case(u8"a", 1)
			._case(u8"b", 2)
			._case(u8"c", 3)
			._default(-1)
	);
}

TEST(Bell_StringSwitch, WStringSwitch)
{
	using namespace Bell;

	EXPECT_EQ(
		2,
		WStringSwitch<int>(L"b")
			._case(L"a", 1)
			._case(L"b", 2)
			._case(L"c", 3)
			.value()
	);

	EXPECT_EQ(
		2,
		WStringSwitch<int>(L"b")
			._case(L"a", 1)
			._case(L"b", 2)
			._case(L"c", 3)
			._default(-1)
	);

	EXPECT_EQ(
		-1,
		WStringSwitch<int>(L"z")
			._case(L"a", 1)
			._case(L"b", 2)
			._case(L"c", 3)
			._default(-1)
	);
}

TEST(Bell_StringSwitch, U16StringSwitch)
{
	using namespace Bell;

	EXPECT_EQ(
		2,
		U16StringSwitch<int>(u"b")
			._case(u"a", 1)
			._case(u"b", 2)
			._case(u"c", 3)
			.value()
	);

	EXPECT_EQ(
		2,
		U16StringSwitch<int>(u"b")
			._case(u"a", 1)
			._case(u"b", 2)
			._case(u"c", 3)
			._default(-1)
	);

	EXPECT_EQ(
		-1,
		U16StringSwitch<int>(u"z")
			._case(u"a", 1)
			._case(u"b", 2)
			._case(u"c", 3)
			._default(-1)
	);
}

TEST(Bell_StringSwitch, U32StringSwitch)
{
	using namespace Bell;

	EXPECT_EQ(
		2,
		U32StringSwitch<int>(U"b")
			._case(U"a", 1)
			._case(U"b", 2)
			._case(U"c", 3)
			.value()
	);

	EXPECT_EQ(
		2,
		U32StringSwitch<int>(U"b")
			._case(U"a", 1)
			._case(U"b", 2)
			._case(U"c", 3)
			._default(-1)
	);

	EXPECT_EQ(
		-1,
		U32StringSwitch<int>(U"z")
			._case(U"a", 1)
			._case(U"b", 2)
			._case(U"c", 3)
			._default(-1)
	);
}
