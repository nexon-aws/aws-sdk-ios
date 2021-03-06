/*
 Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.

 Licensed under the Apache License, Version 2.0 (the "License").
 You may not use this file except in compliance with the License.
 A copy of the License is located at

 http://aws.amazon.com/apache2.0

 or in the "license" file accompanying this file. This file is distributed
 on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 express or implied. See the License for the specific language governing
 permissions and limitations under the License.
 */

#import <Foundation/Foundation.h>

#import "AWSNetworking.h"
#import "AWSSerialization.h"

@interface AWSJSONRequestSerializer : NSObject <AWSURLRequestSerializer>

- (instancetype)initWithResource:(NSString *)resource
                      actionName:(NSString *)actionName
                  classForBundle:(Class)classForBundle;

@end

@interface AWSXMLRequestSerializer : NSObject <AWSURLRequestSerializer>

- (instancetype)initWithResource:(NSString *)resource
                      actionName:(NSString *)actionName
                  classForBundle:(Class)classForBundle;

+ (BOOL)constructURIandHeadersAndBody:(NSMutableURLRequest *)request
                                rules:(AWSJSONDictionary *)rules
                           parameters:(NSDictionary *)params
                            uriSchema:(NSString *)uriSchema
                                error:(NSError *__autoreleasing *)error;
@end

@interface AWSQueryStringRequestSerializer : NSObject <AWSURLRequestSerializer>

- (instancetype)initWithResource:(NSString *)resource
                      actionName:(NSString *)actionName
                  classForBundle:(Class)classForBundle;

@property (nonatomic, strong) NSDictionary *additionalParameters;

@end

@interface AWSEC2RequestSerializer : AWSQueryStringRequestSerializer <AWSURLRequestSerializer>

@end