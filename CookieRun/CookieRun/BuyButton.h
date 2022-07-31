#pragma once
#include "Button.h"
class CBuyButton :
    public CButton
{
 
private:
    String ITemName;
public:
    CBuyButton(Vector2D InPos, Vector2D InSca);
    ~CBuyButton();

    virtual void MouseLButtonPress() override;
    void SetItemName(const String& InName) { ITemName = InName;};
    void BuyButton();
};

