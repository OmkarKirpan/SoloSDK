//
//  SoloManager.h
//  SoloFramework
//
//  Created by Pavel Yurchenko on 8/4/16.
//  Copyright © 2016 Tipit Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

extern const NSInteger kInvalidAssetURLError;
extern const NSInteger kPrepareAssetError;
extern const NSInteger kCancelError;

@protocol IEffectsManager;
@protocol IEffect;
@protocol IBGManager;
@protocol IBGVideo;
@class SoloEditorViewController;

typedef void(^EditCompletion)(NSURL *url, NSError *error);
typedef void(^EditorBlock)(SoloEditorViewController *editor);
typedef void(^ImageBlock)(UIImage *image);


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
    @brief Set custom editor class
 
    @discussion If you are implementing custom editor then use the following method to
                let SDK know the editor view controller class, i.e. <i>[SoloManager setEditorControllerClass:[CustomEditorViewController class]];</i>
 
    @param editorClass Custom editor class to open for editing media
 */
+ (void)setEditorControllerClass:(Class)editorClass;


/*!
    @brief Call to present editor and start editing video process
    
    @discussion When calling this method SoloManager creates instance of the editor view controller and presents it on parent. If you want your custom editor to be used for editing media make sure that you set it's class before calling this method
 
    @param assetURL URL to video file to edit
    @param completion Code block that is called when saving result video is finished or when user cancels the progress
    @param parent Parent view controller on top of which editor will be presented
 
    @deprecated This method is deprecated and will be removed in the nearest future. Use @link editVideo:willAppearBlock:completion:parent:@/link instead
 */
+ (void)editVideo:(NSURL*)assetURL completion:(EditCompletion)completion parent:(UIViewController*)parent DEPRECATED_ATTRIBUTE;


/*!
    @brief Call to present editor and start editing video process
 
    @discussion When calling this method SoloManager creates instance of the editor view controller and presents it on parent. If you want your custom editor to be used for editing media make sure that you set it's class before calling this method
 
    @param assetURL URL to video file to edit
    @param willAppearBlock Code block that is called when editor instance is created and about to appear on screen. It's good place to make some configurations to the editor view controller like configure default controls visibility (Cancel, Done, Music buttons etc.)
    @param completion Code block that is called when saving result video is finished or when user cancels the progress
    @param parent Parent view controller on top of which editor will be presented
 */
+ (void)editVideo:(NSURL*)assetURL willAppearBlock:(EditorBlock)willAppearBlock completion:(EditCompletion)completion parent:(UIViewController*)parent;


/*!
    @brief Call to present editor and start editing photo process
 
    @discussion When calling this method SoloManager creates instance of the editor view controller and presents it on parent. If you want your custom editor to be used for editing media make sure that you set it's class before calling this method
 
    @param assetURL URL to photo file to edit
    @param completion Code block that is called when saving result photo is finished or when user cancels the progress
    @param parent Parent view controller on top of which editor will be presented
 
    @deprecated This method is deprecated and will be removed in the nearest future. Use @link editPhoto:willAppearBlock:completion:parent:@/link instead
 */
+ (void)editPhoto:(NSURL*)assetURL completion:(EditCompletion)completion parent:(UIViewController*)parent DEPRECATED_ATTRIBUTE;


/*!
    @brief Call to present editor and start editing photo process
 
    @discussion When calling this method SoloManager creates instance of the editor view controller and presents it on parent. If you want your custom editor to be used for editing media make sure that you set it's class before calling this method
 
    @param assetURL URL to photo file to edit
    @param willAppearBlock Code block that is called when editor instance is created and about to appear on screen. It's good place to make some configurations to the editor view controller like configure default controls visibility (Cancel, Done, Music buttons etc.)
    @param completion Code block that is called when saving result photo is finished or when user cancels the progress
    @param parent Parent view controller on top of which editor will be presented
 */
+ (void)editPhoto:(NSURL*)assetURL willAppearBlock:(EditorBlock)willAppearBlock completion:(EditCompletion)completion parent:(UIViewController*)parent;


/*!
    @brief Apply effect to video without presenting editor
 
    @discussion Call to apply effect to a video on background. TargetSize property does not have effect in this case. The output video has the same resolution as input.
 
    @param assetURL URL to video file to edit
    @param effect Effect to apply to the video
    @param completion Code block that is called when saving result video is finished
 */
+ (void)applyEffectToVideo:(NSURL*)assetURL effect:(id<IEffect>)effect completion:(EditCompletion)completion;


/*!
    @brief Apply effect to photo without presenting editor
 
    @discussion Call to apply effect to a photo on background. TargetSize property does not have effect in this case. The output photo has the same resolution as input.
 
    @param assetURL URL to a photo file to edit
    @param effect Effect to apply to the photo
    @param completion Code block that is called when saving result photo is finished
 */
+ (void)applyEffectToPhoto:(NSURL*)assetURL effect:(id<IEffect>)effect completion:(EditCompletion)completion;


/*!
    @brief Force to finish editing media
 
    @discussion Call to finish editing process. This method triggers delegate appropriate method to notify about the result
 
    @param cancel Pass YES if canceling is needed
 */
+ (void)finishEditing:(BOOL)cancel;


/*!
    @brief Get effects manager
 
    @discussion Call to obtain reference to the effects manager instance
 
    @return Reference to the effects manager instance
 */
+ (id<IEffectsManager>)getEffectsManager;


/*!
    @brief Generate effect thumbnail image
 
    @discussion Call to apply effect to the first frame thumbnail image extracted from current media
 
    @param effect Effect to apply to the first frame image for generating thumbnail
    @param completion Code block that is called when generating effect thumbnail is finished
 */
+ (void)generateEffectThumbnailImage:(id<IEffect>)effect completion:(ImageBlock)completion;


/*!
    @brief Activate effect
 
    @discussion Call to load and activate effect in the editor
 
    @param effect Effect to make active in the current editor
 */
+ (void)setCurrentEffect:(id<IEffect>)effect;


/*!
    @brief Get backgrounds manager
 
    @discussion Call to obtain reference to the background manager instance
 
    @return Reference to the backgrounds manager instance
 */
+ (id<IBGManager>)getBGManager;


/*!
    @brief Activate background
 
    @discussion Call to load and activate background in editor. It works for both video and photo. Only video backgrounds are supported. For photo mode the first frame extracted from the video background is used
 
    @param video Video background to activate in current editor
 */
+ (void)setBGVideo:(id<IBGVideo>)video;


/*!
    @brief Activate custom background
 
    @discussion Call to load and activate any custom video background in editor. It works for both video and photo. Only video backgrounds are supported. For photo mode the first frame extracted from the video background is used
 
    @param url URL to the video background file to activate in current editor
 */
+ (void)setBGVideoURL:(NSURL*)url;


/*!
 @brief Activate custom background
 
 @discussion Call to load and activate any custom photo background in editor.
 @param url URL to the photo background file to activate in current editor
 */
+ (void)setBGImageURL:(NSURL*)url;


/*!
    @brief Set render target size
 
    @discussion Call to set new target render size. By default it's equal to device screen resolution to support full screen, i.e. 320x568 for iPhone 5 or 768x1024 for iPad
 
    @param size New render target size
 */
+ (void)setTargetSize:(CGSize)size;

@end
