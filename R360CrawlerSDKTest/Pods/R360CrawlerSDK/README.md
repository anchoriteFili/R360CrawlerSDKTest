# R360CrawlerSDK
a crawler sdk of rong360

Switft配置

****** 必须用1.1.8和以后的pod库

1、建立一个头文件例如：RDPCrawlerBridg.h

2、在头文件里引入 #import <RDPCrawlerSDK/RDPCrawlerManager.h>

3、点击工程配置yourTarget->build setting -> Objective-c Bridging Header -> xxxTarget/RDPCrawlerBridg.h(xxxTarget为你的工程的名字)

接入步骤：

支持的iOS最低版本7.0, Xcode 8.0

需要先申请appid, 配置好相应的证书和回调url

1.在Podfile文件里添加 pod 'R360CrawlerSDK', 然后pod update(需更新下本地pod仓库，避免本地仓库不包含sdk的信息)



2.权限配置

a.如果支持了ATS, 需要对uiwebview放开限制

	<key>NSAllowsArbitraryLoadsInWebContent</key>
	<true/>

b.如果使用支付宝抓取，需要在工程中的info.plist中的添加LSApplicationQueriesSchemes数组,在数组里面添加一个支持的scheme:alipayqr

	<key>LSApplicationQueriesSchemes</key>
	<array>
		<string>alipayqr</string>
	</array>

c.使用运营商时，如果支持了ATS,需要对以下域名放开限制

10086.cn,

10010.com,

189.cn,

chinamobile.com,

telecomjs.com,

ct10000.com,

chinatelecom-ec.com


plist配置：

    <key>NSAppTransportSecurity</key>
	<dict>
		<key>NSExceptionDomains</key>
		
		<dict>
		
			<key>10086.cn</key>
			<dict>
				<key>NSExceptionAllowsInsecureHTTPLoads</key>
				<true/>
				<key>NSExceptionMinimumTLSVersion</key>
				<string>TLSv1.0</string>
				<key>NSExceptionRequiresForwardSecrecy</key>
				<false/>
				<key>NSIncludesSubdomains</key>
				<true/>
			</dict>
			
			<key>10010.com</key>
			<dict>
				<key>NSExceptionAllowsInsecureHTTPLoads</key>
				<true/>
				<key>NSExceptionMinimumTLSVersion</key>
				<string>TLSv1.0</string>
				<key>NSExceptionRequiresForwardSecrecy</key>
				<false/>
				<key>NSIncludesSubdomains</key>
				<true/>
			</dict>
			
			<key>189.cn</key>
			<dict>
				<key>NSExceptionAllowsInsecureHTTPLoads</key>
				<true/>
				<key>NSExceptionMinimumTLSVersion</key>
				<string>TLSv1.0</string>
				<key>NSExceptionRequiresForwardSecrecy</key>
				<false/>
				<key>NSIncludesSubdomains</key>
				<true/>
			</dict>
			
			<key>chinamobile.com</key>
			<dict>
				<key>NSExceptionAllowsInsecureHTTPLoads</key>
				<true/>
				<key>NSExceptionMinimumTLSVersion</key>
				<string>TLSv1.0</string>
				<key>NSExceptionRequiresForwardSecrecy</key>
				<false/>
				<key>NSIncludesSubdomains</key>
				<true/>
			</dict>
			
			<key>telecomjs.com</key>
			<dict>
				<key>NSExceptionAllowsInsecureHTTPLoads</key>
				<true/>
				<key>NSExceptionMinimumTLSVersion</key>
				<string>TLSv1.0</string>
				<key>NSExceptionRequiresForwardSecrecy</key>
				<false/>
				<key>NSIncludesSubdomains</key>
				<true/>
			</dict>
			
			<key>ct10000.com</key>
			<dict>
				<key>NSExceptionAllowsInsecureHTTPLoads</key>
				<true/>
				<key>NSExceptionMinimumTLSVersion</key>
				<string>TLSv1.0</string>
				<key>NSExceptionRequiresForwardSecrecy</key>
				<false/>
				<key>NSIncludesSubdomains</key>
				<true/>
			</dict>
			
			<key>chinatelecom-ec.com</key>
			<dict>
				<key>NSExceptionAllowsInsecureHTTPLoads</key>
				<true/>
				<key>NSExceptionMinimumTLSVersion</key>
				<string>TLSv1.0</string>
				<key>NSExceptionRequiresForwardSecrecy</key>
				<false/>
				<key>NSIncludesSubdomains</key>
				<true/>
			</dict>
			
		</dict>
		
		<key>NSAllowsArbitraryLoadsInWebContent</key>
		<true/>
		<key>NSPhotoLibraryUsageDescription</key>
		<string>访问相册</string>
		
	</dict>




3.初始化sdk, 调用接口传入appid和对应的p12格式的私钥    

  	NSString *keyPath = [[NSBundle mainBundle] pathForResource:@"private" ofType:@"p12"];

 	NSData *keyData = [NSData dataWithContentsOfFile:keyPath];

  如私钥文件没有设置密码调用以下方法：
  
  	[RDPCrawlerManager configAppId:@"申请的appid" delegate:self privateKey:keyData];
 
  如私钥文件设置了密码调用另一个方法:
  
  	[RDPCrawlerManager configAppId:@"申请的appid" delegate:self privateKey:keyData password:@"私钥密码"];
  

