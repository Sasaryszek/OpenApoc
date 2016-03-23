#pragma once
#include "library/sp.h"
#include "library/strings.h"
#include "game/stateobject.h"
#include <vector>

namespace OpenApoc
{

class Image;

class DoodadFrame
{
  public:
	sp<Image> image;
	int time;
};

class DoodadType : public StateObject<DoodadType>
{
  public:
	DoodadType() = default;
	int lifetime;
	Vec2<int> imageOffset;
	std::vector<DoodadFrame> frames;
};

} // namespace OpenApoc