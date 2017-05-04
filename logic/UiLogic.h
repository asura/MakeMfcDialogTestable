#pragma once
#include "logic_export.h"
#include "logic.h"
#include <memory>

template<typename IListBox, typename IEditBox>
class UiLogic
{
	IListBox* m_lst_items;
	IEditBox* m_edt_item;
	Logic m_logic;

public:
	UiLogic() = default;
	~UiLogic() = default;

	void SetLstItems(IListBox* const lst_items) { m_lst_items = lst_items; }
	void SetEdtItem(IEditBox* const edt_item) { m_edt_item = edt_item; }

	void UpdateList()
	{
		m_lst_items->ResetContent();

		const auto& items = m_logic.GetList();
		for (const auto& item : items)
		{
			m_lst_items->AddString(item.c_str());
		}
	}

	void Add()
	{
		CString item_name;
		m_edt_item->GetWindowText(item_name);

		m_logic.Add((LPCWSTR)item_name);

		UpdateList();
	}

	const Logic& logic() const { return m_logic; }
};
