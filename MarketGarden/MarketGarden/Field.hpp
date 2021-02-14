#pragma once

/**
 * 土地の基底クラス
 * 平地、砂漠、山岳等、たまに戦略物資や産業物資が埋まってる
 */
class FieldBase
{
public:

};

enum class Field
{
	OCEAN = 0,	// 海
	LAND,		// 平地
	FOREST,		// 森林
	DESERT,		// 砂漠
	WETLANDS,	// 湿地
	ALPINE,		// 山岳
	TUNDRA		// ツンドラ
};