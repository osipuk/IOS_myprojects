//
//  AppotaPaymentController.h
//  AppotaSDK
//
//  Created by tuent on 10/14/13.
//
//

#import <Foundation/Foundation.h>
#import <MessageUI/MessageUI.h>
#import "AppotaPayment.h"

@class AppotaPaymentDialog;

@interface AppotaPaymentController : NSObject <MFMessageComposeViewControllerDelegate>
{
    NSTimer *transTimer;
    int checkTime;
}
@property (nonatomic, unsafe_unretained) NSString *inAppId;
@property (nonatomic, unsafe_unretained) AppotaPaymentHandler paymentHandler;
@property (nonatomic, unsafe_unretained) AppotaPaymentDialog *paymentDialog;
@property (readwrite) BOOL enableHideDialog;
@end
