//
//  MPEG4File.h
//  BDMP4Utils
//
//  Created by wangwei34 on 14-2-8.
//
//

#import <Foundation/Foundation.h>
#import "MPEG4BoxCommon.h"
#import "MPEG4Box.h"
#import "BDInputStream.h"

extern const UInt32 MPEG4File_OK;   // looks like a good MP4, but not guarantee

// mp4 looks good
#define IS_MPEG4FILE_OK(f)          ((f).descriptor == MPEG4File_OK)

// callbacks for parsing
@class BDMPEG4File;
typedef BOOL (^MPEG4FileParsing_block_t) (BDMPEG4File *mp4file, BDMPEG4Box *box, BOOL *ignore);

// NOTE: BDMPEG4File, not thread-safe, blocking call, keep it running in a single worker-thread.
@interface BDMPEG4File : NSObject
{
    id<BDInputStream> _in_stream;
}

@property (nonatomic, readonly, strong) NSDictionary *boxes;
@property (nonatomic, readonly, strong) NSArray *boxes_seq;     // box序列，保持文件中的先后顺序
@property (nonatomic, copy) MPEG4FileParsing_block_t callback4parsing;  // be called in worker-thread!

// MPEG4File is responsible for the life-time of raw-data
- (BOOL)attach2stream:(id<BDInputStream>)raw;
- (BOOL)detach;

- (UInt32)descriptor;      // e.g. if (IS_MPEG4FILE_CORRUPTED(mp4file)) { ... }

@end
