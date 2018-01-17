//
//  SoloSegmentationDelegate.h
//  SoloFramework
//
//  Created by Pavel Yurchenko on 12/1/17.
//  Copyright © 2017 Camerai. All rights reserved.
//
//  Please contact us at bugs@camerai.co if you have problems
//


/*!
    @brief Determines a set of available mask types
 */
typedef NS_ENUM(NSUInteger, SoloMaskType)
{
    SMT_FullBody = 0,
    SMT_Head,
    SMT_Face,
    SMT_Hair,
};


/*!
    @protocol SoloSegmentationDelegate
    @brief It's a protocol to handle frame masks pushed back through it
 */

@protocol SoloSegmentationDelegate

@optional

/*!
    @brief Called when mask of appropriate type is generated
 */
- (void)onSoloSegmentationMaskMTLTextureFrame:(id<MTLTexture>)mtlTexture maskType:(SoloMaskType)maskType;


/*!
    @brief Called when mask of appropriate type is generated
 
    @param data Pixel buffer data in format BGRA
    @param width Width of the mask frame
    @param height Height of the mask frame
 */
- (void)onSoloSegmentationMaskDataFrame:(NSData*)data width:(CGFloat)width height:(CGFloat)height maskType:(SoloMaskType)maskType;


/*!
    @brief Called when mask of appropriate type is generated
 */
- (void)onSoloSegmentationMaskImageFrame:(UIImage*)image maskType:(SoloMaskType)maskType;


/*!
    @brief Called when mask of appropriate type is generated
 */
- (void)onSoloSegmentationMaskPixelBufferFrame:(CVPixelBufferRef)pixelBuffer maskType:(SoloMaskType)maskType;


@end

