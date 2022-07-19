/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannouao <mannouao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:26:09 by mannouao          #+#    #+#             */
/*   Updated: 2022/07/19 11:18:10 by mannouao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MAP_HPP
# define MAP_HPP

# include "__tree.hpp"
# include "utility.hpp"
# include <memory>

namespace ft
{
	template<class _Key, class _Tp, class _Compare = std::less<_Key>,
			 class _Allocator = std::allocator<ft::pair<const _Key, _Tp> > >
	class map
	{
	public:
		typedef _Key									Key_type;
		typedef _Tp										mapped_type;
		typedef ft::pair<const Key_type, mapped_type>	value_type;
		typedef _Compare								key_compare;
		typedef _Allocator								allocator_type;

		class value_compare 
			: public std::binary_function<value_type, value_type, bool>
		{
			friend class map;
		protected:
			key_compare comp;

			value_compare(key_compare c) : comp(c) {}
		public:
			bool operator () (const value_type& __x, const value_type& __y) const
			{ return(comp(__x.first, __y.first)); }
		};
	private:
		typedef ft::tree<value_type, key_compare, allocator_type> tree_type;
		tree_type	__tree;
	public:
		typedef tree_type::reference				reference;
		typedef tree_type::const_reference			const_reference;
		typedef tree_type::pointer					pointer;
		typedef tree_type::const_pointer			const_pointer;
		typedef tree_type::difference_type			difference_type;
		typedef tree_type::size_type				size_type;

	};

} // ft

# endif