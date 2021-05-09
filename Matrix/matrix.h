﻿/* OSL/Matrix/matrix.h
 *
 * Copyright (C) 2021 YuminZhan
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with this
 * program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once
#ifdef MATRIX_EXPORTS
	#define MATRIX_API __declspec(dllexport)
#else
	#define MATRIX_API __declspec(dllimport)
	#pragma	comment(lib, "matrix")
#endif

#include <iostream>
#include "../Number/number.h"

namespace osl {
	template<class elm = double>
	class MATRIX_API element {
	public:
		int row, col;
		elm value;
		inline element();
		inline element(const element& origin);
		inline element(int row, int col, const elm& value);
	};

	typedef const void* c_ary;
	template<class elm = double>
	class MATRIX_API vector {
		typedef const vector& agm_vec;
		typedef const elm& agm_elm;
	public:
		// Constructors & Destructor
		vector(int n = 0, agm_elm value = 0.0);
		vector(agm_vec origin);
		vector(agm_vec origin, int begin, int end);
		vector(c_ary ary, int len);
		~vector();

		// Properties
		inline bool empty()const;
		inline int size()const;

		// Element
		inline elm& at(int lct)const;
		element<elm> MAX()const;
		element<elm> MIN()const;
		element<elm> absmax()const;
		element<elm> absmin()const;

		// Modifiers
		void cover(agm_elm value = 0);
		void cover(c_ary ary);
		void cover(agm_vec vec, int begin = 0);
		void insert(int lct, int n = 1, agm_elm value = 0.0);
		void insert(int lct, c_ary ary, int len);
		void insert(int lct, agm_vec vec);
		inline void append(int n = 1, agm_elm value = 0.0);
		inline void append(c_ary ary, int len);
		inline void append(agm_vec vec);
		void remove(int lct);
		void remove(int start, int end);
		inline void cutoff(int n);
		void add(agm_vec vec);
		void sub(agm_vec vec);
		void mul(agm_vec vec);
		void mul(agm_elm value);
		void div(agm_vec vec);
		void div(agm_elm value);

		// Operators
		inline elm& operator[](int lct)const;
		template <typename elm>
		friend MATRIX_API inline vector<elm> operator+(const vector<elm>& vec1, const vector<elm>& vec2);
		template <typename elm>
		friend MATRIX_API inline vector<elm> operator-(const vector<elm>& vec1, const vector<elm>& vec2);
		template <typename elm>
		friend MATRIX_API elm operator*(const vector<elm>& vec1, const vector<elm>& vec2);
		template <typename elm>
		friend MATRIX_API std::ostream& operator<<(std::ostream& os, const vector<elm>& vec);
		template <typename elm>
		friend MATRIX_API std::istream& operator>>(std::istream& is, vector<elm>& vec);

		// Practical Tools
		void print(c_str separator = " ", char end = '\n');

	private:
		int _size;
		elm* pointer;
	};

	typedef const void** c_rary;
	template<class elm = double>
	class MATRIX_API matrix {
		typedef const matrix& agm_mat;
		typedef const elm& agm_elm;
		typedef const vector<elm>& agm_vec;

	public:
		matrix(int nrow = 0, int ncol = 0, agm_elm value = 0.0);
		matrix(agm_mat origin);
		matrix(agm_mat origin, int start_row, int end_row, int start_col, int end_col);
		matrix(agm_vec vec, int n = 1);
		matrix(c_ary ary, int ncol, int n = 1);
		matrix(c_rary rary, int nrow, int ncol);
		//matrix(const char* file, int nrow, int ncol);
		~matrix();

		// Properties
		inline bool empty()const;
		inline int nrow()const;
		inline int ncol()const;

		// Element
		elm& at(int row, int col)const;
		vector<elm> at(int row)const;
		element<elm> MAX()const;
		element<elm> MIN()const;
		element<elm> absmax()const;
		element<elm> absmin()const;

		//inline elm* operator[](int i);
		//typedef int position;
		//inline void insert(int lct_i, int lct_j,
		//	int inst_rows = 1U, int inst_cols = 0U, elm fillnumber = 0.0);
		//void insert_rows(int lct_i, int inst_rows = 1U, elm fillnumber = 0.0);
		//void insert_cols(int lct_j, int inst_cols = 1U, elm fillnumber = 0.0);
		//inline void remove(int lct_i, int lct_j, int rmv_rows = 1, int rmv_cols = 0);
		//void remove_rows(int lct_i, int rmv_rows = 1);
		//void remove_cols(int lct_j, int rmv_cols = 1);
		//void print(int start_row = 0U, int start_col = 0U,
		//	int print_nrows = 0U, int print_sizes = 0U);

		//void add(agm_mat matrix);
		//void subtract(agm_mat matrix);
		//void multiply(agm_mat matrix);
		//void invert();

	private:
		int _nrow, _ncol;
		vector<elm>* pointer;
		//inline void empty_matrix(bool showtip = NO);
		//void normal_matrix(int nrows, int ncols, elm num = 0.0);
		//inline void expmatrix(int nrows, int ncols, agm_mat origin,
		//	int start_row, int start_col, elm num = 0.0);
		//void max_and_min();
	};
	
	namespace exc {
		class MATRIX_API vector {
		public:
			const unsigned code;
			c_str const discription;
			static c_str overview_list[];
			inline vector(unsigned code, c_str discription);
			inline c_str overview()const;
		};

		class MATRIX_API matrix {
		public:
			const unsigned code;
			c_str const discription;
			static c_str overview_list[];
			inline matrix(unsigned code, c_str discription);
			inline c_str overview()const;
		};
	}
}