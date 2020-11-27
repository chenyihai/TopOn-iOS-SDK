//
//  ATUnityAdsBannerAdapter.h
//  AnyThinkUnityAdsBannerAdapter
//
//  Created by Martin Lau on 2018/12/25.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface ATUnityAdsBannerAdapter : NSObject

@end

@protocol UnityAdsDelegate;
@protocol ATUnityAds<NSObject>
+ (NSString *)getVersion;
+ (BOOL)isInitialized;
+ (void)initialize:(NSString *)gameId;
+ (void)addDelegate:(__nullable id<UnityAdsDelegate>)delegate;
+ (void)removeDelegate:(id<UnityAdsDelegate>)delegate;
+ (BOOL)isReady:(NSString *)placementId;
+ (void)initialize:(NSString *)gameId delegate:(nullable id<UnityAdsDelegate>)delegate;
+ (void)initialize:(NSString *)gameId delegate:(nullable id<UnityAdsDelegate>)delegate testMode:(BOOL)testMode;
@end


@protocol UnityAdsDelegate <NSObject>
- (void)unityAdsReady:(NSString *)placementId;
- (void)unityAdsDidError:(NSInteger)error withMessage:(NSString *)message;
- (void)unityAdsDidStart:(NSString *)placementId;
- (void)unityAdsDidFinish:(NSString *)placementId withFinishState:(NSInteger)state;
@end

@protocol UADSPlayerMetaData<NSObject>
- (BOOL)set:(NSString *)key value:(id)value;
- (void)setServerId:(NSString *)serverId;
- (void)commit;
@end

@protocol UADSBannerViewDelegate;
@protocol UADSBannerView <NSObject>
@property(nonatomic, readonly) CGSize size;
@property(nonatomic, readwrite, nullable, weak) NSObject <UADSBannerViewDelegate> *delegate;
@property(nonatomic, readonly) NSString *placementId;
-(instancetype)initWithPlacementId:(NSString *)placementId size:(CGSize)size;
-(void)load;
@end

typedef NS_ENUM(NSInteger, ATUADSBannerErrorCode) {
    UADSBannerErrorCodeUnknown = 0,
    UADSBannerErrorCodeNativeError = 1,
    UADSBannerErrorCodeWebViewError = 2,
    UADSBannerErrorCodeNoFillError = 3
};

@protocol UADSBannerError <NSObject>
- (instancetype)initWithCode:(ATUADSBannerErrorCode)code userInfo:(nullable NSDictionary<NSErrorUserInfoKey, id> *)dict;
@end

@protocol UADSBannerViewDelegate <NSObject>
@optional
- (void)bannerViewDidLoad:(id<UADSBannerView>)bannerView;
- (void)bannerViewDidClick:(id<UADSBannerView>)bannerView;
- (void)bannerViewDidLeaveApplication:(id<UADSBannerView>)bannerView;
- (void)bannerViewDidError:(id<UADSBannerView>)bannerView error:(NSError *)error;
@end
