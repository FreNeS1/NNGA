#include "Output.hpp"

namespace NNGA {

	OutputNode::OutputNode()
		: BaseNode()
		, _seed("NoSeed")
		, _giver(nullptr)
	{ }

	std::string OutputNode::getSeed() const
	{
		return _seed;
	}

	Data OutputNode::getData()
	{
		return _giver->getData();
	}

	void OutputNode::setSeed(const std::string& seed)
	{
		_seed = seed;
	}

	void OutputNode::setGiver(BaseNode& giver)
	{
		_giver = giver.getPtr();
	}

	void OutputNode::setGiver(BaseNodePtr giver)
	{
		_giver = giver;
	}
}
