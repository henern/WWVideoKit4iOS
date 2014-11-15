//
//  WWAVPlayerView.m
//  AVPlayerXSample
//
//  Created by Wayne W on 14-11-15.
//
//

#import "WWAVPlayerView.h"
#import <AVFoundation/AVFoundation.h>

@implementation WWAVPlayerView

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
    }
    return self;
}

+ (Class)layerClass
{
	return [AVPlayerLayer class];
}

- (AVPlayer*)player
{
	return [(AVPlayerLayer*)[self layer] player];
}

- (void)setPlayer:(AVPlayer*)player
{
	[(AVPlayerLayer*)[self layer] setPlayer:player];
}

@end
