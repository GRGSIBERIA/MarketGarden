#pragma once

/**
 * 区画の基底クラス
 */
class DivisionBase
{
	double infra = 1.0;	//!< インフラの成長度合い
public:

};

/**
 * 商業区画
 * 生産品の流通に関わる職業が中心
 * 商業力が低いと平坦物資が滞りがちになる
 */
class CommerceDivision : public DivisionBase
{
public:

};

/**
 * 鉱業区画
 * 戦略物資や消費財を獲得するための区画
 */
class MiningDivision : public DivisionBase
{
public:

};

/**
 * 産業(工業)区画
 * 消費財や物資を生産するための区画
 * インフラの製造にも必要
 */
class IndustryDivision : public DivisionBase
{
public:

};

/**
 * 住居区画
 * 住民と必ず紐付いた区画、失業者はいない
 */
class ResidenceDivision : public DivisionBase
{
public:

};

/**
 * 農業区画
 * 住民の量に応じて適宜農業が発展する
 * 1石を1年間に消費する量とすると1石=1反
 * 1000反=1km^2ぐらいで計算できる
 */
class FarmingDivision : public DivisionBase
{
public:

};

/**
 * 教育区画
 * 就学児を預かり、教育を受けるための区画
 * 3歳から15歳までを未就学児童とする
 */
class EducationDivision : public DivisionBase
{
public:

};

/**
 * 研究区画
 * 研究力があるほど文明が進歩しやすい
 * 例えば、区画あたりの人口密度バフを生成するには産業力と研究力の両面が必要
 */
class ResearchDivision : public DivisionBase
{
public:

};

/**
 * 軍需区画
 * 軍事力を有するのに必要な物資を生産する区画
 */
class MunitionsDivision : public DivisionBase
{
public:
	
};