//
//  IFilter.h
//  SoloFramework
//
//  Created by Pavel Yurchenko on 3/23/17.
//  Copyright © 2017 Tipit Ltd. All rights reserved.
//

/*!
    @brief Custom filters enumeration
 */
typedef NS_ENUM(NSUInteger, CustomFilterType)
{
    CFT_Hue = 0,
    CFT_Grayscale,
    CFT_Polkadot,
    CFT_Sepia,
    CFT_PolarPixellate,
    CFT_ColorInvert,
    CFT_Bulge,
    CFT_Pinch,
    CFT_GlassSphere,
    CFT_Vignette,
    CFT_Custom,
    CFT_CGA,
    CFT_Monochrome,
    CFT_FalseColor,
    CFT_Sketch,
    CFT_Toon,
    CFT_SmoothToon,
    CFT_Posterize,
    CFT_Emboss,
    CFT_WhiteBalance,
    CFT_ToneCurve,
    CFT_HighLightShadow,
    CFT_Haze,
    CFT_AverageLuminanceTheshold,
    CFT_Pixellate,
    CFT_CrossHatch,
    CFT_XYGradient,
    CFT_LowPass,
    CFT_HighPass,
    CFT_TiltShift,
    CFT_Stretch,
    CFT_Dilation,
    CFT_Erosion,
    CFT_SobelEdgeDetection,
    CFT_Count,
};

/*!
    @protocol IFilter
    @brief It's a protocol for accessing filter features
 */
@protocol IFilter <NSObject>

@property (nonatomic, readonly) CustomFilterType customFilterType;

@end
