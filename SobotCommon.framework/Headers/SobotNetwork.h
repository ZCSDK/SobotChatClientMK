//
//  SobotNetwork.h
//  SobotNetwork
//
//  Created by zhangxy on 2021/7/9.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SobotRequest.h"

// 自定义超时时间，每次请求header中增加此参数，单位毫秒，默认30秒
FOUNDATION_EXPORT NSString * const SobotRequestHeaderTimeoutInterval;

NS_ASSUME_NONNULL_BEGIN

// 网络请求类型
typedef NS_ENUM(NSInteger, SobotRequestType) {
    SobotRequestTypeGET = 0,
    SobotRequestTypePOST = 1,
    SobotRequestTypePUT = 2,
    SobotRequestTypeDELETE = 3
};

// 参数模式已在 SobotRequest.h 中定义，这里不再重复定义

// 回调块定义
typedef void(^SobotStartLoadingBlock)(NSURLSessionDataTask * _Nonnull task);
typedef void(^SobotSuccessBlock)(NSURLResponse * _Nonnull response, id _Nullable responseObject, NSData * _Nullable data);
typedef void(^SobotFailBlock)(NSURLResponse * _Nullable response, NSString * _Nullable errorMessage, NSError * _Nullable error);
typedef void(^SobotFinishBlock)(NSURLResponse * _Nullable response, NSData * _Nullable data, NSString * _Nullable responseString);
typedef void(^SobotProgressBlock)(NSURLSessionDataTask * _Nonnull task, double progress);

@interface SobotNetwork : NSObject

// 性能优化相关方法
+ (void)setMaxConcurrentRequests:(NSInteger)maxCount;
+ (void)cancelAllRequests;
+ (void)cancelRequestWithURL:(NSString *)url;
+ (void)setRequestTimeout:(NSTimeInterval)timeout;
+ (void)enableRequestCache:(BOOL)enable;
+ (void)clearRequestCache;

// 网络请求方法
+ (void)get:(NSString *)api_url params:(NSDictionary *)paramters;
+ (SobotRequest *)getSobotRequest;

+ (void)get:(NSString *)api_url
      params:(NSDictionary *)paramters
      header:(NSDictionary *)header
       begin:(SobotStartLoadingBlock)beginBlock
     success:(SobotSuccessBlock)successBlock
        fail:(SobotFailBlock)failBlock
      finish:(SobotFinishBlock)finishBlock;

+ (void)get:(NSString *)api_url
      params:(NSDictionary *)paramters
      header:(NSDictionary *)header
       begin:(SobotStartLoadingBlock)beginBlock
     success:(SobotSuccessBlock)successBlock
        fail:(SobotFailBlock)failBlock
      finish:(SobotFinishBlock)finishBlock
    progress:(SobotProgressBlock _Nullable)proressBlock;

+ (void)post:(NSString *)api_url
       params:(NSDictionary *)paramters
       header:(NSDictionary *)header
        begin:(SobotStartLoadingBlock)beginBlock
      success:(SobotSuccessBlock)successBlock
         fail:(SobotFailBlock)failBlock
       finish:(SobotFinishBlock)finishBlock;

+ (void)post:(NSString *)api_url
       params:(NSDictionary *)paramters
       header:(NSDictionary *)header
    paramsMode:(SobotParameterMode)mode
        begin:(SobotStartLoadingBlock)beginBlock
      success:(SobotSuccessBlock)successBlock
         fail:(SobotFailBlock)failBlock
       finish:(SobotFinishBlock)finishBlock
     progress:(SobotProgressBlock)proressBlock;

+ (void)url:(NSString *)api_url
      params:(NSDictionary *)paramters
      header:(NSDictionary *)header
  paramsMode:(SobotParameterMode)mode
      mothed:(NSString *)mothed
       begin:(SobotStartLoadingBlock)beginBlock
     success:(SobotSuccessBlock)successBlock
        fail:(SobotFailBlock)failBlock
      finish:(SobotFinishBlock)finishBlock
   progress:(SobotProgressBlock)proressBlock;

@end

NS_ASSUME_NONNULL_END

