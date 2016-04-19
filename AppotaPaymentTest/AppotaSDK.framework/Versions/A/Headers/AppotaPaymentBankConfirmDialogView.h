//
//  AppotaPaymentBankConfirmDialogView.h
//  AppotaSDK
//
//  Created by tuent on 10/21/13.
//
//

#import "AppotaPaymentDialogView.h"

@interface AppotaPaymentBankConfirmDialogView : AppotaPaymentDialogView {
    
    __unsafe_unretained IBOutlet UIButton *confirmBankButton;
    __unsafe_unretained IBOutlet UITextView *shortLinkUITextView;
}
- (void) setupPCConfirmViewWithShortLink:(NSString*) shortLink;
- (void) setupMobileConfirmView;
- (void) setupConfirmViewWitType:(NSString*) confirmType
                         withURL:(NSString*) url;
@end
