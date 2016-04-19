//
//  AppotaPaymentCardDialogView.h
//  AppotaSDK
//
//  Created by tuent on 10/17/13.
//
//

#import "AppotaPaymentDialogView.h"
#import "AppotaDropDown.h"
@interface AppotaPaymentCardDialogView : AppotaPaymentDialogView <AppotaDropDownDelegate, UITextFieldDelegate, UIScrollViewDelegate>
{
    __unsafe_unretained IBOutlet UILabel *chooseVendorLabel;

    __unsafe_unretained IBOutlet UIView *paymentDetailBackGroundView;
    __unsafe_unretained IBOutlet UITextField *serialTextField;
    __unsafe_unretained IBOutlet UITextField *codeTextField;
    
    __unsafe_unretained IBOutlet UIImageView *serialTextFieldImageView;
    __unsafe_unretained IBOutlet UIImageView *codeTextFieldImageView;
    __unsafe_unretained IBOutlet UIButton *payButton;
    
    
    AppotaDropDown *chooseVendorDropdown;
    NSArray *listPhoneCard;
    NSArray *listPhoneCardVendor;
}


@property (unsafe_unretained, nonatomic) IBOutlet UIButton *openVendorButton;
- (IBAction)openVendor:(id)sender;
- (void) updatePayButtonDictionary;
@end
