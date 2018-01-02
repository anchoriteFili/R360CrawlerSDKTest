//
//  RDPCrawlerManager.h
//  Pods
//  version 1.1.3 
//  Created by whj on 16/10/10.
//
//

#import <Foundation/Foundation.h>
#import "RDPCrawlerItem.h"

@protocol RDPCrawlerDelegate <NSObject>


/**
 抓取状态改变的回调

 @param statusItem 抓取状态的item
 */
- (void)crawlerChangeStatus:(RDPCrawlerItem *)statusItem;

@optional
/**
 抓取页面Dissmiss的回调
 */
- (void)didControllerDismiss:(RDPCrawlerItem *)statusItem;

@end

@interface RDPCrawlerManager : NSObject


/**
 配置sdk必需信息

 @param appId    appId
 @param delegate delegate
 @param key      私钥证书(.p12文件转成的NSData)
 */
+ (void)configAppId:(NSString *)appId delegate:(id<RDPCrawlerDelegate>)delegate privateKey:(NSData *)key;


/**
 配置sdk必需信息

 @param appId    appId
 @param delegate delegate
 @param key      私钥证书(.p12文件转成的NSData)
 @param password 私钥证书密码
 */
+ (void)configAppId:(NSString *)appId delegate:(id<RDPCrawlerDelegate>)delegate privateKey:(NSData *)key password:(NSString *)password;


/**
 启动抓取服务
 
 @param config          抓取配置信息
 */
+ (void)startCrawler:(RDPC_Config *)config;

/**
 配置可选信息
 
 @param appName app名称
 */
+ (void)configOptionalAppName:(NSString *)appName;


/**
 设置抓取过程的超时时间（默认为1800S）

 @param second 超时时间(单位为秒)
 */
+ (void)setTimeoutSecond:(NSInteger)second;


/**
 设置是否使用测试环境
 
 @param isDebug isDebug
 */
+ (void)setIsDebug:(BOOL)isDebug;

/**
 设置请求失败时是否输出日志信息，协助定位问题
 
 @param isShow 是否输出
 */
+ (void)showErrorLogs:(BOOL)isShow;


/**
 设置顶部头颜色
 
 @param navigationColor 顶部头颜色
 */
+ (void)setNavigationColor:(UIColor *)navigationColor;

/**
 设置导航栏字体
 
 @param font 导航栏字体
 */
+ (void)setNavigationTitleFont:(UIFont *)font;

/**
 设置导航栏字体颜色
 
 @param titleColor 字体颜色
 */
+ (void)setNavigationTitleColor:(UIColor *)titleColor;

/**
 运营商，邮箱底部提交按钮颜色
 
 @param buttonColor 运营商，邮箱底部按钮颜色
 */
+ (void)setSubmitButtonColor:(UIColor *)buttonColor;

/**
 运营商，邮箱底部提交底部按钮高亮颜色
 
 @param buttonHighLightColor 运营商，邮箱底部按钮高亮颜色
 */
+ (void)setSubmitButtonHighLightColor:(UIColor *)buttonHighLightColor;

/**
 运营商，邮箱底部提交底部按钮文字颜色
 
 @param titleColor  运营商，邮箱底部提交底部按钮文字颜色
 */
+ (void)setSubmitButtonTitleColor:(UIColor *)titleColor;


@end
