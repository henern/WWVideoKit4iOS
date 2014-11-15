//
//  BDHTTPServerSingleton.h
//  BDVideoPlayerKit
//
//  Created by wangwei34 on 14-3-5.
//
//

#import <Foundation/Foundation.h>
#import "HTTPServer.h"

extern NSString * const BDHTTPServerSingletonStatusChangedNotification;

@interface BDHTTPServerSingleton : NSObject

@property (nonatomic, strong) NSString *folder;

+ (BDHTTPServerSingleton*)sharedInstance;

- (BOOL)launch4taskCtx:(id)taskCtx;
- (NSString*)playURL4path:(NSString*)urlPath supportRemotePlayer:(BOOL)supportRemotePlayer;
- (NSInteger)port;
- (BOOL)closeTask:(id)taskCtx;
- (void)restart;

- (BOOL)isActive;

@end
