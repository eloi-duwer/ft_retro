/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Object.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 00:22:21 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 00:38:42 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _OBJECT_HPP_
# define _OBJECT_HPP_

class Object {

	public:
		Object( void );
		Object( Object &src);

		Object &operator=(Object const &src);
		int		*getPos( void ) const;
		int		getHp( void ) const;
		void	takeDamage(int damage);

	protected:
		int		_pos[2];
		float	_realPos[2];
		float	_direction[2];
		int		_hp;

};

#endif
