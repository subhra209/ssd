
#ifndef SSD_H
#define SSD_H

/*
*------------------------------------------------------------------------------
* ssd.h
*
*/

#include "config.h"
#include "board.h"
#include "typedefs.h"

/*
*------------------------------------------------------------------------------
* SSD - the Seven Segement Display structure. 
*------------------------------------------------------------------------------
*/

typedef struct _Field 
{

	UINT8	 ID;				// To Identify the field
	UINT8	 bufferIndex;		//Index of digit display buffer, corresponding to field data
	UINT8	 length;			//Field Length
	BOOL 	 blink;				// Blink Flag
	UINT8 	 dotIndex ;			//Values [0 - length -1, 0xFF]
}Field;


typedef struct _SSD
{
	Field    fields[MAX_FIELDS];   		// contains field information
	UINT8 	 buffer[2][MAX_DIGITS];		//stores the data going to be display
	UINT8 	 digitIndex ;				//to point next data in buffer
	UINT16	 blinkPeriod;	
}SSD;


/*------------------------------------------------------------------------------
Public Function declarations:
*------------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
*void  SSD_Init( )
*
* Function to initialize the digit display module
* 
* Initializes digit index.
* 
*Input :none
* return value: none.
* 
*------------------------------------------------------------------------------*/
void  SSD_Init( );


/*------------------------------------------------------------------------------
*BOOL  SSD_CreateField( UINT8 field_ID )
*
* Function to initialize the individual fields
* 
* Initializes starting address, length of respective field.
* 
*Input : the index number of the field
* return value: true.
* 
*------------------------------------------------------------------------------*/

BOOL SSD_CreateField(UINT8 field_ID, UINT8 bufferIndex, UINT8 length, BOOL blink );


/*------------------------------------------------------------------------------
*void SSD_UpdateField(filedno , *buffer);
*
* Function to update field content to in display buffer.
* 
* 
*Input : number of digits used in the application
* return value: none.
* 
*------------------------------------------------------------------------------*/
void SSD_UpdateField(UINT8 field_ID ,UINT8 *buffer);


/*------------------------------------------------------------------------------
*void update_field(filedno , *buffer);
*
* Function to update field content to in display buffer.
* 
* 
*Input : number of digits used in the application
* return value: none.
* 
*------------------------------------------------------------------------------*/

void SSD_UpdateFieldpartial(UINT8 field_ID , UINT8*buffer , UINT8 from ,UINT8 no_of_digit);

/*------------------------------------------------------------------------------
*BOOL SSD_DotOn(field_no , from , no of digit);
*
* Function to turn on dot in the field.
* 
* 
*Input : field number and number of digits in which dot has to be enabled
* return value: true.
* 
*------------------------------------------------------------------------------*/
BOOL SSD_DotOn(UINT8 field_ID , UINT8 from , UINT8 no_of_digit);


/*------------------------------------------------------------------------------
*BOOL dot_off(field_no , from , no of digit);
*
* Function to turn off dot in the field.
* 
* 
*Input : field number and number of digits in which dot has to be disabled
* return value: true.
* 
*------------------------------------------------------------------------------*/
BOOL dot_off(UINT8 field_ID , UINT8 from , UINT8 no_of_digit);


/*------------------------------------------------------------------------------
*  void SSD_BlinkOn( field_no, from, length )
*
* Function to turn off blinking feature
* 
* 
* Input : field number, from and  number of digits to be blinked.
* return value: none.
* 
*------------------------------------------------------------------------------*/
void SSD_BlinkOn( UINT8 field_ID , UINT8 from , UINT8 no_of_digit );





/*------------------------------------------------------------------------------
*  void blink_off(field_no )
*
* Function to turn off blinking feature
* 
* 
* Input : field number 
* return value: none.
* 
*------------------------------------------------------------------------------*/
void blink_off(UINT8 field_ID );


