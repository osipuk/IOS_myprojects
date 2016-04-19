//
//  AppotaPaymentPaypalConfirmDialogView.h
//  AppotaSDK
//
//  Created by tuent on 10/18/13.
//
//

#import "AppotaPaymentDialogView.h"

@interface AppotaPaymentPaypalConfirmDialogView : AppotaPaymentDialogView{
    
    __unsafe_unretained IBOutlet UIButton *confirmPaypalBtn;
    __unsafe_unretained IBOutlet UIButton *resendPaypalBtn;
}

@end
