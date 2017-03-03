//
//  IBGManager.h
//  SoloFramework
//
//  Created by Pavel Yurchenko on 10/7/16.
//  Copyright © 2016 Tipit Ltd. All rights reserved.
//

@protocol IBGVideo;


/*!
    @protocol IBGManager
    @brief It's a protocol for accessing backgrounds manager features
 */

@protocol IBGManager <NSObject>

/*!
    @brief Number of available backgrounds
 */
@property (nonatomic, readonly) NSUInteger backgroundsCount;


/*!
    @discussion Call it to get reference to a background with corresponding index
 
    @param index Index of a background
 
    @return Reference to a background
 */
- (id<IBGVideo>)backgroundAtIndex:(NSUInteger)index;

/*!
    @brief Add video background
 
    @discussion Call to add video background into the list and make it available in editor
 */
- (void)addVideoBG:(id<IBGVideo>)bgVideo;

/*!
 @brief Add photo background
 
 @discussion Call to add photo background into the list and make it available in editor
 */
- (void)addPhotoBG:(id<IBGVideo>)bgVideo;

@end
