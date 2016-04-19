//
//  AppotaPaymentDialogView.h
//  AppotaSDK
//
//  Created by tuent on 10/17/13.
//
//

#import <UIKit/UIKit.h>
#import "AppotaPopoverView.h"
@class AppotaPaymentDialog;
@interface AppotaPaymentDialogView : UIView <AppotaPopoverViewDelegate>{
    __unsafe_unretained IBOutlet UIView *tabBarView;
    __unsafe_unretained IBOutlet UIImageView *iconImageView;
    __unsafe_unretained IBOutlet UITextView *paymentDetailTextView;
    __unsafe_unretained IBOutlet UIButton *paymentDetailButton;
    __unsafe_unretained IBOutlet UIButton *backPaymentButton;
    __unsafe_unretained IBOutlet UILabel *titleLabel;
    __unsafe_unretained IBOutlet UIImageView *tabBarIconImageView;
    __unsafe_unretained IBOutlet UIScrollView *descriptionScrollView;
    
    __unsafe_unretained IBOutlet UIButton *dropInForButton;
    UIButton *chooseLangButton;
    __unsafe_unretained IBOutlet UIScrollView *landscapeContentScrollView;
}
- (void) adjustLandscapeIphone4WithListView:(NSArray*) listMoveView;
- (void) addChooseLanguageButton;
- (void) adjustPaymentDetail;
- (IBAction)showPaymentDetailDescription:(id)sender;
- (void) setUpViewWithTitle:(NSString*) title
            withDescription:(NSString*) description
          withPaymentDialog:(AppotaPaymentDialog*) paymentDialog;
- (void) setUpLandscapeXibWithHeight:(float) height;
@end
