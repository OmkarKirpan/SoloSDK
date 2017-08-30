//
//  IEffectBundle.h
//  SoloFramework
//
//  Created by Pavel Yurchenko on 2/22/17.
//  Copyright © 2017 Tipit Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

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
 @brief YES if want to use effect file name for effect.name
 */
@property (nonatomic, assign) BOOL useEffectsFileName;

/*!
    @brief Call to make bundle ready for use locally
    @discussion If bundle is remote downloading and mapping starts. If it's compressed then just mapping is done
 
    @param progress Block that is called when portion of effect data is downloaded or decompressed
    @param completion Block that is called when bundle is ready to use
 */
- (void)makeReady:(PogressBlock)progress completion:(SuccessBlock)completion;


@end
