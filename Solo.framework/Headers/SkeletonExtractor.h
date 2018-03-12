//
//  FaceDetect.h
//  RunModel
//
//  Created by Camerai on 18/04/2017.
//  Copyright © 2017 Moty Kosharovsky. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreImage/CoreImage.h>

@interface SkeletonExtractor : NSObject

+ (void)extractSkeletonWithJoints:(float *)jointsPtr jointsCount:(int *)jointCountPtr pafMap:(float *)pafmapPtr skeletons:(float *)skeletons andPAFSize:(CGSize)pafmapSize;

@end
