//
//  FileHelper.m
//  KissGirl
//  
//

#import "FileHelper.h"

@implementation FileHelper

+ (NSString *) getLibraryPath
{
    return [NSSearchPathForDirectoriesInDomains(NSLibraryDirectory,NSUserDomainMask,YES) objectAtIndex:0];
}

@end

