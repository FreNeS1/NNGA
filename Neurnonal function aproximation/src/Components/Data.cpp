#include "Data.hpp"

namespace NNGA {

	Data::Data()
		: _value(0.0)
		, _valid(false)
	{ }

	Data::Data(double value, bool valid)
		: _value(value)
		, _valid(valid)
	{ }

	Data operator+(const Data& d1, const Data& d2)
	{
		return Data(d1._value + d2._value, d1._valid && d2._valid);
	}

	Data operator*(const Data& d1, const Data& d2)
	{
		return Data(d1._value * d2._value, d1._valid && d2._valid);
	}

	Data& Data::operator+=(const Data& d)
	{
		_value += d._value;
		_valid = _valid && d._valid;
		return (*this);
	}

	Data& Data::operator*=(const Data& d)
	{
		_value *= d._value;
		_valid = _valid && d._valid;
		return (*this);
	}

	double Data::getValue() const
	{
		return _value;
	}

	bool Data::getValid() const
	{
		return _valid;
	}

	/********************************/

	BaseNode::BaseNode()
	{ }

	Data BaseNode::getData()
	{
		return Data(0.0, false);
	}

	BaseNode::BaseNodePtr BaseNode::getPtr()
	{
		return shared_from_this();
	}

}