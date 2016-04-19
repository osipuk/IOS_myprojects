//
//  AppotaPaymentBankInputDialogView.h
//  AppotaSDK
//
//  Created by tuent on 10/21/13.
//
//

#import "AppotaPaymentDialogView.h"
#import "AppotaPaymentBankDialogView.h"

@interface AppotaPaymentBankInputDialogView : AppotaPaymentBankDialogView <UITextFieldDelegate>{
    
    __unsafe_unretained IBOutlet UIImageView *inputValueImageView;
    __unsafe_unretained IBOutlet UITextField *inputValueTextField;
    __unsafe_unretained IBOutlet UIButton *currencyBtn;
}
- (IBAction)updateCurrency:(id)sender;
- (NSDictionary*) getPaymentData;
- (void) setupPaymentFixedWithInput:(int) inputValue;
@end
