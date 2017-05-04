#include "stdafx.h"
#include <catch.hpp>
#include "logic.h"

SCENARIO("�������ǉ�", "[logic]")
{
	Logic sut;
	REQUIRE(sut.GetList().empty());

	WHEN("���ڂ�ǉ�����")
	{
		sut.Add(L"abc");

		THEN("���X�g�ɒǉ����ڂ�������")
		{
			REQUIRE(sut.GetList().size() == 1);
			CHECK(sut.GetList()[0] == L"abc");
		}
	}
}
