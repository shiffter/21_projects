#include "s21_vector.h"

template <typename T> s21_vector<T>::s21_vector() : size_(0), capacity_(0), data_(nullptr) {}

template <typename T> s21_vector<T>::s21_vector(size_t length) : size_(length), capacity_(length) {
	data_ = new T[size_]{};
} 

template <typename T> s21_vector<T>::~s21_vector() { delete[] data_; }

template <typename T> s21_vector<T>::s21_vector(const s21_vector<T>& other) {
	size_ = other.size_;
	capacity_ = other.capacity_;
	data_ = new T[size_];
	memcpy(data_, other.data_, size_ * sizeof(T));
}

template <typename T> s21_vector<T>::s21_vector(const s21_vector<T>&& other) noexcept {
	size_ = other.size_;
	capacity_ = other.capacity_;
	data_ = new T[size_];
	memcpy(data_, other.data_, size_ * sizeof(T));
	other.size_ = 0;
	other.capacity_ = 0;
	delete[] other.data_;
	other.data = nullptr;
}

 




