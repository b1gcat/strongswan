/**
 * @file ihe_sa_id.h
 * 
 * @brief Class for identification of an IKE_SA
 * 
 */

/*
 * Copyright (C) 2005 Jan Hutter, Martin Willi
 * Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */


#ifndef IKE_SA_ID_H_
#define IKE_SA_ID_H_

#include "types.h"

/**
 * @brief This class is used to identify an IKE_SA.
 * 
 * An IKE_SA is identified by its initiator and responder spi's.
 * Additionaly it contains the role of the actual running IKEv2-Daemon 
 * for the specific IKE_SA.
 */
typedef struct ike_sa_id_s ike_sa_id_t;

struct ike_sa_id_s { 	

	/**
	 * @brief Sets the SPI of the responder.
	 * 
	 * This function is called when a request or reply of a IKE_SA_INIT is received.
	 * 
	 * @param this ike_sa_id object
	 * @param responder_spi SPI of responder to set
	 * @return SUCCESSFUL if succeeded, FAILED otherwise
	 */
	status_t (*set_responder_spi) (ike_sa_id_t *this, spi_t responder_spi);

	/**
	 * @brief Returns TRUE if the initiator spi is set (not zero)
	 * 
	 * @param this ike_sa_id object
	 * @return TRUE if the initiator spi is set, FALSE otherwise
	 */
	bool (*initiator_spi_is_set) (ike_sa_id_t *this);

	/**
	 * @brief Returns TRUE if the responder spi is set (not zero)
	 * 
	 * @param this ike_sa_id object
	 * @return TRUE if the responder spi is set, FALSE otherwise
	 */
	bool (*responder_spi_is_set) (ike_sa_id_t *this);
	
	/**
	 * @brief Check if two ike_sa_ids are equal
	 * 
	 * @param this ike_sa_id object
 	 * @param this other ike_sa_id object to check if equal
 	 * @param are_equal is set to TRUE, if given ike_sa_ids are equal, FALSE otherwise
	 * @return SUCCESSFUL if succeeded, FAILED otherwise
	 */
	status_t (*equals) (ike_sa_id_t *this,ike_sa_id_t *other, bool *are_equal);	

	/**
	 * @brief Destroys a ike_sa_id object
	 * 
	 * @param this ike_sa_id object
	 * @return SUCCESSFUL if succeeded, FAILED otherwise
	 */
	status_t (*destroy) (ike_sa_id_t *this);
};

/**
 * Creates an ike_sa_id_t-object with specific spi's and defined role
 * 
 * @warning The initiator SPI and role is not changeable after initiating a ike_sa_id-object 
 */
ike_sa_id_t * ike_sa_id_create(spi_t initiator_spi, spi_t responder_spi,ike_sa_role_t role);

#endif /*IKE_SA_ID_H_*/
