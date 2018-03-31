/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 00:22:21 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 15:16:56 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _OBJECT_HPP_
# define _OBJECT_HPP_

class Object {

	public:
		Object( void );
		Object( int x, int y, int hp);
		Object( Object const &src);
		~Object( void );

		Object &operator=(Object const &src);
		const int		*getPos( void ) const;
		int		getHp( void ) const;
		int		takeDamage(int damage);

	protected:
		int		_pos[2];
		int		_hp;

};

#endif
