#pragma once
#include "Button.h"

class CPetObject;

class CSelectButton :
    public CButton
{
private:
    String ITemName;
    CPetObject* trackingItem;
public:
    CSelectButton(Vector2D InPos, Vector2D InScale);
    ~CSelectButton();

    virtual void Update(float InDeltaTime) override;
    virtual void MouseLButtonPress() override;

    void SetTrackingItem(CPetObject* InItem) {trackingItem = InItem;};
    void SetITemName(const String InName) {ITemName = InName;};
};

