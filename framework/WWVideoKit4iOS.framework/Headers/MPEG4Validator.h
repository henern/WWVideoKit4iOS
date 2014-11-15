//
//  MPEG4Validator.h
//  BDMP4Utils
//
//  Created by wangwei34 on 14-7-10.
//
//

#import <Foundation/Foundation.h>
#import "MPEG4File.h"

@interface BDMPEG4Validator : NSObject

// NOTE: you should call this in worker-thread!
+ (BDMPEG4Validator*)validator4path:(NSString*)path;

- (BOOL)isMP4;
- (BOOL)isCorrupted;

@end
