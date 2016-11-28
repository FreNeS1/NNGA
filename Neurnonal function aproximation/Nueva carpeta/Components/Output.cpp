#include "Output.hpp"

namespace NNGA {

	OutputNode::OutputNode()
		: ConstantNode()
		, _seed("NoSeed")
	{ }

	OutputNode::OutputNode(Data data)
		: ConstantNode(data)
		, _seed("NoSeed")
	{ }

	OutputNode::OutputNode(double value, bool valid)
		: ConstantNode(value, valid)
		, _seed("NoSeed")
	{ }

	std::string OutputNode::getSeed() const
	{
		return _seed;
	}

	void OutputNode::setSeed(const std::string& seed)
	{
		_seed = seed;
	}
}
