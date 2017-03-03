//
//  IBGVideo.h
//  SoloFramework
//
//  Created by Pavel Yurchenko on 10/7/16.
//  Copyright © 2016 Tipit Ltd. All rights reserved.
//


/*!
    @protocol IBGVideo
    @brief It's a protocol for accessing background video features
 */

@protocol IBGVideo <NSObject>

/*!
    @brief Predefined background title
 */
@property (nonatomic, copy) NSString *title;


/*!
    @brief Preferined icon image
 
    @discussion Call it to get the predefined icon representing the background
 
    @return Icon image if it's predefined, otherwise returns nil
 */
- (UIImage*)getIconImage;

@end
