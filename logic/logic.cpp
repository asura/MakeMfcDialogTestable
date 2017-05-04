#include "stdafx.h"
#include "logic.h"

const std::vector<std::wstring>& Logic::GetList() const
{
	return m_list;
}

void Logic::Add(const std::wstring& item_name)
{
	m_list.push_back(item_name);
}
