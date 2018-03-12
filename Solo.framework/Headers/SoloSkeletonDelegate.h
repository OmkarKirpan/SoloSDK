//
//  SoloSkeletonDelegate.h
//  SoloFramework
//
//  Created by Pavel Yurchenko on 3/7/18.
//  Copyright © 2018 Camerai. All rights reserved.
//
//  Please contact us at bugs@camerai.co if you have problems
//

/*!
    @protocol SoloSkeletonDelegate
    @brief It's a protocol to handle skeletons data pushed back through it
 */

extern NSString *const kSkeletonNoseJointName;
extern NSString *const kSkeletonChestJointName;
extern NSString *const kSkeletonRightShoulderJointName;
extern NSString *const kSkeletonRightElbowJointName;
extern NSString *const kSkeletonRightHandJointName;
extern NSString *const kSkeletonLeftShoulderJointName;
extern NSString *const kSkeletonLeftElbowJointName;
extern NSString *const kSkeletonLeftHandJointName;
extern NSString *const kSkeletonRightHipJointName;
extern NSString *const kSkeletonRightKneeJointName;
extern NSString *const kSkeletonRightFootJointName;
extern NSString *const kSkeletonLeftHipJointName;
extern NSString *const kSkeletonLeftKneeJointName;
extern NSString *const kSkeletonLeftFootJointName;
extern NSString *const kSkeletonRightEyeJointName;
extern NSString *const kSkeletonLeftEyeJointName;
extern NSString *const kSkeletonRightEarJointName;
extern NSString *const kSkeletonLeftEarJointName;

@protocol SoloSkeletonDelegate <NSObject>

@optional

/*!
    @brief Called when skeletons data is generated
    @param skeletons List of skeletons detected on the frame
 
    @discussion The returned skeletons list contains dictionaries each describing one skeleton, like:
 
                    {
                        "ID": 0,
                        "chest": [x, y],
                        ...,
                    }
 
                ID key of dictionary is unique for each skeleton detected.
                Supported list of joint names:
                        [
                            kSkeletonNoseJointName,
                            kSkeletonRightShoulderJointName,
                            kSkeletonRightElbowJointName,
                            kSkeletonRightHandJointName,
                            kSkeletonLeftShoulderJointName,
                            kSkeletonLeftElbowJointName,
                            kSkeletonLeftHandJointName,
                            kSkeletonRightHipJointName,
                            kSkeletonRightKneeJointName,
                            kSkeletonRightFootJointName,
                            kSkeletonLeftHipJointName,
                            kSkeletonLeftKneeJointName,
                            kSkeletonLeftFootJointName,
                            kSkeletonRightEyeJointName,
                            kSkeletonLeftEyeJointName,
                            kSkeletonRightEarJointName,
                            kSkeletonLeftEarJointName,
                         ]
 */
- (void)onSoloSkeletonData:(NSArray<NSDictionary*>*)skeletons;


/*!
    @brief Called when debug image with skeleton plotted on it is ready
    @discussion Override this callback only for debug purposes
 */
- (void)onSoloSkeletonDebugImage:(UIImage*)image;

@end

