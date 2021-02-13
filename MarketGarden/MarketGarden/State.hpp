#pragma once
#include <Siv3D.hpp>

enum class State
{
	START,
	NEW_GAME,
	GAME
};

void UpdateState(State state)
{
	switch (state)
	{
	case State::START:
		break;
	default:
		break;
	}
}

class StateBase
{
	void* currentState = nullptr;

public:
	virtual ~StateBase()
	{

	}

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual StateBase* finalize() = 0;
};

class StartState : public StateBase
{
	const Font strong = Font(32);
	const Font font = Font(24);

	const Audio mouseOver = Audio(U"resources/se/click.mp3");

	const Color background = Color(U"#232946");
	const Color stroke = Color(U"#b8c1ec");
	const Color highlight = Color(U"#eebbc3");

	bool tobeNewGame = false;
	bool tobeLoadGame = false;
	bool tobeExit = false;

	bool toggleNewGame = false;
	bool toggleLoadGame = false;
	bool toggleExit = false;

public:
	StartState()
		: StateBase()
	{
		Scene::SetBackground(background);
	}

	void update() override
	{

	}

private:
	void toggleButton(const RectF& reg, bool& toggler)
	{
		if (reg.mouseOver())
		{
			reg.bottom().draw(highlight);
			if (!toggler)
			{
				mouseOver.playOneShot();
				toggler = true;
			}
		}
		else
		{
			toggler = false;
		}
	}

public:
	void draw() override
	{
		auto center = Window::ClientSize();
		center.x >>= 1;
		center.y >>= 1;

		const auto jatitle = center - Point(0, 32);
		const auto entitle = center;

		strong(U"人民は畑で採れる").drawAt(jatitle, stroke);
		const auto enreg = font(U"Government of the People to be Born the Market Garden").drawAt(entitle, stroke);
		enreg.bottom().draw(stroke);

		const auto newgame = font(U"NEW GAME").drawAt(enreg.bottomCenter() + Point(0, 32), highlight);
		const auto loadgame = font(U"LOAD GAME").drawAt(newgame.bottomCenter() + Point(0, 24), highlight);
		const auto exitgame = font(U"EXIT").drawAt(loadgame.bottomCenter() + Point(0, 24), highlight);

		toggleButton(newgame, toggleNewGame);
		toggleButton(loadgame, toggleLoadGame);
		toggleButton(exitgame, toggleExit);
	}

	StateBase* finalize() override
	{
		return this;
	}
};