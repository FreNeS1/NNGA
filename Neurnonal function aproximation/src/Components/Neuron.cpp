#include "Neuron.hpp"

namespace NNGA {

	NeuronNode::NeuronNode()
		: BaseNode()
		, _seed("NoSeed")
		, _degree(0)
		, _data(0.0, true)
		, _calculated(false)
		, _infiniteLoopCatch(false)
		, _inputs()
		, _weights()
	{ }

	void NeuronNode::configure(std::vector<BaseNode>& inputs, std::vector<BaseNode>& weights)
	{
		_degree = inputs.size();
		_inputs = std::vector<BaseNodePtr>(_degree);
		_weights = std::vector<BaseNodePtr>(_degree);

		for (size_t i = 0; i < _degree; i++)
		{
			_inputs[i] = inputs[i].getPtr();
			_weights[i] = weights[i].getPtr();
		}
	}

	void NeuronNode::configure(std::vector<BaseNodePtr>& inputs, std::vector<BaseNodePtr>& weights)
	{
		_degree = inputs.size();
		_inputs = std::vector<BaseNodePtr>(_degree);
		_weights = std::vector<BaseNodePtr>(_degree);

		for (size_t i = 0; i < _degree; i++)
		{
			_inputs[i] = inputs[i];
			_weights[i] = weights[i];
		}
	}

	Data NeuronNode::getData()
	{
		/* If it's allready calculated, just relay the value */
		if (_calculated)
			return _data;

		/* If this getData was called before but output was not determined yet -> infinite loop -> not valid net*/
		if (_infiniteLoopCatch)
		{
			_data = Data(0.0, false);
			_calculated = true;
			return _data;
		}

		/* Set the flag for infinite loop catching*/
		_infiniteLoopCatch = true;

		/* Get data for all inputs, weigh it, checking if it's valid */
		for (size_t i = 0; i < _degree; i++)
		{
			_data += _inputs[i]->getData() * _weights[i]->getData();

			if (!_data.getValid())
			{
				_data = Data(0.0, false);
				_calculated = true;
				return _data;
			}
		}

		/* If everything went ok to here, data is valid and can be outputed */
		_calculated = true;
		return _data;
	}

	std::string NeuronNode::getSeed() const
	{
		return _seed;
	}

	void NeuronNode::setSeed(const std::string& seed)
	{
		_seed = seed;
	}

}