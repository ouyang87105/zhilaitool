#ifndef __LICENSE_H__
#define __LICENSE_H__


#pragma pack (1)
typedef struct {
	char app_id[64];
	char app_secret[64];
	char serial_id[64];
	char lic_path[64];
} RS_LIC_INFO;

typedef struct {
	unsigned char rep_ok;
	
	char cpu_id[32];
	char vender_id[32];
	
	RS_LIC_INFO face;
} RS_REP_LIC_STATUS;
#pragma pack ()


#endif //__LICENSE_H__