//
//  FTPManager.m
//  RunModel
//
//  Created by Camerai on 09/04/2017.
//  Copyright © 2017 Moty Kosharovsky. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FTPManager : NSObject

+ (FTPManager *)sharedInstance;

@property (nonatomic, assign, readonly ) BOOL              isSending;
@property (nonatomic, strong, readwrite) NSOutputStream *  networkStream;
@property (nonatomic, strong, readwrite) NSInputStream *   fileStream;
@property (nonatomic, assign, readonly ) uint8_t *         buffer;
@property (nonatomic, assign, readwrite) size_t            bufferOffset;
@property (nonatomic, assign, readwrite) size_t            bufferLimit;
@property (nonatomic, assign, readwrite) NSString        * ftpAddress;
@property (nonatomic, assign, readwrite) NSString        * ftpUsername;
@property (nonatomic, assign, readwrite) NSString        * ftpPassword;

- (void)startSend:(NSString *)filePath;
- (void)setFTPAddress:(NSString *)address username:(NSString *)username password:(NSString *) password;

@end
