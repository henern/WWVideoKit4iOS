//
//  HTTPFragMP4Task.h
//  BDMP4Utils
//
//  Created by wangwei34 on 14-3-6.
//
//

#import <Foundation/Foundation.h>

@class BDHTTPFragMP4Task;
typedef void (^BDHTTPFragMP4Task_block_t)(BDHTTPFragMP4Task *task, BOOL isSucceed);

// BDHTTPFragMP4Task
@interface BDHTTPFragMP4Task : NSObject

@property (nonatomic, strong) id fragMP4;

+ (BDHTTPFragMP4Task*)createFragMP4Task4files:(NSArray*)files callback:(BDHTTPFragMP4Task_block_t)callback;
+ (BDHTTPFragMP4Task*)createFragMP4Task4urls:(NSArray*)urls callback:(BDHTTPFragMP4Task_block_t)callback;

+ (NSString*)playURL4task:(BDHTTPFragMP4Task*)task supportRemotePlayer:(BOOL)supportRemotePlayer;
+ (BOOL)stopTask:(BDHTTPFragMP4Task*)task;

@end

// category for HTTPConnection
@interface BDHTTPFragMP4Task (HTTPConnection)
+ (BDHTTPFragMP4Task*)task4url:(NSString*)url;
@end