4.调用所需类型的抓取服务
  
  通过创建RDPC_Config来调用抓取服务，实例如下
    
    
    RDPC_Config *config = [RDPC_Config new];
    //配置抓取项
    config.phone = @"13812345678";
    config.canEditPhone = YES;
    config.taskId = @“1111”;
    config.type = kCrawlerTypeAlipay;
    config.addtionParams = nil;
    //启动抓取
    [RDPCrawlerManager startCrawler:config];
 
 具体抓取项如下所示
 
     /
     **
     手机号，必选参数
     */
    @property (nonatomic, copy) NSString *phone;
    
    /**
     是否能修改手机号，默认YES
     */
    @property (nonatomic, assign) BOOL canEditPhone;
    
    /**
     和手机号匹配的姓名，必填
     */
    @property (nonatomic, copy) NSString *userName;
    
    /**
     和手机号匹配的身份证号，必填
     */
    @property (nonatomic, copy) NSString *idNo;
    
    /**
     抓取任务的唯一标志符
     */
    @property (nonatomic, copy) NSString *taskId;
    
    /**
     传入的附加参数
     */
    @property (nonatomic, strong) NSDictionary *addtionParams;
    
    /**
     抓取类型
     */
    @property (nonatomic, assign) kRDPCrawlerType type;
  
  抓取类型如下所示
    
    typedef NS_ENUM(NSUInteger, kRDPCrawlerType) {
        kRDPCrawlerTypeAlipay = 1,//支付宝抓取
        kRDPCrawlerTypeTaobao = 2,//淘宝抓取
        kRDPCrawlerTypeOperator = 3,//运营商抓取
        kRDPCrawlerTypeEmail = 4,//邮箱抓取
    };

  
5.抓取结果
	在抓取结果类实现RDPCrawlerDelegate，协议，并且实现协议的具体方法,其中RDPCrawlerItem.addtionParams 为抓取任务开始时传入的addtionalParams参数。
	
	- (void)crawlerChangeStatus:(RDPCrawlerItem *)statusItem {
    switch (statusItem.status) {
        case kRDPCrawlerStatusStart:
            NSLog(@"分配到serverId,开始抓取");
            break;
        case kRDPCrawlerStatusLoginSuccess:
            NSLog(@"登录成功");
            break;
        case kRDPCrawlerStatusFetchSuccess:
            NSLog(@"获取数据成功, 抓取完成");
            break;
        case kRDPCrawlerStatusFailed:
            NSLog(@"出现错误:%@", statusItem.error.domain);
            break;
        case kRDPCrawlerStatusCancel:
            NSLog(@"用户手动取消任务");
            break;
        default:
            break;
    	}
	}


6.界面自定义
	目前sdk支持界面部分元素进行自定义，主要包括顶部导航栏背景色，导航栏文字字号以及颜色。运营商页面提交按钮颜色和按钮文字颜色，当未设置时，则使用默认颜色。具体如下

	+ (void)setNavigationColor:(UIColor *)navigationColor;//设置导航栏背景色

	+ (void)setNavigationTitleFont:(UIFont *)font;//设置导航栏字体

	+ (void)setNavigationTitleColor:(UIColor *)titleColor;//导航栏字体颜色

	+ (void)setSubmitButtonColor:(UIColor *)buttonColor;//运营商，邮箱底部提交按钮颜色

	+ (void)setSubmitButtonHighLightColor:(UIColor *)buttonHighLightColor;//运营商，邮箱底部提交按钮高亮颜色,当未设置按钮颜色时，改属性不起作用

	+ (void)setSubmitButtonTitleColor:(UIColor *)titleColor;//运营商，邮箱底部提交底部按钮文字颜色，当未设置按钮颜色时，改属性不起作用


  ps:
  
    如需使用测试环境联调，需调用[RDPCrawlerManager setIsDebug:YES]

    pem转p12的步骤，需在终端输入如下命令:

    如pem文件为private.pem

    
    (1) 生成一个csr文件

      openssl req -new -key private.pem -out rsacert.csr

      这时候要求输入以下一些证书配置信息

      Country Name (2 letter code) [AU]:CN

      State or Province Name (full name) [Some-State]:beijing

      Locality Name (eg, city) []:beijing

      Organization Name (eg, company) [Internet Widgits Pty Ltd]:Rong360

      Organizational Unit Name (eg, section) []:com

      Common Name (e.g. server FQDN or YOUR name) []:R360

      Email Address []:whj5484138@gmail.com

      Please enter the following 'extra' attributes

      to be sent with your certificate request

      A challenge password []:

      An optional company name []:



   (2)生成证书并且签名,有效期10年

      openssl x509 -req -days 3650 -in rsacert.csr -signkey private.pem -out rsacert.crt


   (3)生成P12文件

      openssl pkcs12 -export -out private.p12 -inkey private.pem -in rsacert.crt

 


