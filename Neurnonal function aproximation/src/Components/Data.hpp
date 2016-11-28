#pragma once

/*
* AUTHOR: José Antonio Díaz Mata
*/

#include <memory>

namespace NNGA {

	struct Data
	{
	public:
		Data();
		Data(double value, bool valid);

		friend Data		operator+(const Data& a, const Data& b);
		friend Data		operator*(const Data& a, const Data& b);
		Data&			operator+=(const Data& d);
		Data&			operator*=(const Data& d);

		double	getValue() const;
		bool	getValid() const;

	private:
		double	_value;
		bool	_valid;
	};

	/**************************************/

	class BaseNode : public std::enable_shared_from_this<BaseNode>
	{
	public:
		typedef std::shared_ptr<BaseNode> BaseNodePtr;

	public:
		virtual Data	getData();
		BaseNodePtr		getPtr();

	protected:
		BaseNode();
	};

}