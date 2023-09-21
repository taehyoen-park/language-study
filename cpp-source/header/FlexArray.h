#pragma once
#include<iostream>

template<typename T>
class FlexArray{
private:
	std::unique_ptr<T[]> mData;
	size_t mSize;
	size_t mCapacity;
public:
	FlexArray();
	FlexArray(const std::initializer_list<T>& init);
	void push_back(const T& data);
	void pop_back();
	void reserve(const size_t& capacity);
	void resize(const size_t& size, const int& value);
	void erase(const size_t& index);
	void erase(const size_t& Lb,const size_t& Rb);
	void clear();
	bool empty()const;
	size_t find(const int& value)const;
	size_t size()const;
	size_t capacity()const;
	T* begin()const;
	T* end()const;
	T& operator[](const size_t& index)const;
	void operator=(FlexArray<T>& fa);
	bool operator==(const FlexArray<T>& fa)const;
};


template<typename T>
FlexArray<T>::FlexArray(const std::initializer_list<T>& init)
{
	this->mSize = init.size();
	this->mData = std::make_unique<T[]>(this->mSize);
	std::copy(init.begin(), init.end(), this->mData.get());
}

template<typename T>
FlexArray<T>::FlexArray()
{
	this->mCapacity = this->mCapacity+1;
	this->mSize = 0;
	this->mData = std::make_unique<T[]>(this->mCapacity);
}

template<typename T>
void FlexArray<T>::push_back(const T& data)
{
	if (this->mCapacity > this->mSize)
	{
		this->mData[mSize++] = data;
	}
	else
	{
		std::unique_ptr<T[]> newData = std::make_unique<T[]>(this->mCapacity + 1);
		memcpy(newData.get(), this->mData.get(), sizeof(T) * this->mSize);
		newData[mSize++] = data;
		this->mData = std::move(newData);
	}
}

template<typename T>
void FlexArray<T>::pop_back()
{
	if (this->mSize > 0)
		this->mSize--;
}

template<typename T>
void FlexArray<T>::reserve(const size_t& capacity)
{
	size_t newCapacity = this->mCapacity + capacity;
	std::unique_ptr<T[]> newData = std::make_unique<T[]>(newCapacity);
	memcpy(newData.get(), this->mData.get(), sizeof(T) * this->mSize);
	this->mData = std::move(newData);
	this->mCapacity += capacity;
}


template<typename T>
T& FlexArray<T>::operator[](const size_t& index)const
{
	if (this->mSize > 0 && index < this->mSize)
		return this->mData[index];
	else
	{
		throw std::out_of_range("Index out of range");
	}
}

template<typename T>
size_t FlexArray<T>::size()const
{
	return this->mSize;
}

template<typename T>
size_t FlexArray<T>::capacity()const
{
	return this->mCapacity;
}


template<typename T>
void FlexArray<T>::erase(const size_t& index)
{
	if (this->mSize <= 0) return;
	for (size_t i = index + 1; i < this->mSize; i++)
	{
		this->mData[i-1] = this->mData[i];
	}
	this->mSize--;
}

template<typename T>
void FlexArray<T>::erase(const size_t& Lb,const size_t& Rb)
{
	if (Lb > Rb)return;
	if (Lb < 0 || Rb >= this->mSize)return;
	std::unique_ptr<T[]> newData = std::make_unique<T[]>(this->mCapacity);
	for (size_t i = 0,k = 0; i < this->mSize; i++)
	{
		if (i >= Lb && i <= Rb)continue;
		else newData[k++] = this->mData[i];
	}
	this->mData = std::move(newData);
	this->mSize -= (Rb - Lb + 1);
}

template<typename T>
void FlexArray<T>::resize(const size_t& capacity,const int& value)
{
	std::unique_ptr<T[]> newData = std::make_unique<T[]>(capacity);
	for (size_t i = 0; i < capacity; i++)
		newData[i] = value;
	this->mCapacity = capacity;
	this->mSize = capacity;
	this->mData = move(newData);
}

template<typename T>
size_t FlexArray<T>::find(const int& value)const
{
	if (this->mSize <= 0) return NULL;
	for (size_t i = 0; i < this->mSize; i++)
	{
		if (this->mData[i] == value)return i;
		else continue;
	}
	return NULL;
}

template<typename T>
T* FlexArray<T>::begin()const 
{
	if (this->mSize > 0)
	{
		return &(this->mData[0]);
	}
	else return nullptr;
}

template<typename T>
T* FlexArray<T>::end()const
{
	if (this->mSize > 0)
	{
		return &(this->mData[this->mSize]);
	}
	else return nullptr;
}

template<typename T>
void FlexArray<T>::operator=(FlexArray<T>& fa)
{
	this->mSize = fa.size();
	this->mCapacity = fa.capacity();
	std::unique_ptr<T[]> newData = std::make_unique<T[]>(fa.capacity());
	for (size_t i = 0; i < fa.size(); i++)
	{
		newData[i] = fa[i];
	}
	this->mData = std::move(newData);
}

template<typename T>
void FlexArray<T>::clear()
{
	this->mData.reset();
	this->mSize = 0;
	this->mCapacity = 0;
}

template<typename T>
bool FlexArray<T>::empty()const
{
	if (this->mSize == 0) return true;
	else return false;
}

template<typename T>
bool FlexArray<T>::operator==(const FlexArray<T>& fa)const
{
	if (this->mSize != fa.size()) return false;
	if (this->mSize == 0) return true;
	for (size_t i = 0; i < this->mSize; i++)
	{
		if (this->mData[i] == fa[i]) continue;
		else return false;
	}
	return true;
}

