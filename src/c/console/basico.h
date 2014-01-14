/*
 * BASICO.H - Archivo de cabecera con definiciones básicas
 */

/* P R E P R O C E S S O R **************************************************/
#ifndef __BASICO_H
#    define __BASICO_H

#ifdef __cplusplus
extern "C" {
#endif

/* D E F I N E S  ***********************************************************/
#define TRUE 1
#define FALSE 0
#define ERR (-1)
#define EOS '\0'
#define YES 1
#define SI 1
#define NO 0
#define OK 0
#define ERROR (!OK)
#define ON 1
#define OFF 0

/* M A C R O S *************************************************************/
#define MK_WORD(HIBYTE, LOBYTE) (word)((HIBYTE<<8)+LOBYTE)
#define HI(WORDVAR) (byte)(WORDVAR>>8)
#define LO(WORDVAR) (byte)(WORDVAR)

/* T Y P E S ***************************************************************/
typedef int bits; /* Definición de bit para campos de bits */
typedef unsigned char byte; /* Improvisamos un byte (8 bits) */
typedef unsigned int word; /* Un word (2 bytes) (16 bits) */
typedef unsigned long dword; /* Un dword (4 bytes) (32 bits) */
typedef char bool; /* Boolean (TRUE/FALSE) */

#ifdef __cplusplus
}
#endif

#endif /* __BASICO_H */
/* E O F ********************************************************************/
