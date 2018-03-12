//
//  SoloManager.h
//  SoloFramework
//
//  Created by Pavel Yurchenko on 8/4/16.
//  Copyright © 2016 Camerai. All rights reserved.
//
//  Please contact us at bugs@camerai.co if you have problems
//

#import <GLKit/GLKit.h>
#import <AVFoundation/AVFoundation.h>

@protocol IEffect;
@protocol IEffectBundle;
@protocol SoloRenderDelegate;
@protocol SoloSegmentationDelegate;
@protocol SoloDepthDelegate;
@protocol SoloSkeletonDelegate;
typedef void(^ImageBlock)(UIImage *image, NSError *error);
typedef void(^ValidBlock)(BOOL valid, NSError *error);

typedef NS_ENUM(NSUInteger, FrameFormat)
{
    FF_PixelBuffer = 0,
    FF_Image,
    FF_Data,
    FF_MetalTexture, // Available for segmentation only
    FF_YUV420, // Available for rendering only
};

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
    @brief Determines frame orientation
 */
typedef NS_ENUM(NSUInteger, SoloFrameOrientation)
{
    SFO_Portrait = 0,
    SFO_LandscapeRight,
    SFO_LandscapeLeft,
    SFO_PortraitUpsideDown,
};

/*!
    @brief Determines YUV420 frame data type
 */
struct SoloYUV420Frame
{
    void *yBuffer;
    void *uBuffer;
    void *vBuffer;
    
    NSUInteger yStride;
    NSUInteger uStride;
    NSUInteger vStride;
    
    CGSize size;
    
    SoloFrameOrientation orientation;
};

/*!
    @class SoloManager
 
    @brief Use to manage editor's and core functionality
 
    @discussion This class is the main connection point between SDK's functionality and the utilizing code. 
                It aggregates methods for managing editor and core functionality, access other managers like effects and backgrounds
 */

@interface SoloManager : NSObject

/*!
    @brief Initializer method
 
    @discussion This is the main initializer method, it must be called on application launch. 
                Use access token received to initialize the SDK
 
    @param accessToken Access token used by the core to communicate with server
 */
+ (void)initSolo:(NSString*)accessToken;


/*!
    @brief Validate license method
 
    @discussion Call this method to validate license on server
 */
+ (void)validateLicense:(NSString*)accessToken completion:(ValidBlock)completion;


/*!
    @brief Setup rendering system
    @param viewController Pointer to view controller instance where to render result. Pass nil if you don't need to render result, i.e. if you just want to receive result frames in render delegate callbacks
 */
+ (void)setupRenderFor:(GLKViewController*)viewController error:(NSError**)error;


/*!
    @brief Setup delegate to receive call back with frames ready for rendering
 */
+ (void)setupRenderDelegate:(id<SoloRenderDelegate>)renderDelegate frameFormat:(FrameFormat)frameFormat error:(NSError**)error;


/*!
    @brief Setup delegate to receive call back with frame masks after segmentation
 */
+ (void)setupSegmentationDelegate:(id<SoloSegmentationDelegate>)segmentationDelegate frameFormat:(FrameFormat)frameFormat error:(NSError**)error;


/*!
    @brief Setup delegate to recieve call back with depth map
 */
+ (void)setupDepthDelegate:(id<SoloDepthDelegate>)depthDelegate frameFormat:(FrameFormat)frameFormat error:(NSError**)error;


/*!
    @brief Setup delegate to recieve call back with skeletons detected data
 */
+ (void)setupSkeletonDelegate:(id<SoloSkeletonDelegate>)skeletonDelegate error:(NSError**)error;


/*!
    @brief Stop and destroy redering system
 */
+ (void)destroyRender;


/*!
    @brief Activate effect
 
    @discussion Call to load and activate effect in the editor
 
    @param effect Effect to make active in the current editor
 */
+ (void)setCurrentEffect:(id<IEffect>)effect error:(NSError**)error;

/*!
    @brief Current effect
 
    @discussion Call to get access to currently active effect
 */
+ (id<IEffect>)getCurrentEffect:(NSError**)error;


/*!
    @brief Create bundle
 
    @discussion Call to create new effect bundle instance
 
    @param url Either local or remote file URL
 */
+ (id<IEffectBundle>)effectBundleWithURL:(NSURL*)url error:(NSError**)error;

