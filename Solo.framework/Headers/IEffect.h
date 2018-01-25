//
//  IEffect.h
//  SoloFramework
//
//  Created by Pavel Yurchenko on 10/6/16.
//  Copyright © 2016 Camerai. All rights reserved.
//
//  Please contact us at bugs@camerai.co if you have problems
//

#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
typedef UIImage ImageType;
#else
#import <AppKit/AppKit.h>
typedef NSImage ImageType;
#endif


@protocol IFilterParameter;
@protocol IEffectBundle;


/*!
    @protocol IEffect
    @brief It's a protocol for accessing effect features
 */
@protocol IEffect <NSObject>

/*!
    @brief Predefined effect name
 */
@property (nonatomic, readonly) NSString *name;

/*!
    @brief Effect version
 */
@property (nonatomic, readonly) NSString *version;

/*!
    @brief Keeps selfie camera flag for the case effect is dependant on it
 */
@property (nonatomic, assign) BOOL isSelfie;

/*!
 @brief Filter layers structure by folders
 
 @discussion Call to get structured information about all filter layers used in effect. The result is returned as
                NSDictionary<NSString *, NSArray<NSDictionary *> *>
                where key is the folder name and value is array of dictionaries describing filter layers
 */
@property (nonatomic, readonly) NSDictionary* filterLayersByFolders;



/*!
    @brief Predefined icon image
    
    @discussion Call it to get a predefined icon representing the effect if it's present. 
                If there is no predefined icon then use <i>generateEffectThumbnailImage:completion:</i> method of <i>SoloManager</i> to generate one
 
    @return Icon image if it's predefined, otherwise returns nil
 */
- (ImageType*)getIconImage;



@end
