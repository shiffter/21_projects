#ifndef __S21_VECTOR_H__
#define __S21_VECTOR_H__

#include "../s21_containers.h"

#define t_vector (template <typename T> s21_vector<T>::s21_vector)


template <typename T>
class s21_vector {
	public:

		//ctor
		s21_vector();
		s21_vector(size_type);
		s21_vector(const s21_vector&);
		s21_vector(const s21_vector&&) noexcept;
		~s21_vector();

		//capacity
		bool empty();
		size_type size();
		size_type max_size();
		void reserve(size_type size);
		size_type capacity();
		void shrink_to_fit();
		
		//operators
		s21_vector& operator=(const s21_vector&);

		//helpers
		void print_vector();

	private:
		size_type size_;
		size_type capacity_;
		int* data_;
};

#endif
