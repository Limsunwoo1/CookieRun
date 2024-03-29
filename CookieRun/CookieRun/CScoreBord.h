#pragma once
#include "UI.h"
#
#include <vector>

class CTexture;

class CScoreBord :
    public CUI
{
    MEMBER(int, SaveScore)
private:
    std::vector<String> FilePathList;

    int                 MaxCount;
    float               IntervalPosX;
    int                 Score;

    unsigned int        buf[20];
    unsigned int        bufsize;
public:
    CScoreBord();
    CScoreBord(Vector2D InPos, Vector2D InScale);
    ~CScoreBord();

    virtual void Update(float InDeltaTime) override;
    virtual void Render(HDC InHdc) override;

    int GetScore() const { return Score; };
    void SetScore(int jelly) {Score = jelly;};

    void ReSetScore();
};
