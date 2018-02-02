//
//  SoloDepthDelegate.h
//  SoloFramework
//
//  Created by Pavel Yurchenko on 1/30/18.
//  Copyright © 2018 Camerai. All rights reserved.
//
//  Please contact us at bugs@camerai.co if you have problems
//

/*!
    @protocol SoloDepthDelegate
    @brief It's a protocol to handle depth frames pushed back through it
 */

@protocol SoloDepthDelegate <NSObject>

@optional

/*!
    @brief Called when depth buffer is generated
 */
- (void)onSoloDepthPixelBufferFrame:(CVPixelBufferRef)pixelBuffer;


/*!
    @brief Called when depth buffer is generated
 */
- (void)onSoloDepthImageFrame:(UIImage*)image;


/*!
    @brief Called when depth buffer is generated
 
    @param data Pixel buffer data in format BGRA
    @param width Width of the output frame
    @param height Height of the output frame
 */
- (void)onSoloDepthDataFrame:(NSData*)data width:(CGFloat)width height:(CGFloat)height;

@end

