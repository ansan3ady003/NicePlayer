/**
 * DVDPlayerView.h
 * NicePlayer
 */

#import <Cocoa/Cocoa.h>
#import "NPMovieProtocol.h"
#import "NPPluginView.h"

@interface DVDPlayerView : NPPluginView <NPMoviePlayer>
{
	NSURL *urlToOpen;
	BOOL isAspectRatioChanging;

	UInt32 cid;
}

-(void)previousChapter;
-(void)nextChapter;

-(id)titleMenu;
-(id)chapterMenu;
-(id)audioMenu;
-(id)angleMenu;
-(id)subPictureMenu;

-(void)gotoMainMenu;
@end