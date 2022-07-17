#include "EventManager.h"
#include "CSceneManager.h"

CEventManager::CEventManager()
{

}

CEventManager::~CEventManager()
{
	EventList.clear();
}

void CEventManager::Init()
{

}

// �̺�Ʈ ������ DELETE_OBJECT Ÿ���� ����Ʈ�� ���� �ȵȴ�
// DELETE_OBJECT �� ��� ���� ������Ʈ�� ������ ����ֱ� ������ ���⼭ ������ �ȵ�
// ADD_OBJECT �� �̺�Ʈ �Ŵ����� ����ִ� �߰� ��� ������Ʈ�� Delete ����� �Ѵ�
// �ű� �߰��Ǵ� �̺�Ʈ�� �� �� �����ϰ� Clear �߰��� ��
void CEventManager::Clear()
{
	for (const EventInfo& eventInfo : EventList)
	{
		if(eventInfo.Type != EVENT_TYPE::ADD_OBJECT)
			continue;

		if(eventInfo.Parameter)
			delete eventInfo.Parameter;

		if (eventInfo.Parameter2)
			delete eventInfo.Parameter2;

		if (eventInfo.Parameter3)
			delete eventInfo.Parameter3;
	}
	EventList.clear();
}

void CEventManager::Update(float InDeltaTime)
{
	for (const EventInfo& eventInfo : EventList)
	{
		switch (eventInfo.Type)
		{
			case EVENT_TYPE::ADD_OBJECT:
				CSceneManager::GetInstance()->AddObject(
					*((OBJ_LAYER*)eventInfo.Parameter),
					((CObject*)eventInfo.Parameter2));

				delete eventInfo.Parameter;
			break;
			case EVENT_TYPE::DELETE_OBJECT:
				CSceneManager::GetInstance()->DeleteObject(
					*((OBJ_LAYER*)eventInfo.Parameter),
					((CObject*)eventInfo.Parameter2));

				delete eventInfo.Parameter;
			break;
			case EVENT_TYPE::CHANGE_SCENE:
				CSceneManager::GetInstance()->SetCurScene((CScene*)eventInfo.Parameter);
				Clear();
				return;
		}
	}
	EventList.clear();
}

void CEventManager::AddEvent(const EventInfo& InEventInfo)
{
	EventList.emplace_back(InEventInfo);
}

void CEventManager::AddObjectEvent(OBJ_LAYER InLayer, CObject* InObject)
{
	EventInfo eventInfo;
	eventInfo.Type = EVENT_TYPE::ADD_OBJECT;
	eventInfo.Parameter = new OBJ_LAYER(InLayer);
	eventInfo.Parameter2 = InObject;
	AddEvent(eventInfo);
}

void CEventManager::DeleteObjectEvent(OBJ_LAYER InLayer, CObject* InObject)
{
	EventInfo eventInfo;
	eventInfo.Type = EVENT_TYPE::DELETE_OBJECT;
	eventInfo.Parameter = new OBJ_LAYER(InLayer);
	eventInfo.Parameter2 = InObject;
	AddEvent(eventInfo);
}

void CEventManager::ChangeSceneEvent(CScene* InScene)
{
	EventInfo eventInfo;
	eventInfo.Type = EVENT_TYPE::CHANGE_SCENE;
	eventInfo.Parameter = InScene;
	AddEvent(eventInfo);
}