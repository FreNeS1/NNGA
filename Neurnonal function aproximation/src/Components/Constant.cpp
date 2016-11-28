#include "Constant.hpp"

namespace NNGA {

	ConstantNode::ConstantNode()
		: BaseNode()
		, _data()
	{ }

	ConstantNode::ConstantNode(Data data)
		: BaseNode()
		, _data(data)
	{ }

	ConstantNode::ConstantNode(double value, bool valid)
		: BaseNode()
		, _data(value, valid)
	{ }

	Data ConstantNode::getData()
	{
		return _data;
	}

	void ConstantNode::setData(Data data)
	{
		_data = data;
	}

	void ConstantNode::setData(double value, bool valid)
	{
		_data = Data(value, valid);
	}

}