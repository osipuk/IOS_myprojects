//
//  AppotaPaymentDiaglogView.h
//  AppotaSDK
//
//  Created by tuent on 10/9/13.
//
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>
#import "AppotaPaymentDialogView.h"

@class AppotaPaymentDialog;

@interface AppotaPaymentSMSDialogView : AppotaPaymentDialogView
{
    // SMS variable
    __unsafe_unretained IBOutlet UIScrollView *paymentItemscrollView;
    __unsafe_unretained IBOutlet UIImageView *scrollViewBackground;
    __unsafe_unretained IBOutlet UITextView *smsSyntaxTextView;
    NSArray *listSMSOption;
    MFMessageComposeViewController *viewController;
    NSString *inAppId;
}

//- (void) setupViewWithSMSStructureDict:(NSDictionary*) smsDict;
- (void) setupViewWithSMSStructureDict:(NSDictionary*) smsDict
                     withListSMSAmount:(NSArray*) listSMSAmount
                       withDescription:(NSString*) description
                            withDialog:(AppotaPaymentDialog*) paymentDialog;
@end
