//
//  MPEG4Box.h
//  BDMP4Utils
//
//  Created by wangwei34 on 14-2-7.
//
//

#import <Foundation/Foundation.h>
#import "MPEG4BoxCommon.h"
#import "BDInputStream.h"

typedef enum
{
    MPEG4Box_VERSION_0          = 0,
    MPEG4Box_VERSION_Default    = MPEG4Box_VERSION_0,
    MPEG4Box_VERSION_1          = 1,
    
    // more?
    
    MPEG4Box_VERSION_MAX,
}MPEG4Box_VERSION;

typedef enum
{
    MPEG4Box_PARSER_OPTION_UNKNOWN          = 0,
    
    MPEG4Box_PARSER_OPTION_SKIP_CONTENT     = 1,
    MPEG4Box_PARSER_OPTION_DEFAULT          = MPEG4Box_PARSER_OPTION_SKIP_CONTENT,
    MPEG4Box_PARSER_OPTION_COPY_CONTENT     = 2,
    MPEG4Box_PARSER_OPTION_NONE             = 3,
    
    MPEG4Box_PARSER_OPTION_MAX,
}MPEG4Box_PARSER_OPTION;

@interface BDMPEG4Box : NSObject

@property (nonatomic, readonly, strong) NSString *type;         // ftyp, moov, etc.
@property (nonatomic, readonly, assign) UInt32 total_size;      // box size (header + content), or 1
@property (nonatomic, readonly, assign) UInt32 offset;          // offset of box (i.e. offset of header)
@property (nonatomic, readonly, assign) UInt32 contentSize;     // size without header
@property (nonatomic, readonly, assign) UInt64 extend_size;
@property (nonatomic, readonly, assign) UInt32 header_size;

// writable properties for its parent 
@property (nonatomic, weak) BDMPEG4Box *parent;

// type+size+offset MUST be ready when initialization
- (id)initWithType:(NSString*)type size:(UInt32)size offset:(UInt32)offset extSize:(UInt64)extend_size;

- (UInt32)size;                 // return total_size, or extend_size if total_size is 1
- (MPEG4Box_VERSION)version;    // version
- (NSString*)tag;               // unique identifier
- (NSDictionary*)subboxes;      // NOTE: by default, it's nil. check the sub-class for more details.

// NOTE: all sub-class MUST call this method first!
- (BOOL)parseStream:(id<BDInputStream>)raw
         alreadyEnd:(BOOL*)alreadyEnd;

- (BOOL)willJoinGroup:(NSDictionary*)boxes;     // NOTE: called when this box is accepted by a file
- (NSData*)copyRawContent;                      // make a memory copy of content
- (UInt32)writeContentTo:(NSOutputStream*)output;

// utils APIs
+ (BDMPEG4Box*)box4rawStream:(id<BDInputStream>)stream;

@end

@interface BDMPEG4Box (Private)

- (id<BDInputStream>)_input;
- (MPEG4Box_PARSER_OPTION)_option4parsing;

@end