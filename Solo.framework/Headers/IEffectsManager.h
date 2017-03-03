//
//  IEffectsManager.h
//  SoloFramework
//
//  Created by Pavel Yurchenko on 10/6/16.
//  Copyright © 2016 Tipit Ltd. All rights reserved.
//

@protocol IEffect;
@protocol IEffectBundle;


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
    @brief Returns current IEffect
 */
@property (nonatomic, readonly) id<IEffect> currentEffect;


/*!
    @discussion Call it to get reference to an effect with corresponding index
 
    @param index Index of an effect
 
    @return Reference to an effect
 */
- (id<IEffect>)effectAtIndex:(NSUInteger)index;


/*!
    @brief Add effect
 
    @discussion Call it to register effect in the effects manager list and make it available in editor
 */
- (void)addEffect:(id<IEffect>)effect;


@end
