/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AObject.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 00:22:21 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 15:16:56 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _AObject_HPP_
# define _AObject_HPP_

class AObject {

	public:
		AObject( void );
		AObject( int x, int y, int hp);
		AObject( AObject const &src);
		~AObject( void );

		AObject &operator=(AObject const &src);
		const int		*getPos( void ) const;
		int		getHp( void ) const;
		int		takeDamage(int damage);
		virtual void update() = 0;

	protected:
		int		_pos[2];
		int		_hp;

};

#endif
