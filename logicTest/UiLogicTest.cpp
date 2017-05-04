#include "stdafx.h"
#include <catch.hpp>
#include "MockEditBox.h"
#include "MockListBox.h"
#include "UiLogic.h"

TEST_CASE("UiLogic", "[UiLogic]")
{
	UiLogic<MockListBox, MockEditBox> sut;

	MockListBox list;
	sut.SetLstItems(&list);

	MockEditBox edit;
	sut.SetEdtItem(&edit);

	SECTION("������ԁ�UpdateList")
	{
		EXPECT_CALL(list, ResetContent())
			.Times(1);
		EXPECT_CALL(list, AddString(::testing::_))
			.Times(0);

		sut.UpdateList();

		THEN("Logic���̏�Ԃ͕ω����Ȃ�")
		{
			REQUIRE(sut.logic().GetList().empty());

			WHEN("Add")
			{
				// Add
				EXPECT_CALL(edit, GetWindowText(::testing::_))
					.WillOnce(
						::testing::DoAll(
							::testing::SetArgReferee<0>(L"ABC"),
							::testing::Return(0)
						)
				);
				EXPECT_CALL(list, AddString(::testing::_))
					.Times(1);

				// UpdateList
				EXPECT_CALL(list, ResetContent())
					.Times(1);

				sut.Add();

				THEN("Logic���ɍ��ڂ��ǉ������")
				{
					REQUIRE(sut.logic().GetList().size() == 1);
					CHECK(sut.logic().GetList()[0] == L"ABC");
				}
			}
		}
	}
}
