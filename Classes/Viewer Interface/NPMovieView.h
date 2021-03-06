/**
 * NPMovieView.h
 * NicePlayer
 */

/* ***** BEGIN LICENSE BLOCK *****
* Version: MPL 1.1/GPL 2.0/LGPL 2.1
*
* The contents of this file are subject to the Mozilla Public License Version
* 1.1 (the "License"); you may not use this file except in compliance with
* the License. You may obtain a copy of the License at
* http://www.mozilla.org/MPL/
*
* Software distributed under the License is distributed on an "AS IS" basis,
* WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
* for the specific language governing rights and limitations under the
* License.
*
* The Original Code is NicePlayer.
*
* The Initial Developer of the Original Code is
* James Tuley & Robert Chin.
* Portions created by the Initial Developer are Copyright (C) 2004-2005
* the Initial Developer. All Rights Reserved.
*
* Contributor(s):
*           Robert Chin <robert@osiris.laya.com> (NicePlayer Author)
*           James Tuley <jay+nicesource@tuley.name> (NicePlayer Author)
*
* Alternatively, the contents of this file may be used under the terms of
* either the GNU General Public License Version 2 or later (the "GPL"), or
* the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
* in which case the provisions of the GPL or the LGPL are applicable instead
* of those above. If you wish to allow use of your version of this file only
* under the terms of either the GPL or the LGPL, and not to allow others to
* use your version of this file under the terms of the MPL, indicate your
* decision by deleting the provisions above and replace them with the notice
* and other provisions required by the GPL or the LGPL. If you do not delete
* the provisions above, a recipient may use your version of this file under
* the terms of any one of the MPL, the GPL or the LGPL.
*
* ***** END LICENSE BLOCK ***** */



#import <Cocoa/Cocoa.h>
#import "Preferences.h"
#import <AppKit/AppKit.h>
#import "NPMovieProtocol.h"

@class ControlPlay;
@class NiceWindow;

@interface NPMovieView : NSView {
    NSURL *openedURL;
    id trueMovieView;
    id contextMenu;
    id title;
	float internalVolume;
    
    NSTrackingRectTag trackingRect;
    
    NSString *fileType;
    NSString *fileExtension;

    BOOL dragButton;
    BOOL wasPlaying;
    BOOL mouseEntered;
}

+(id)blankImage;

-(BOOL)openURL:(NSURL *)url;
-(void)switchToPlugin:(id)sender;
-(void)switchToPluginClass:(Class)aClass;
-(BOOL)loadMovie;
-(void)closeReopen;
-(void)close;

-(void)mouseDoubleClick:(NSEvent *)anEvent;

-(void)start;
-(void)stop;
-(void)ffStart;
-(void)ffDo;
-(void)ffDo:(int)aSeconds;
-(void)ffEnd;
-(void)rrStart;
-(void)rrDo;
-(void)rrDo:(int)aSeconds;
-(void)rrEnd;

-(void)toggleMute;
-(void)incrementVolume;
-(void)decrementVolume;
-(void)setVolume:(float)aVolume;
-(float)volume;
-(float)volumeWithMute;

-(NSArray*)chapters;
-(id)currentChapter;
-(void)gotoChapter:(int)anIndex;

-(BOOL)isPlaying;
-(BOOL)wasPlaying;
-(void)playPrevMovie;
-(void)playNextMovie;
-(void)finalProxyViewLoad;

-(void)showOverLayVolume;
-(void)smartHideMouseOverOverlays;
-(void)timedHideOverlayWithSelector:(NSString *)aStringSelector;
-(void)cancelPreviousPerformRequestsWithSelector:(NSString *)aStringSelector;
-(void)hideOverlayWithSelector:(NSString *)aStringSelector;

-(Class)currentPluginClass;
-(id)myMenu;
-(id)menuTitle;
-(id)pluginMenu;
-(id)contextualMenu;
-(void)rebuildMenu;

-(BOOL)canAnimateResize;
-(void)scrollWheelResize:(float)delta;
-(void)scrollWheelAdjustVolume:(float)delta;
-(void)performScrollerForPref:(enum scrollWheelMoviePrefValues)pref event:(NSEvent *)anEvent delta:(float)delta;

#pragma mark -
#pragma mark Calculations

-(double)scrubLocation:(id)sender;
-(NSSize)naturalSize;
-(BOOL)hasEnded:(id)sender;
-(BOOL)muted;
-(void)setMuted:(BOOL)aBool;
-(double)currentMovieTime;
-(double)currentMovieFrameRate;
-(void)setCurrentMovieTime:(double)aDouble;
-(double)totalTime;
-(double)perecntLoaded;
-(void)drawMovieFrame;
-(void)setLoopMode:(NSQTMovieLoopMode)flag;

@end
