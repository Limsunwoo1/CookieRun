#pragma once
#include "CScene.h"
#include "PetObject.h"
#include <map>
class CShop :
    public CScene
{
public:
    typedef std::map<std::string, CPetObject*> ItemList;

private:
    ItemList mItemList;

    CPetObject* SeleteItem;
    String SeletItemName;
public:
    CShop();
    virtual ~CShop();

    virtual void Init() override;
    virtual void Clear() override;

    virtual void Update(float InDeltaTime) override;
};

