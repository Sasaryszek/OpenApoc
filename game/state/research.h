#pragma once

#include "game/state/stateobject.h"
#include <map>

namespace OpenApoc
{

class UfopaediaEntry;
class Base;
class ResearchDependency;
class ItemDependency;
class Agent;
class Lab;

class ProjectDependencies
{
  public:
	ProjectDependencies() = default;
	std::list<ResearchDependency> research;
	std::list<ItemDependency> items;

	bool satisfied(StateRef<Base> base) const;
};

class ResearchTopic : public StateObject<ResearchTopic>
{
  public:
	ResearchTopic();
	enum class Type
	{
		BioChem,
		Physics,
	};
	static const std::map<Type, UString> TypeMap;
	enum class LabSize
	{
		Small,
		Large,
	};
	static const std::map<LabSize, UString> LabSizeMap;
	UString name;
	UString description;
	StateRef<UfopaediaEntry> ufopaedia_entry;
	unsigned man_hours;
	unsigned man_hours_progress;
	Type type;
	LabSize required_lab_size;
	StateRef<Lab> current_lab;

	unsigned score;
	bool started;

	ProjectDependencies dependencies;

	bool isComplete() const;
};

class ResearchDependency
{
  public:
	ResearchDependency();
	enum class Type
	{
		Any,
		All,
	};
	static const std::map<Type, UString> TypeMap;
	Type type;

	std::set<StateRef<ResearchTopic>> topics;

	bool satisfied() const;
};

class ItemDependency
{
  public:
	ItemDependency() = default;
	// FIXME: Replace with StateRef<GenericItemClass> or something?
	std::map<UString, int> items;

	bool satisfied(StateRef<Base> base) const;
};

class Lab : public StateObject<Lab>
{
  public:
	ResearchTopic::LabSize size;
	ResearchTopic::Type type;
	StateRef<ResearchTopic> current_project;
	std::list<StateRef<Agent>> assigned_agents;

	static void setResearch(StateRef<Lab> lab, StateRef<ResearchTopic> topic);
};

class ResearchState
{
  public:
	ResearchState();
	unsigned int num_labs_created;
	std::map<UString, sp<ResearchTopic>> topics;
	std::map<UString, sp<Lab>> labs;
};

} // namespace OpenApoc
