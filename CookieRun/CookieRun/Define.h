#pragma once

// �ּ�ó���ϸ� �浹 �簢�� �Ⱥ���
//#define SHOW_COLLISION

#ifdef _DEBUG						// ����� ��忡�� ������� ����
#	define USE_MEMORY_TRACE
#	define USE_LOGER
#else								// ������ ��忡�� ������� ����
#	define USE_MEMORY_TRACE
//#	define USE_LOGER
#	define USE_CRASH_HANDLER		// ũ���� �ڵ鷯�� ����� ��忡���� ���۾��Ѵ�.
#endif


#define SINGLE(type) \
private: \
	type(); \
	~type(); \
public: \
	static type* GetInstance() \
	{ \
		static type* Instance; \
		if(Instance == nullptr) \
			Instance = new type(); \
		return Instance; \
	} \
	static void DestroyInstance() \
	{ \
		if(GetInstance()) \
			delete GetInstance(); \
	} \

#define KEY_STATE(InKey) CKeyManager::GetInstance()->GetKeyState(InKey)
#define MOUSE_POS CKeyManager::GetInstance()->GetMousePos();

#define MEMBER(type, name)									\
private:													\
	type name;												\
public:														\
	void Set##name(const type& InValue) {name = InValue;}	\
	type Get##name() {return name;}

#define PROTECT_MEMBER(type, name)							\
protected:													\
	type name;												\
public:														\
	void Set##name(const type& InValue) {name = InValue;}	\
	type Get##name() {return name;}