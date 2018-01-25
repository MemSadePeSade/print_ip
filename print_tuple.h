#pragma once
#include <iostream>

using namespace std;

template <typename Tup, std::size_t N>
struct print_tuple {
	static void _(const Tup &t, ostream &o = cout) {
		print_tuple<Tup, N - 1>::_(t, o);
		o << "." << get<N - 1>(t);
	}
};

template <typename Tup>
struct print_tuple<Tup, 1> {
	static void _(const Tup &t, ostream &o = cout) { o << get<0>(t); }
};

template <typename Tup>
struct print_tuple<Tup, 0> {
	static void _(const Tup &, ostream &) {}
};

template <typename ...Ts>
ostream& operator<< (ostream &o, const tuple<Ts...> &t) 
{
	print_tuple<tuple<Ts...>, sizeof...(Ts)>::_(t, o);
	return o;
}

