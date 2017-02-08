//
//  IEffect.h
//  SoloFramework
//
//  Created by Pavel Yurchenko on 10/6/16.
//  Copyright © 2016 Tipit Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>


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
- (UIImage*)getIconImage;

@end
