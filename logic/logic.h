#pragma once
#include "logic_export.h"
#include <string>
#include <vector>

#pragma warning(disable: 4251)

class LOGIC_API Logic
{
	std::vector<std::wstring> m_list;

public:
	Logic() = default;
	~Logic() = default;

	const std::vector<std::wstring>& GetList() const;
	void Add(const std::wstring& item_name);
};
