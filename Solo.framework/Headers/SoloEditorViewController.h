//
//  SoloEditorViewController.h
//  SoloFramework
//
//  Created by Pavel Yurchenko on 9/28/16.
//  Copyright © 2016 Tipit Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol SoloEditorViewControllerDelegate;
@class GPUImageView;

typedef NS_ENUM(NSUInteger, ShowStyle)
{
    SS_Modal = 0,
    SS_Push
};


typedef void(^ExportCompletion)(NSURL *url);

/*!
    @class SoloEditorViewController
 
    @brief This is the default editor view controller
 
    @discussion This class implements functionality of Solo default editor. It should be used as a base class when creating custom editor.
 */

@interface SoloEditorViewController : UIViewController

/*!
    @brief gpuImageView outlet
 
    @discussion This one must be connected with the appropriate view in the storyboard to render the media that is being edited correctly on it
 */
@property (nonatomic, strong) IBOutlet GPUImageView *gpuImageView;


/*!
    @brief Delegate
 
    @discussion It's used to notify about editing finished or canceled events
 */
@property (nonatomic, weak) id<SoloEditorViewControllerDelegate> delegate;

/*!
    @brief Cancel button visibility token
 
    @discussion Use it to get or set Cancel button hidden state. Assign YES to hide Cancel button on default editor
 */
@property (nonatomic, assign) BOOL cancelButtonIsHidden;


/*!
    @brief Done button visibility token
 
    @discussion Use it to get or set Done button hidden state. Assign YES to hide Done button on default editor
 */
@property (nonatomic, assign) BOOL doneButtonIsHidden;


/*!
    @brief Custom Filters button visibility token
 
    @discussion Use it to get or set Custom Filters button hidden state. Assign YES to hide Custom Filters button on default editor
 */
@property (nonatomic, assign) BOOL customFiltersButtonIsHidden;


/*!
    @brief Music button visibility token
 
    @discussion Use it to get or set Music button hidden state. Assign YES to hide Music button on default editor
 */
@property (nonatomic, assign) BOOL musicButtonIsHidden;


/*!
    @brief Effects tool visibility token
 
    @discussion Use it to get or set Effects Tool hidden state. Assign YES to hide Effects Tool on default editor
 */
@property (nonatomic, assign) BOOL effectsToolIsHidden;


/*!
    @brief Deny render transformation token
 
    @discussion Use it to allow or deny the ability to scale/rotate/translate the media in editor view. By default it's set to NO and transformations are allowed
 */
@property (nonatomic, assign) BOOL denyRenderTransformation;


/*!
 @brief Tutorial tooltip popups visibility token
 
 @discussion Use it to get or set tutorial tooltip popups hidden state. Assign YES to hide tutorial tooltip popups on default editor
 */
@property (nonatomic, assign) BOOL tutorialTooltipsIsHidden;


/*!
    @brief URL to media being edited
 */
@property (nonatomic, copy, readonly) NSURL *mediaURL;


/*!
    @brief First frame image
 
    @discussion First frame image extracted from current media. It can be used for generating effects thumbnails
 */
@property (nonatomic, readonly) UIImage *firstImageThumbnail;

/*!
 @brief Presentation sty;e
 
 @discussion Presentation style value defines how view controller is presented on editing. Default value is SS_Modal
 */
@property (nonatomic, assign) ShowStyle showStyle;


/*!
    @brief Default editor static constructor
 
    @discussion The following static constructor is a MUST for each custom editor view controller class, it is used by the SoloManager code to create instance and present it.
                Create similar one if you are creating custom editor based on SoloEditorViewController for your successor class
 */
+ (SoloEditorViewController*)controllerFromStoryboard;


/*!
    @brief Cancel action
 
    @discussion Call to simulate back/cancel button press
 */
- (void)cancel;


/*!
    @brief Done action
 
    @discussion Call to simulate done button press. In this case the result will be saved and returned in callback
 */
- (void)done;


/*!
    @brief Returns YES whether quit confirmation dialog should be shown
 
    @discussion Override this method to control quit confirmation dialog visibility. Return NO if you don't want it to be shown
 */
- (BOOL)showQuitConfirmation;

/*!
 @brief Call to generate url with processed photo
 
 @discussion When calling this method it saves image with applied filters on it and returns image url in completion
 
 @param completion Code block that is called when image is saved
 */
- (void)exportProcessedPhoto:(ExportCompletion)completion;



@end


/*!
    @protocol SoloEditorViewControllerDelegate
    
    @brief Default editor delegate protocol
 
    @discussion Implement it to receive notifications from editor
 */

@protocol SoloEditorViewControllerDelegate <NSObject>

@optional
/*!
    @brief Did cancel notification
 
    @discussion This method is called when user presses Cancel button on the editor or when <i>cancel</i> method of editor is fired in the code
 
    @param sender Reference to the editor view controller that called it
 */
- (void)onSoloEditorViewControllerDidCancel:(SoloEditorViewController*)sender;

/*!
    @brief Did refuse cancelling
 
    @discussed This method is called when user pressed cancel button of the editor and then answers NO the confirmation question
 
    @param sender Reference to the editor view controller that called it
 */
- (void)onSoloEditorViewControllerDidRefuseCancelling:(SoloEditorViewController*)sender;

/*!
    @brief Did finish notification
 
    @discussion This method is called when user presses Done button on the editor or when <i>done</i> method of editor is fired in the code and right after saving result media is finished
 
    @param sender Reference to the editor view controller that called it
    @param url URL to the result media
 */
- (void)onSoloEditorViewController:(SoloEditorViewController*)sender didFinishExport:(NSURL*)url;

/*!
 @brief Did complete notification
 
 @discussion This method is called when server processing is ended

 @param sender Reference to the editor view controller that called it
 @param error Returns error if something went wrong
 */
- (void)onSoloEditorViewController:(SoloEditorViewController*)sender didCompleteWithError:(NSError *)error;

@end
