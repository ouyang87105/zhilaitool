#ifndef __RS_DATA_H__
#define __RS_DATA_H__


#define TCP_SERVER_ADDR "192.168.32.3"
#define TCP_SERVER_PORT 10051


typedef enum {
	RS_CMD_TEST = 0x00,
	RS_CMD_PING = 0x10,
	RS_CMD_VERSION = 0x11,
	RS_CMD_MODE = 0x12,
	RS_CMD_START = 0x13,
	RS_CMD_STOP = 0x14,
	RS_CMD_FW_PREPARE = 0x15,
	RS_CMD_FW_DATA = 0x16,
	RS_CMD_FW_UPDATE = 0x17,
	RS_CMD_REBOOT = 0x1b,
	RS_CMD_SET_SN = 0x1c,
	RS_CMD_GET_SN = 0x1d,
	RS_CMD_LIC_INFO = 0x1e,
	RS_CMD_FILE_OPEN = 0x1f,
	RS_CMD_FILE_DATA = 0x20,
	RS_CMD_FILE_DONE = 0x21,
	RS_CMD_FACE_PICTURE = 0x22,
	RS_CMD_TAKE_PHOTO = 0x24,
	RS_CMD_UVC_SOURCE = 0x25,
	RS_CMD_SLEEP = 0x26,
} RS_CMD_CODE;

typedef enum {
	RS_REPLY_TEST = 0x70,
	RS_REPLY_PING = 0x80,
	RS_REPLY_VERSION = 0x81,
	RS_REPLY_MODE = 0x82,
	RS_REPLY_START = 0x83,
	RS_REPLY_STOP = 0x84,
	RS_REPLY_FW_PREPARE = 0x85,
	RS_REPLY_FW_DATA = 0x86,
	RS_REPLY_FW_UPDATE = 0x87,
	RS_REPLY_REBOOT = 0x8b,
	RS_REPLY_SET_SN = 0x8c,
	RS_REPLY_GET_SN = 0x8d,
	RS_REPLY_LIC_INFO = 0x8e,
	RS_REPLY_FILE_OPEN = 0x8f,
	RS_REPLY_FILE_DATA = 0x90,
	RS_REPLY_FILE_DONE = 0x91,
	RS_REPLY_FACE_PICTURE = 0x92,
	RS_REPLY_TAKE_PHOTO = 0x94,
	RS_REPLY_UVC_SOURCE = 0x95,
	RS_REPLY_SLEEP = 0x96,
	
	RS_REPLY_FACE = 0xa0,
	RS_REPLY_PHOTO = 0xa1,
} RS_REPLY_CODE;


#define PING_REPLY "readsense server reply ping."
#define PICTURE_FORMAT_JPEG   "picture.jpeg"

#define HEAD_MAGIC "READSENSE"
#define MAGIC_SIZE (sizeof(HEAD_MAGIC) - 1)

#pragma pack (1)
typedef struct {
	unsigned char  magic[MAGIC_SIZE];
	unsigned char  version;
	unsigned char  id;
	unsigned char  cmdtype;
	unsigned int   bodysize;
} packet_head;

// uart 115200 8n1
#define UART_DATA_SIZE        (5 * 1024)

#define HEADSIZE              sizeof(packet_head)
#define INDEX_SIZE            sizeof(unsigned int)
#define DATA_SIZE             (150 * 1024)
#define BUFSIZE               (INDEX_SIZE + DATA_SIZE)

typedef struct {
	packet_head head;
	unsigned char buffer[BUFSIZE];
} rspacket;


// cmd
typedef struct {
	unsigned char mode;
} RS_SYS_CONTROL;

typedef struct {
	unsigned char type;
} RS_UPDATE_TYPE;

typedef struct {
	unsigned int index;
	unsigned char data[DATA_SIZE];
} RS_INDEX_DATA;

typedef struct {
	unsigned char md5[16];
} RS_CHKSUM_MD5;

typedef struct {
	unsigned char sn[16];
} RS_MODULE_SN;

typedef struct {
	char path[64];
} RS_FILE_PARA;

typedef struct {
	unsigned char data[BUFSIZE];
} RS_ONLY_DATA;

typedef struct {
	unsigned char recognition;
} RS_TAKE_PHOTO;

typedef struct {
	unsigned char source;
} RS_UVC_SOURCE;


//reply
typedef struct {
	unsigned char status[30];
} RS_PING_STATUS;

typedef struct {
	char kernel[10];
	char rootfs[10];
	char algo[10];
} RS_VERSION;

typedef struct {
	unsigned char rep_ok;
} RS_REP_ONLY_STATUS;

typedef struct {
	unsigned int index;
	unsigned char rep_ok;
} RS_REP_INDEX_STATUS;

#define RS_FACE_RECOGNITION_FEATURE_DIMENSION 512
typedef struct tag_RS_FACE_RECOGNITION_RESULT
{
	int fr_available_flag;
	float fr_feature[RS_FACE_RECOGNITION_FEATURE_DIMENSION];
} RS_FACE_RECOGNITION_RESULT;


//
typedef enum {
	SYS_MODE_UVC = 0,
	SYS_MODE_NORMAL,
	SYS_MODE_MAX,
} eworkmode;

typedef enum {
	TAKE_PHOTO_ONLY = 0,
	TAKE_PHOTO_RECO,
	TAKE_PHOTO_MAX,
} etakephoto;

typedef enum {
	UVC_SOURCE_NONE = 0,
	UVC_SOURCE_ISP = 3,
	UVC_SOURCE_CIF = 4,
	UVC_SOURCE_MAX,
} euvcsource;
#pragma pack ()


#endif