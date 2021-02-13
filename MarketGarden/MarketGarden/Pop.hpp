#pragma once

/**
 * @brief POPの基底クラス
 */
class PopBase
{
protected:
	double _age = 0.0;			//!< 年齢
	const double _spanOfLife;	//!< 天寿

public:
	const double deltaDate = 1.0 / 365.0;	//!< 1日
	const double deltaMonth = 1.0 / 12.0;	//!< 1ヶ月

public:
	PopBase(const double spanOfLife)
		: _spanOfLife(spanOfLife) {}

	virtual ~PopBase() {}

	/**
	 * @returns 年齢を返す
	 */
	const double age() const { return _age; }

	/**
	 * @returns 天寿を返す
	 */
	const double spanOfLife() const { return _spanOfLife; }

	/**
	 * @returns 天寿を全うしたか返す
	 */
	const bool enableNaturalDeath() const { return _age > _spanOfLife; }

	/**
	 * @brief 経過時間を年齢に足し込む
	 */
	void elapsedTime(const double yearly) { _age += yearly; }
};

/**
 * 男子クラス
 */
class Male : PopBase
{
public:
	Male(const double spanOfLife)
		: PopBase(spanOfLife) {}
};

/**
 * 女子クラス
 */
class Female : PopBase
{
private:
	const double _minimumOfMarriageable = 15.0;	//!< 出産適齢期の下限
	const double _maximumOfMarriageable = 35.0;	//!< 出産適齢期の上限
	bool _wasMarriaged = false;					//!< 出産したか否か
	double _pastMarriaged = 0.0;				//!< 出産してからの年数
	const double _marriageableSpan = 2.0;		//!< また出産可能になる年数

public:
	Female(const double spanOfLife)
		: PopBase(spanOfLife) {}
};