#pragma once
#include <gmock/gmock.h>
#include <atlstr.h>

class MockEditBox
{
public:
	MOCK_METHOD1(GetWindowText, int(CString&));
};
