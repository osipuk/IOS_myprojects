//
//  AppotaUtil.h
//  AppotaSDK
//
//  Created by tuent on 10/1/13.
//
//

#import <Foundation/Foundation.h>

@class AppotaPaymentController;

@interface AppotaUtil : NSObject
+ (NSBundle *)frameworkBundle;
+(UIImage *)imageWithNamed:(NSString *)imgName ofType:(NSString *)extension;
+ (UIImage*) imageNamed:(NSString*) imageName;
+ (UIViewController *) firstAvailableUIViewController:(UIView*) v;
+ (CGSize) getWindowSize;
+ (CGRect) getKeyWindowFrame;
+ (CGRect) getViewFrameWithSize:(CGSize) imageSize;
+ (NSArray*) getListSMSOptionWithSMSListAmount:(NSArray*) listSMSAmount
                          withSMSStructureDict:(NSDictionary*) smsDict;
+(void) alertWithTitle:(NSString*) alertTitle
           withMessage:(NSString*) alertMessage;
+ (UIView*) getSMSViewWithText:(NSString*) smsText
                    withRecpit:(NSString*) smsRecpt
                withController:(AppotaPaymentController*) controller
                     withFrame:(CGRect) viewFrame;
+ (NSArray*) getArrayOfDescriptionFromString:(NSString*) descriptionString;

+ (void) setLanguageForView:(UIView*) v;

+ (void) moveViewWithX:(float) xChange
              withView:(UIView*) view;
+ (BOOL) AppotaIsDeviceIPad;
+ (BOOL) isIphone4;
+ (BOOL) isLandscape;
+ (UIView*) findMatchSuperViewWithSender:(id) sender
                           withSuperView:(Class) viewClass;
+ (void) saveAndResetStatusBarState;
+ (BOOL) getStatusBarState;
+ (void) showStatusBar;
+ (void) hideStatusBar;
+ (CGAffineTransform)transformForOrientation;
@end
