#include "Constant.hpp"

namespace NNGA {

	ConstantNode::ConstantNode()
		: _data()
	{ }

	ConstantNode::ConstantNode(Data data)
		: _data(data)
	{ }

	ConstantNode::ConstantNode(double value, bool valid)
		: _data(value, valid)
	{ }

	Data ConstantNode::getdata() const
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