/*!
    @brief Create effect
 
    @discussion Call to create new effect bundle instance
 
    @param effectBundle Effect bundle
    @param error Error to return as a result if failed
 */
+ (id<IEffect>)effectFromBundle:(id<IEffectBundle>)effectBundle error:(NSError**)error;


/*!
    @brief Pass pixel buffer frame to SDK for processing
 
    @discussion Call this method to feed SDK with pixel buffer of frame
 */
+ (void)feedPixelBufferFrame:(CVPixelBufferRef)pixelBuffer error:(NSError**)error;

/*!
    @brief Pass image frame to SDK for processing
 
    @discussion Call this method to feed SDK with image of frame
 */
+ (void)feedImage:(UIImage*)image error:(NSError**)error;

/*!
    @brief Pass YUV 420 frame to SDK for processing
 
    @discussion Call this method to feed SDK with frame in format YUV 420
 
    @param frame YUV frame data instance. User is responsible for managing memory buffers used in structure instance
 */
+ (void)feedYUVFrame:(struct SoloYUV420Frame)frame error:(NSError**)error;


/*!
    @brief Perform rendering frame
 
    @discussion Call to render current frame on the surface previously used to initialize rendering system
 */
+ (void)renderFrame:(NSError**)error;

/*!
    @brief Set render size
 
    @discussion Call to set certain size to use for rendering
 */
+ (void)setRenderTargetSize:(CGSize)size error:(NSError**)error;

/*!
    @brief Applies art effect to image
 
    @discussion Call to apply loaded art effect to an image. Works only with art effects!
 
    @return Image of the same resolution that input one but with effect applied
 */
+ (UIImage*)applyArtEffect:(id<IEffect>)effect toImage:(UIImage*)image error:(NSError**)error;

/*!
    @brief Set model by URL to use for segmentation
 
    @discussion Call to activate new model to use for segmentation
 */
+ (void)setModel:(NSURL*)url error:(NSError**)error;


/*!
    @brief Disable model segmentation
 
    @discussion Call to disable using model for segmentation functionanlity in the SDK
 */
+ (void)disableModel:(BOOL)disable error:(NSError**)error;


/*!
    @brief Set model by URL to use for depth processing
 
    @discussion Call to activate new model to use for depth processing
 */
+ (void)setDepthModel:(NSURL*)url error:(NSError**)error;


/*!
    @brief Disable depth model
 
    @discussion Call to disable depth processing in the SDK
 */
+ (void)disableDepthModel:(BOOL)disable error:(NSError**)error;


/*!
    @brief Set model by URL to use for skeleton processing
 
    @discussion Call to activate new model to use for skeleton processing
 */
+ (void)setSkeletonModel:(NSURL*)url error:(NSError**)error;


/*!
    @brief Disable skeleton model
 
    @discussion Call to disable skeleton processing in the SDK
 */
+ (void)disableSkeletonModel:(BOOL)disable error:(NSError**)error;


/*!
    @brief Set face database by URL to use for segmentation
 
    @discussion Call to activate new face database to use for segmentation. The URL must be URL to folder containing db data files
 */
+ (void)setFaceDB:(NSURL*)url error:(NSError**)error;


/*!
    @brief Disable face tracking
 
    @discussion Call to disable face tracking functionanlity in the SDK
 */
+ (void)disableFace:(BOOL)disable error:(NSError**)error;


/*!
    @brief Resize image to 4 factor
 
    @discussion Call to resize image to the size appropriate for effective processing by the SDK
 */
+ (UIImage*)resizeImageTo4Factor:(UIImage*)image;


/*!
    @brief Set history parameter value
 
    @discussion Call to override default history parameter value used in segmentation logic. Default value is 0.15
 */
+ (void)setHistoryParam:(CGFloat)value error:(NSError**)error;


/*!
    @brief Set mask hardening parameter value
 
    @discussion Call to override default mask hardening parameter value used in segmentation logic. Default value is 2.0
 */
+ (void)setMaskHardeningParam:(CGFloat)value error:(NSError**)error;


/*!
    @brief Enable portrait preprocessing for mask
 
    @discussion Call to enable portrait preprocessing mechanism for specified mask type
 */
+ (void)enablePortraitPreprocessing:(BOOL)enable forMask:(SoloMaskType)maskType error:(NSError**)error;


@end
