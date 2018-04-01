/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AObject.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 00:22:21 by eduwer            #+#    #+#             */
/*   Updated: 2018/04/01 17:24:53 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AObject_HPP_
# define _AObject_HPP_

#include <string>

class AObject {

	public:
		AObject( int x = 1, int y = 1, int hp = 1, \
			std::string skinString = "^", \
			int objectSize = 1, int speed = 1);
		AObject( AObject const &src);
		~AObject( void );

		AObject &operator=(AObject const &src);
		const int		*getPos( void ) const;
		int		getHp( void ) const;
		int		takeDamage(int damage);
		virtual bool update(int keycode = 0) = 0;
		bool onCollision(AObject const & aobj);

	protected:
		int			_pos[2];
		int			_hp;
		int			_framesOfExistence;
		std::string	_skinString;
		int			_objectSize;
		int			_speed;
};

#endif
