#include "stdafx.h"
#include <catch.hpp>
#include "logic.h"

SCENARIO("¶¬¨’Ç‰Á", "[logic]")
{
	Logic sut;
	REQUIRE(sut.GetList().empty());

	WHEN("€–Ú‚ğ’Ç‰Á‚·‚é")
	{
		sut.Add(L"abc");

		THEN("ƒŠƒXƒg‚É’Ç‰Á€–Ú‚ª‘‚¦‚é")
		{
			REQUIRE(sut.GetList().size() == 1);
			CHECK(sut.GetList()[0] == L"abc");
		}
	}
}
