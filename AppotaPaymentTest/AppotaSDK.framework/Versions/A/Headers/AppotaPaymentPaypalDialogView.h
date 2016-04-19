//
//  AppotaPaymentPaypalDialogView.h
//  AppotaSDK
//
//  Created by tuent on 10/18/13.
//
//

#import "AppotaPaymentDialogView.h"

@interface AppotaPaymentPaypalDialogView : AppotaPaymentDialogView
{
    __unsafe_unretained IBOutlet UIScrollView *paymentItemscrollView;
    __unsafe_unretained IBOutlet UIImageView *scrollViewBackground;
}
- (void) setupViewWithListAmount:(NSArray*) listAmount
                 withDescription:(NSString*) description
                      withDialog:(AppotaPaymentDialog*) paymentDialog;
@end
