#include "s21_vector.h"

template <typename T> 
s21_vector<T>& s21_vector<T>::operator=(const s21_vector<T>& other) {
	if (data_ != other.data_) {
		if (data_) {
			delete[] data_;
		}
		size_ = other.size_;
		capacity_ = other.capacity_;
		data_ = new T[other.size_];
		memcpy(data_, other.data_, sizeof(T) * size_);
	}
		return *this;
}
