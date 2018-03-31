/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missile.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduwer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:54:30 by eduwer            #+#    #+#             */
/*   Updated: 2018/03/31 18:04:02 by eduwer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILE_HPP
# define MISSILE_HPP

#include "AObject.hpp"

class Missile : public AObject {

	public:
		Missile( void );
		Missile( Missile const &src );
		~Missile( void );

		virtual void	update( void );
		void			setPos( int x, int y );


};

# endif
