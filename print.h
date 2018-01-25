#pragma once

#include <type_traits>
#include <iostream>
#include <tuple>
#include <vector>
#include <list>
#include <iterator>

#include"print_tuple.h"

/// print tuple
template<typename ...Args>
struct all_type_identical :std::true_type {};

template<typename T, typename U, typename ...Args>
struct all_type_identical<T,U,Args...> : std::false_type {};

template<typename T,typename ...Args>
struct all_type_identical<T,T,Args...> : all_type_identical<Args...> {};

template<class... Types>
typename std::enable_if<all_type_identical<Types...>::value, void>::type
print(const std::tuple<Types...>& t, std::ostream& os)
{
	std::cout <<  t  << std::endl;
}

/// integral type
template<typename T>
typename std::enable_if<std::is_integral<T>::value,void>::type  
print(const T& ip, std::ostream& os)
{ 
	unsigned char* p = (unsigned char*)&ip+ sizeof(T)-1;
	for (size_t i = 0; i<(sizeof(T)-1); i++)
		os << ((unsigned)*p--) << ".";
	os << (unsigned)*p;
	os << std::endl;
};

/// print container
template <typename T>       struct is_stl_container :std::false_type {};
template <>                 struct is_stl_container<std::string> :std::true_type {};
template <typename... Args> struct is_stl_container<std::vector <Args...>> :std::true_type {};
template <typename... Args> struct is_stl_container<std::list   <Args...>> :std::true_type {};

template<typename T>
typename std::enable_if<is_stl_container<T>::value,void>::type 
print(const T& ip, std::ostream& os)
{
	std::ostream_iterator<typename T::value_type> out_it(os, ".");
	std::copy(ip.begin(), ip.end(), out_it);
	os << '\b';  os << " "; // delete last "."
	os << std::endl;
};

/// print string
template<>
void print(const std::string& ip, std::ostream& os)
{
	std::ostream_iterator<char> out_it(os, "");
	std::copy(ip.begin(), ip.end(), out_it);
	os << std::endl;
}

