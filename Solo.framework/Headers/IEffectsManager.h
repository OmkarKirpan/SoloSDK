//
//  IEffectsManager.h
//  SoloFramework
//
//  Created by Pavel Yurchenko on 10/6/16.
//  Copyright © 2016 Tipit Ltd. All rights reserved.
//

@protocol IEffect;


/*!
    @protocol IEffectsManager
    @brief It's a protocol for accessing effects manager features
 */

@protocol IEffectsManager <NSObject>

/*!
    @brief Number of available effects
 */
@property (nonatomic, readonly) NSUInteger effectsCount;


/*!
    @discussion Call it to get reference to an effect with corresponding index
 
    @param index Index of an effect
 
    @return Reference to an effect
 */
- (id<IEffect>)effectAtIndex:(NSUInteger)index;


@end
