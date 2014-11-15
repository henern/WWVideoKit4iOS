//
//  BDFileInputStream.h
//  BDMP4Utils
//
//  Created by wangwei34 on 14-2-27.
//
//

#import <Foundation/Foundation.h>
#import "BDInputStream.h"

@interface BDFileInputStream : NSObject <BDInputStream>

- (id)initWithFilePath:(NSString*)localPath;

@end
