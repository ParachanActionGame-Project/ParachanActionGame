﻿
# pragma once
#include "Common.hpp"
#include <vector>
#include "ParachanSample.hpp"

// parachanゲームシーンのサンプル
class ParaSampleScene : public MyApp::Scene
{
private:
	std::vector<ParachanSample> parachans;
	int countClick = 0;
	int countScore = 0;
	std::vector<Texture> textures;
public:

	ParaSampleScene(const InitData& init);

	void checkMouseOver();

	void checkMouseClick();

	void update() override;

	void draw() const override;
};