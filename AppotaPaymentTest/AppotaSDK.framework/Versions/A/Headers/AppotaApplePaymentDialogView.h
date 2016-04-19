//
//  AppotaApplePaymentDialogView.h
//  AppotaSDK
//
//  Created by tuent on 10/30/13.
//
//

#import "AppotaPaymentPaypalDialogView.h"

@interface AppotaApplePaymentDialogView : AppotaPaymentPaypalDialogView
- (void) setupViewWithListItem:(NSArray*) listIAPItem
               withDescription:(NSString*) description
                    withDialog:(AppotaPaymentDialog*) paymentDialog;
@end
