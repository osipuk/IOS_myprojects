//
//  AppotaSMSDialogCell.h
//  AppotaSDK
//
//  Created by tuent on 10/16/13.
//
//

#import <UIKit/UIKit.h>

@interface AppotaSMSDialogCell : UIButton {
    NSDictionary *smsDict;
    NSString *inAppID;
}

+ (AppotaSMSDialogCell*) getDialogCell;

@property (unsafe_unretained, nonatomic) IBOutlet UILabel *smsNumberLabel;
@property (unsafe_unretained, nonatomic) IBOutlet UILabel *smsMoneyLabel;
- (void) setUpCellWithSMSDict:(NSDictionary*) smsDict_
                  withInAppID:(NSString*) inAppID_;


- (NSDictionary *)smsDict;

- (void)setSmsDict:(NSDictionary *)newValue;

- (NSString *)inAppID;

- (void)setInAppID:(NSString *)newValue;

@end
