#include "TCore.h"
#include "TSound.h"

class Sample : public TCore
{
public:
	bool	Init()
	{
		TSound::Get()->Init();
		TSound::Get()->Load("../../data/romance.mid", false);

		TSound::Get()->Load("../../data/ItemGain.wav", false);
		TSound::Get()->Load("../../data/Gun1.wav", false);
		TSound::Get()->Load("../../data/GunShot.mp3", false);
		return true;
	}

	bool	Frame()
	{
		TSound::Get()->Frame();
		if (I_Input.Key('3') == KEY_PUSH)
		{
			TSound::Get()->PlayEffect(1);
		}
		if (I_Input.Key('4') == KEY_PUSH)
		{
			TSound::Get()->PlayEffect(2);
		}
		if (I_Input.Key('5') == KEY_PUSH)
		{
			TSound::Get()->PlayEffect(3);
		}
		if (I_Input.Key('2') == KEY_PUSH)
		{
			TSound::Get()->paused(0);
		}
		if (I_Input.Key('7') == KEY_PUSH)
		{
			TSound::Get()->Stop(0);
		}
		if (I_Input.Key(VK_INSERT) == KEY_HOLD)
		{
			TSound::Get()->Volume(0, g_fSecPerFrame*1.0f, true);
		}
		if (I_Input.Key(VK_DELETE) == KEY_HOLD)
		{
			TSound::Get()->Volume(0, g_fSecPerFrame*1.0f, false);
		}
		return true;
	}
	bool	Render()
	{
		TSound::Get()->Render();
		return true;
	}
	bool	Release()
	{
		TSound::Get()->Release();
		return true;
	}
public:
	Sample() {
	}
	virtual ~Sample() {}
};

GAME_RUN("SampleSound", 800, 600)