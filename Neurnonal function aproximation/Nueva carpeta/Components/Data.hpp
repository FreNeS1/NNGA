#pragma once

/*
* AUTHOR: Jos� Antonio D�az Mata
*/

namespace NNGA {

	struct Data
	{
	public:
		Data();
		Data(double value, bool valid);

		friend Data		operator+(const Data& a, const Data& b);
		Data&			operator+=(const Data& d);

		double	getValue() const;
		bool	getValid() const;

	private:
		double	_value;
		bool	_valid;
	};

}