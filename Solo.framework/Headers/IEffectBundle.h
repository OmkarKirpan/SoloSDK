//
//  IEffectBundle.h
//  SoloFramework
//
//  Created by Pavel Yurchenko on 2/22/17.
//  Copyright © 2017 Camerai. All rights reserved.
//
//  Please contact us at bugs@camerai.co if you have problems
//

#if ORYOL_MACOS
#import <AppKit/AppKit.h>
#else
#import <UIKit/UIKit.h>
#endif

typedef void (^SuccessBlock)(BOOL success);
typedef void (^PogressBlock)(CGFloat percentage);

/*!
    @protocol IEffectBundle
    @brief It's a protocol for accessing effect bundle features
 */

@protocol IEffectBundle <NSObject>

/*!
    @brief YES if bundle is ready to use locally
 */
@property (nonatomic, readonly) BOOL isReady;

/*!
    @brief Add path to list to ignore caches for
 */
- (void)resetCachesForURL:(NSURL*)url;

@end
