//
//  IEffect.h
//  SoloFramework
//
//  Created by Pavel Yurchenko on 10/6/16.
//  Copyright © 2016 Tipit Ltd. All rights reserved.
//

#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
typedef UIImage ImageType;
#else
typedef NSImage ImageType;
#endif


@protocol IFilterParameter;
@protocol IEffectBundle;
@protocol IFilter;


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
 @brief Predefined minimum value of effect's background
 */
@property (nonatomic, readonly)  CGFloat backgroundParamMinValue;

/*!
 @brief Predefined maximum value of effect's background
 */
@property (nonatomic, readonly)  CGFloat backgroundParamMaxValue;

/*!
 @brief  Value of effect's background. Possible values - in range from backgroundParamMinValue to backgroundParamMaxValue
 */
@property (nonatomic, assign)    CGFloat backgroundParamValue;

/*!
 @brief Predefined minimum value of effect's foreground
 */
@property (nonatomic, readonly)  CGFloat objectParamMinValue;

/*!
 @brief Predefined maximum value of effect's foreground
 */
@property (nonatomic, readonly)  CGFloat objectParamMaxValue;

/*!
 @brief  Value of effect's foreground. Possible values - in range from objectParamMinValue to objectParamMaxValue
 */
@property (nonatomic, assign)    CGFloat objectParamValue;

/*!
    @brief Predefined icon image
    
    @discussion Call it to get a predefined icon representing the effect if it's present. 
                If there is no predefined icon then use <i>generateEffectThumbnailImage:completion:</i> method of <i>SoloManager</i> to generate one
 
    @return Icon image if it's predefined, otherwise returns nil
 */
- (ImageType*)getIconImage;

/*!
    @brief Apply custom filter to foreground
 
    @discussion Call this method to apply custom filter to the foreground
 
    @param filter Custom filter to apply
 */
- (void)applyCustomObjectFilter:(id<IFilter>)filter;

/*!
    @brief Apply custom filter to background
 
    @discussion Call this method to apply custom filter to the background
 
    @param filter Custom filter to apply
 */
- (void)applyCustomBackgroundFilter:(id<IFilter>)filter;


@end
