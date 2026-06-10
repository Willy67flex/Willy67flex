#include "Array.hpp"

template <typename T>

Array<T>::Array() : _data(NULL), _size(0) {}


template <typename T>

Array<T>::Array(unsigned int n) : _size(n)
{
	if (n > 0)
		_data = new T[n]();
	else
		_data = NULL;
}


template <typename T>

Array<T>::Array(const Array &other) : _data(NULL), _size(0)
{
	*this = other;
}


template <typename T>

Array<T>::~Array()
{
	if (_data)
		delete[] _data;
}


template <typename T>

Array<T>	&Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		if (_data)
			delete[] _data;
		_size = other._size;
		if (_size > 0)
		{
			_data = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_data[i] = other._data[i];
		}
		else
			_data = NULL;
	}
	return *this;
}


template <typename T>

T	&Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _data[index];
}


template <typename T>

const T	&Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _data[index];
}

template <typename T>

unsigned int	Array<T>::size() const
{
	return _size;
}
