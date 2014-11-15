//
//  MPEG4BoxCommon.h
//  BDMP4Utils
//
//  Created by wangwei34 on 14-2-7.
//
//

#ifndef BDMP4Utils_MPEG4BoxCommon_h
#define BDMP4Utils_MPEG4BoxCommon_h

#import <Foundation/Foundation.h>

/*
 *  data-type definition
 */
#define BYTE8       char
#define PBYTE8      BYTE8*
#define PVOID       void*
#define LONG64      long long

/*
 *  box-type definition
 */
extern NSString * const MPEG4BoxType_ftyp;
extern NSString * const MPEG4BoxType_moov;
extern NSString * const MPEG4BoxType_mvhd;
extern NSString * const MPEG4BoxType_trak;
extern NSString * const MPEG4BoxType_mdia;
extern NSString * const MPEG4BoxType_minf;
extern NSString * const MPEG4BoxType_stbl;
extern NSString * const MPEG4BoxType_tkhd;
extern NSString * const MPEG4BoxType_hdlr;
extern NSString * const MPEG4BoxType_stsz;
extern NSString * const MPEG4BoxType_stco;
extern NSString * const MPEG4BoxType_stts;
extern NSString * const MPEG4BoxType_stss;
extern NSString * const MPEG4BoxType_mdat;
extern NSString * const MPEG4BoxType_ctts;
extern NSString * const MPEG4BoxType_stsc;
extern NSString * const MPEG4BoxType_mdhd;
extern NSString * const MPEG4BoxType_edts;
extern NSString * const MPEG4BoxType_co64;

/*
 *  utility for BYTE8
 */
#define LEN_OF_BYTES_4_UINT32       4
#define LEN_OF_BYTES_4_UINT64       8

UInt32 Byte8ToUInt32(const PBYTE8 raw, LONG64 sizeOfRaw);           // big-endian bytes ==> UInt32
BOOL UInt32ToByte8(UInt32 value, PBYTE8 dest, LONG64 sizeOfDest);   // UInt32 ==> big-endian bytes
UInt32 NSStringToByte8(NSString *src, UInt32 len2copy, PBYTE8 dest, UInt32 sizeOfDest);
BOOL Byte8IsEqualToFourCC(const PBYTE8 raw, BYTE8 fcc1, BYTE8 fcc2, BYTE8 fcc3, BYTE8 fcc4);
extern UInt64 Byte8ToUInt64(const PBYTE8 raw);
extern BOOL UInt64ToByte8(UInt64 value, PBYTE8 dest, LONG64 sizeOfDest);

/*
 *  field-length definition
 */
#define LEN_BOX_SIZE        LEN_OF_BYTES_4_UINT32
#define LEN_BOX_TYPE        4
#define LEN_BOX_HEADER      ([self header_size])
#define LEN_BOX_EXT_SIZE    LEN_OF_BYTES_4_UINT64
#define LEN_BOX_EXT_HEADER      (LEN_BOX_SIZE + LEN_BOX_TYPE + LEN_BOX_EXT_SIZE)
#define LEN_BOX_NORMAL_HEADER   (LEN_BOX_SIZE + LEN_BOX_TYPE)

#endif
