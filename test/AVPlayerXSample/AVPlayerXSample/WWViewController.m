//
//  WWViewController.m
//  AVPlayerXSample
//
//  Created by Wayne W on 14-11-15.
//
//

#import "WWViewController.h"
#import "WWAVPlayerView.h"
#import <AVFoundation/AVPlayerItem.h>
#import <WWVideoKit4iOS/HTTPFragMP4Task.h>

@interface WWViewController ()
@property (nonatomic, strong) WWAVPlayerView *playerView;
@property (nonatomic, strong) BDHTTPFragMP4Task *current_task;
@end

@implementation WWViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    // player-view
    self.playerView = [[WWAVPlayerView alloc] initWithFrame:self.view.bounds];
    self.playerView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    [self.view addSubview:self.playerView];
    
    // button for flv
    {
        UIButton *playbtn = [UIButton buttonWithType:UIButtonTypeCustom];
        [playbtn setTitle:@"Play FLV" forState:UIControlStateNormal];
        playbtn.frame = CGRectMake(20, 20, 100, 30);
        playbtn.autoresizingMask = UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleBottomMargin;
        playbtn.backgroundColor = [UIColor grayColor];
        
        [playbtn addTarget:self
                    action:@selector(_playSampleFLV)
          forControlEvents:UIControlEventTouchUpInside];
        
        [self.view addSubview:playbtn];
    }
    
    // button for fragmented mp4
    {
        UIButton *playbtn = [UIButton buttonWithType:UIButtonTypeCustom];
        [playbtn setTitle:@"Play Frag-MP4" forState:UIControlStateNormal];
        playbtn.frame = CGRectMake(130, 20, 150, 30);
        playbtn.autoresizingMask = UIViewAutoresizingFlexibleRightMargin | UIViewAutoresizingFlexibleBottomMargin;
        playbtn.backgroundColor = [UIColor grayColor];
        
        [playbtn addTarget:self
                    action:@selector(_playSampleFragMP4)
          forControlEvents:UIControlEventTouchUpInside];
        
        [self.view addSubview:playbtn];
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark private
- (void)_doPlay:(NSArray*)playList
{
    [BDHTTPFragMP4Task stopTask:self.current_task];
    self.current_task = nil;
    
    [BDHTTPFragMP4Task createFragMP4Task4files:playList
                                      callback:^(BDHTTPFragMP4Task *task, BOOL isSucceed)
     {
         NSString *url = [BDHTTPFragMP4Task playURL4task:task supportRemotePlayer:NO];
         AVPlayerItem *item = [AVPlayerItem playerItemWithURL:[NSURL URLWithString:url]];
         AVPlayer *player = [AVPlayer playerWithPlayerItem:item];
         
         [self.playerView setPlayer:player];
         self.current_task = task;
         
         [player play];
     }];
}

- (void)_playSampleFLV
{
    NSString *path4flv = [[NSBundle mainBundle] pathForResource:@"000" ofType:@"flv"];
    NSArray *playList = [NSArray arrayWithObjects:path4flv, nil];
    
    [self _doPlay:playList];
}

- (void)_playSampleFragMP4
{
    NSString *path0 = [[NSBundle mainBundle] pathForResource:@"0" ofType:@"mp4"];
    NSString *path1 = [[NSBundle mainBundle] pathForResource:@"1" ofType:@"mp4"];
    NSString *path2 = [[NSBundle mainBundle] pathForResource:@"2" ofType:@"mp4"];
    
    NSArray *playList = [NSArray arrayWithObjects:path0, path1, path2, nil];
    
    [self _doPlay:playList];
}

@end
