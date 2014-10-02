/*! \file data_emelements.h
 *
 * \copyright (C) Copyright 2013 University of Antwerp (http://www.cosys-lab.be) and others.\n
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.\n
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * \author maarten.weyn@uantwerpen.be
 *
 * \brief The Data Elements of D7A
 */

#ifndef DATA_ELEMENTS_H_
#define DATA_ELEMENTS_H_


#define DA_PERMISSION_CODE_CTRL_ENCRYPTED	1 << 7
#define DA_PERMISSION_CODE_CTRL_RUNABLE		1 << 6
#define DA_PERMISSION_CODE_USER_READ		1 << 5
#define DA_PERMISSION_CODE_USER_WRITE		1 << 4
#define DA_PERMISSION_CODE_USER_RUN			1 << 3
#define DA_PERMISSION_CODE_GUEST_READ		1 << 2
#define DA_PERMISSION_CODE_GUEST_WRITE		1 << 1
#define DA_PERMISSION_CODE_GUEST_RUN		1
#define DA_PERMISSION_CODE_USER_MASK B00111000
#define DA_PERMISSION_CODE_GUEST_MASK B00000111
#define DA_PERMISSION_CODE_READ_MASK B00100100
#define DA_PERMISSION_CODE_WRITE_MASK B00010010
#define DA_PERMISSION_CODE_RUN_MASK B00001001


#define DA_NOTIFICATION_STORAGE_CLASS(VAL)		(VAL & 0x03)
#define DA_NOTIFICATION_COND					1 << 7
#define DA_NOTIFICATION_NOTIFY					1 << 6
#define DA_NOTIFICATION_ACCESS_WRITE			0 << 4
#define DA_NOTIFICATION_ACCESS_READ				1 << 4
#define DA_NOTIFICATION_ACCESS_LIST				2 << 4
#define DA_NOTIFICATION_ACCESS_ANY				3 << 4
#define DA_NOTIFICATION_QOS(VAL)				(VAL & 7)

typedef enum {
	DataElementStorageClassTransient = 0,	// The content is not kept in memory. It cannot be read back.
	DataElementStorageClassVolatile,		// The content is kept in a volatile memory of the device. It is accessible for read, and is lost on power off.
	DataElementStorageClassRestorable,		// The content is kept in a volatile memory of the device. It is accessible for read, and can be backed-up upon request in a permanent storage location. It is restored form the permanent location on device power on.
	DataElementStorageClassPermanent		// The content is kept in a permanent memory of the device. It is accessible for read.
} Data_Element_Storage_Class;


typedef struct
{
     uint8_t properties_3_file_id;
     uint8_t properties_2;
     uint8_t properties_1_storage_class;
     uint8_t properties_0_permissions;
     uint16_t length;
     uint16_t allocated_length;
} Data_Element_File_Header;



#endif /* DATA_ELEMENTS_H_ */
