//
//  BDInputStream.h
//  BDMP4Utils
//
//  Created by wangwei34 on 14-2-27.
//
//

#import <Foundation/Foundation.h>

@protocol BDInputStream <NSObject>

- (BOOL)open;       // should be executed in main thread
- (void)close;      // should be executed in main thread
- (BOOL)isOpened;

- (UInt64)size;     // size in byte
- (UInt64)offset;   // offset in byte
- (UInt64)remain;   // remain in byte

- (NSData*)readDataOfLen:(UInt32)len;       // read synchronously
- (BOOL)seekTo:(UInt32)offst;               // seek synchronously

@end

// factory to create BDInputStream instance
@interface BDInputStreamFactory : NSObject
+ (id<BDInputStream>)inputStream4file:(NSString *)pathOrUrl;
@end
