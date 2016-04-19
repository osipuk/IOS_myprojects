//
//  AppotaPaymentPaypalInputDialogView.h
//  AppotaSDK
//
//  Created by tuent on 10/18/13.
//
//

#import "AppotaPaymentDialogView.h"

@interface AppotaPaymentPaypalInputDialogView : AppotaPaymentDialogView <UITextFieldDelegate>
@property (unsafe_unretained, nonatomic) IBOutlet UIButton *paypalInputPayButton;

@property (unsafe_unretained, nonatomic) IBOutlet UITextField *amountTextField;
@property (unsafe_unretained, nonatomic) IBOutlet UIButton *usdBtn;
- (void) updatePayButtonDictionary;
@end
