#pragma once
#include "Define.h"
#include "Typedef.h"
#include <map>

class CPetObject;

class CItemManager
{
	SINGLE(CItemManager);

	typedef std::map<String, CPetObject*> ItemList;
	typedef std::pair<String, CPetObject*> PairItemList;
private:
	CPetObject* SelectItem;
	CPetObject* BuyItem;
	ItemList mItemList;
public:
	void Init();
	void Update(float InDeltaTime);

	void SetSelectItem(String& InName);
	CPetObject* GetSelectItem() { return SelectItem; };
	void SetBuyItem(String& InName);
	const std::map<String, CPetObject*>& GetItemList()const {return mItemList;};

	CPetObject* FindItem(String& InName);
	void SettingSelectItem(const String& InName);
};

