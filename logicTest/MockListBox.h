#pragma once
#include <gmock/gmock.h>
#include <windows.h>

class MockListBox
{
public:
	MOCK_METHOD1(AddString, int(LPCTSTR));
	MOCK_METHOD0(ResetContent, void());
};