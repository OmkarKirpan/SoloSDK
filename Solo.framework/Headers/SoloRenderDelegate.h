//
//  SoloRenderDelegate.h
//  SoloFramework
//
//  Created by Pavel Yurchenko on 11/30/17.
//  Copyright © 2017 Camerai. All rights reserved.
//
//  Please contact us at bugs@camerai.co if you have problems
//

/*!
    @protocol SoloRenderDelegate
    @brief It's a protocol to handle render frames pushed back through it
 */

@protocol SoloRenderDelegate <NSObject>

@optional
/*!
    @brief Called when frame buffer is ready for rendering
 
    @discussion Frame buffer is ready when sff is applied on it
 */
- (void)onSoloRenderPixelBufferFrame:(CVPixelBufferRef)pixelBuffer;


/*!
    @brief Called when frame buffer is ready for rendering
 
    @discussion Frame buffer is ready when sff is applied on it
 */
- (void)onSoloRenderImageFrame:(UIImage*)image;


/*!
    @brief Called when frame buffer is ready for rendering
 
    @discussion Frame buffer is ready when sff is applied on it
 
    @param data Pixel buffer data in format BGRA
    @param width Width of the output frame
    @param height Height of the output frame
 */
- (void)onSoloRenderDataFrame:(NSData*)data width:(CGFloat)width height:(CGFloat)height;


/*!
    @brief Called when frame buffer is ready for rendering
 
    @discussion Frame buffer is ready when sff is applied on it
 */
- (void)onSoloRenderYUV420Frame:(struct SoloYUV420Frame)frame;


@end
