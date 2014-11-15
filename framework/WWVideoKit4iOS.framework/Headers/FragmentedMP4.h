//
//  FragmentedMP4.h
//  BDMP4Utils
//
//  Created by wangwei34 on 14-2-13.
//
//

#import <Foundation/Foundation.h>
#import "MPEG4MergedLayout.h"

@class BDFragmentedMP4;
@protocol BDFragmentedMP4Delegate <NSObject>
- (void)fragmentedMP4Prepared:(BDFragmentedMP4*)fragMP4;
- (void)fragmentedMP4:(BDFragmentedMP4*)fragMP4 failedWithErr:(NSInteger)errorCode;
@end

@interface BDFragmentedMP4 : NSObject <BDMPEG4MergedLayout>

@property (nonatomic, strong, readonly) NSArray *mp4s;
@property (nonatomic, strong, readonly) NSDictionary *mergers;

@property (nonatomic, weak) id<BDFragmentedMP4Delegate> delegate;

- (id)initWithFiles:(NSArray *)files;   // files can be local-path or url
                                        // all invalid mp4 would be skipped
- (BOOL)prepareAsync;
- (UInt32)writeTo:(NSOutputStream*)output atOffset:(UInt32)offset maxLength:(UInt32)maxLen;

@end

@interface BDFragmentedMP4 (HTTP)

- (NSString*)contentType;
- (UInt64)contentLength;

@end