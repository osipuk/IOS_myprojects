//
//  ViewController.m
//  AppotaPaymentSDKTest
//
//  Created by tuent on 10/1/13.
//
//

#import "ViewController.h"
#import <AppotaSDK/AppotaSDK.h>
#import "AppDelegate.h"

@interface ViewController ()

@end

@implementation ViewController

- (void) configAppotaSDK {
    AppotaPayment *appotaAPI = [AppotaPayment shareAPI];
    
    appotaAPI.clientID = CLIENT_ID;
    appotaAPI.clientSecret = CLIENT_SECRET;
    appotaAPI.inappKey = INAPP_API_KEY;
    appotaAPI.debugMode = YES;
    // Config for sandbox app
    // For sandbox app comment above code and uncomment this part
    //    appotaAPI.clientID = SANDBOX_CLIENT_ID;
    //    appotaAPI.clientSecret = SANDBOX_CLIENT_SECRET;
    //    appotaAPI.inappKey = SANDBOX_INAPP_API_KEY;
    
}


- (void)viewDidLoad
{
    [super viewDidLoad];
    [self configAppotaSDK];
    
    //    [[AppotaPaymentAPI shareAPI] addAppotaTopUpWithHandler:^(BOOL status, NSDictionary *resultDict, AppotaTopupErrorCode error_code) {
    //
    //    }];
    //    AppotaDialog* topupView = [[AppotaTopupView alloc] initWithURL:[self getTopupTymURL] params:nil isViewInvisible:NO delegate:nil];
    //    topupView.callbackURI = [NSString stringWithFormat:@"%@%@", APPOTA_SCHEMA, _clientID];
    //    topupView.topupViewType = AppotaTopupTym;
    //    __block id _this = self;
    //    [topupView addCompletionHandler:^(BOOL status, NSDictionary *resultDict, AppotaTopupErrorCode error_code) {
    //        [_this updateNewTokenFromTopupDictionary:resultDict];
    //        completionBlock(status, resultDict, error_code);
    //    }];
    //    [topupView show];
    //    return topupView;
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)openDialog:(id)sender {
	// Do any additional setup after loading the view, typically from a nib.
    //    AppotaDialog *diaglog = [[AppotaDialog alloc] init];
    //    [diaglog show];
//    AppotaPaymentDialog *diaglog = [[AppotaPaymentDialog alloc] init];
//    [diaglog showSMSPaymentDialog];
//    [diaglog showPaypalPaymentDiaglog];

//    [appotaPayment makeSMSPaymentWithAmount:500 withState:@"" withTarget:@"" withNoticeURL:@"" withCompletionHandler:^(NSDictionary *apiDict, AppotaPaymentState status, NSError *error) {
//        
//    }];

}

- (IBAction)makeApplePaymentWithList:(id)sender {
    // IAP list
    // com.testsdknofb.muamotlan1
    // com.testsdknofb.muanhieulan1
    AppotaAppleIAPItem *iapItem = [[AppotaAppleIAPItem alloc] initWithProductID:@"com.testsdknofb.muamotlan1" withPrice:0.99f withDescription:@"Mua nhieu lan $1"];
    AppotaAppleIAPItem *iapItem2 = [[AppotaAppleIAPItem alloc] initWithProductID:@"com.testsdknofb.muanhieulan1" withPrice:0.99f withDescription:@"Mua nhieu lan $1"];
    
    AppotaPayment *appotaPayment = [AppotaPayment shareAPI];
    [appotaPayment makeApplePaymentWithListItem:[NSArray arrayWithObjects:iapItem, iapItem2, nil] withState:@"" withTarget:@"" withNoticeUrl:@"" withDescription:@"$1 for 100 coin\n$2 for 1000 coin" withCompletionHandler:^(NSDictionary *apiDict, AppotaPaymentState status, NSError *error) {
        [AppotaProgressView hideAllHUDsForView:self.view animated:YES];
        if (status == AppotaPaymentSucceed && [[apiDict objectForKey:@"status"] intValue] == 1) {
        }
        else {
            if (status != AppotaPaymentClosed) {
                [AppotaUtil alertWithTitle:@"" withMessage:[AppotaPaymentSDKLanguage get:@"Giao dịch thất bại"]];                
            }
        }
    }];
}

- (IBAction)makeApplePayment:(id)sender {
    // IAP list
    // com.testsdknofb.muamotlan1
    // com.testsdknofb.muanhieulan1
    AppotaAppleIAPItem *iapItem = [[AppotaAppleIAPItem alloc] initWithProductID:@"com.testsdknofb.muamotlan1" withPrice:0.99f withDescription:@"Mua nhieu lan"];

    AppotaPayment *appotaPayment = [AppotaPayment shareAPI];
    appotaPayment.debugMode = YES;
    
    [AppotaProgressView showHUDAddedTo:self.view animated:YES];
    [appotaPayment makeApplePaymentWithItem:iapItem withState:@"" withTarget:@"" withNoticeUrl:@"" withDescription:@"" withCompletionHandler:^(NSDictionary *apiDict, AppotaPaymentState status, NSError *error) {
        [AppotaProgressView hideAllHUDsForView:self.view animated:YES];
        if (status == AppotaPaymentSucceed && [[apiDict objectForKey:@"status"] intValue] == 1) {
            [AppotaUtil alertWithTitle:@"" withMessage:[NSString stringWithFormat:@"%@ %@",[AppotaPaymentSDKLanguage get:@"Mua"], [[apiDict objectForKey:@"data"] objectForKey:@"product_id"]]];
        }
        else {
            [AppotaUtil alertWithTitle:@"" withMessage:[AppotaPaymentSDKLanguage get:@"Giao dịch thất bại"]];
        }
    }];
}

- (IBAction)showBankWithListAmount:(id)sender {
    AppotaPayment *appotaPayment = [AppotaPayment shareAPI];
    appotaPayment.debugMode = YES;
    [appotaPayment makeBankPaymentWithListAmount:[NSArray arrayWithObjects:[NSNumber numberWithFloat:1000.0f], [NSNumber numberWithFloat:2000.0f], [NSNumber numberWithFloat:5000.0f], [NSNumber numberWithFloat:10000.0f], [NSNumber numberWithFloat:20000.0f], [NSNumber numberWithFloat:40000.0f], nil] withState:@"" withTarget:@"" withNoticeUrl:@"" withDescription:@"$1 for 100 coin\n$2 for 1000 coin" withCompletionHandler:^(NSDictionary *apiDict, AppotaPaymentState status, NSError *error) {
        if(status == AppotaPaymentInvalidAmount) {
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"" message:[AppotaPaymentSDKLanguage get:@"Nhập số tiền phù hợp"] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
            [alert show];
        }
        if (status == AppotaPaymentSucceed) {
            [[[UIAlertView alloc] initWithTitle:[AppotaPaymentSDKLanguage get:@"Thông báo"]
                                        message:[AppotaPaymentSDKLanguage get:@"Nạp tiền thành công."]
                                       delegate:nil
                              cancelButtonTitle:@"OK" otherButtonTitles:nil, nil] show];
        }
    }]; 
}


- (IBAction)showBankWithAmount:(id)sender {
    AppotaPayment *appotaPayment = [AppotaPayment shareAPI];
    appotaPayment.debugMode = YES;
    [appotaPayment makeBankPaymentWithAmount:20000 withState:@"" withTarget:@"" withNoticeUrl:@"" withDesciption:@"$1 for 100 coin\n$2 for 1000 coin"  withCompletionHandler:^(NSDictionary *apiDict, AppotaPaymentState status, NSError *error) {
        if (status == AppotaPaymentSucceed) {
            if(status == AppotaPaymentInvalidAmount) {
                UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"" message:[AppotaPaymentSDKLanguage get:@"Nhập số tiền phù hợp"] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
                [alert show];
            }
            [[[UIAlertView alloc] initWithTitle:[AppotaPaymentSDKLanguage get:@"Thông báo"]
                                        message:[AppotaPaymentSDKLanguage get:@"Nạp tiền thành công."]
                                       delegate:nil
                              cancelButtonTitle:@"OK" otherButtonTitles:nil, nil] show];
        }
    }];
}

- (IBAction)showBankWithInputAmount:(id)sender {
    AppotaPayment *appotaPayment = [AppotaPayment shareAPI];
    appotaPayment.debugMode = YES;
    [appotaPayment makeBankPaymentWithState:@"" withTarget:@"" withNoticeUrl:@"" withDescription:@"$1 for 100 coin\n$2 for 1000 coin" withCompletionHandler:^(NSDictionary *apiDict, AppotaPaymentState status, NSError *error) {
        if(status == AppotaPaymentInvalidAmount) {
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"" message:[AppotaPaymentSDKLanguage get:@"Nhập số tiền phù hợp"] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
            [alert show];
        }
        if (status == AppotaPaymentSucceed) {
            [[[UIAlertView alloc] initWithTitle:[AppotaPaymentSDKLanguage get:@"Thông báo"]
                                        message:[AppotaPaymentSDKLanguage get:@"Nạp tiền thành công."]
                                       delegate:nil
                              cancelButtonTitle:@"OK" otherButtonTitles:nil, nil] show];
        }
    }];    
}

- (IBAction)showPaypalWithInputAmount:(id)sender {
    AppotaPayment *appotaPayment = [AppotaPayment shareAPI];
    appotaPayment.debugMode = YES;
    [appotaPayment makePaypalPaymentWithState:@"" withTarget:@"" withNoticeUrl:@"" withDescription:@"$1 for 100 coin\n$2 for 1000 coin" withCompletionHandler:^(NSDictionary *apiDict, AppotaPaymentState status, NSError *error) {
        if(status == AppotaPaymentInvalidAmount) {
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"" message:[AppotaPaymentSDKLanguage get:@"Nhập số tiền phù hợp"] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
            [alert show];
        }
        if (status == AppotaPaymentSucceed) {
            [[[UIAlertView alloc] initWithTitle:[AppotaPaymentSDKLanguage get:@"Thông báo"]
                                        message:[AppotaPaymentSDKLanguage get:@"Nạp tiền thành công."]
                                       delegate:nil
                              cancelButtonTitle:@"OK" otherButtonTitles:nil, nil] show];
        }
    }];    
}

- (IBAction)showPaypalWithListAmount:(id)sender {
    AppotaPayment *appotaPayment = [AppotaPayment shareAPI];
    appotaPayment.debugMode = YES;
    [appotaPayment makePaypalPaymentWithListAmount:[NSArray arrayWithObjects:[NSNumber numberWithFloat:1.0f], [NSNumber numberWithFloat:2.0f], [NSNumber numberWithFloat:5.0f], [NSNumber numberWithFloat:10.0f], [NSNumber numberWithFloat:20.0f], [NSNumber numberWithFloat:40.0f], nil] withState:@"" withTarget:@"" withNoticeUrl:@"" withDescription:@"$1 for 100 coin\n$2 for 1000 coin" withCompletionHandler:^(NSDictionary *apiDict, AppotaPaymentState status, NSError *error) {
        if(status == AppotaPaymentInvalidAmount) {
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"" message:[AppotaPaymentSDKLanguage get:@"Nhập số tiền phù hợp"] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
            [alert show];
        }
        if (status == AppotaPaymentSucceed) {
            [[[UIAlertView alloc] initWithTitle:[AppotaPaymentSDKLanguage get:@"Thông báo"]
                                        message:[AppotaPaymentSDKLanguage get:@"Nạp tiền thành công."]
                                       delegate:nil
                              cancelButtonTitle:@"OK" otherButtonTitles:nil, nil] show];
        }        
    }];
}

- (IBAction)showPaypalWithAmount:(id)sender {
    AppotaPayment *appotaPayment = [AppotaPayment shareAPI];
    appotaPayment.debugMode = YES;    
    [appotaPayment makePaypalPaymentWithAmount:1.0f withState:@"" withTarget:@"" withNoticeUrl:@"" withCompletionHandler:^(NSDictionary *apiDict, AppotaPaymentState status, NSError *error) {
        if(status == AppotaPaymentInvalidAmount) {
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"" message:[AppotaPaymentSDKLanguage get:@"Nhập số tiền phù hợp"] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
            [alert show];
        }
        if (status == AppotaPaymentSucceed) {
            [[[UIAlertView alloc] initWithTitle:[AppotaPaymentSDKLanguage get:@"Thông báo"]
                                        message:[AppotaPaymentSDKLanguage get:@"Nạp tiền thành công."]
                                       delegate:nil
                              cancelButtonTitle:@"OK" otherButtonTitles:nil, nil] show];
        }
    }];
}

- (IBAction)showCardWithListVendor:(id)sender {
    AppotaPayment *appotaPayment = [AppotaPayment shareAPI];
    [appotaPayment makeCardPaymentWithState:@""
                                 withTarget:@""
                              withNoticeUrl:@""
                            withDescription:@"Vinaphone - 50k\nViettel - 70 k"
                      withCompletionHandler:^(NSDictionary *apiDict, AppotaPaymentState status, NSError *error) {
        if (status == AppotaPaymentSucceed) {
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"" message:[AppotaPaymentSDKLanguage get:@"Nạp tiền thành công."] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
            [alert show];
        }
        else if(status != AppotaPaymentClosed){
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"" message:[apiDict objectForKey:@"message"] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
            [alert show];            
        }
    }];
}

- (void) handleSMSPaymentResultDict:(NSDictionary*) resultDict
                   withPaymentState:(AppotaPaymentState) paymentState {
    if (paymentState == AppotaPaymentSucceed) {
        [[[UIAlertView alloc] initWithTitle:[AppotaPaymentSDKLanguage get:@"Thông báo"]
                                    message:[AppotaPaymentSDKLanguage get:@"Nạp tiền thành công."]
                                   delegate:nil
                          cancelButtonTitle:@"OK" otherButtonTitles:nil, nil] show];
    }
    else {
        if (paymentState == AppotaPaymentSMSPending) {
            [[[UIAlertView alloc] initWithTitle:@""
                                        message:[AppotaPaymentSDKLanguage get:@"Đang xác nhận giao dịch, vui lòng chờ."]
                                       delegate:nil
                              cancelButtonTitle:@"OK" otherButtonTitles:nil, nil] show];
        }
        if (paymentState == AppotaPaymentFailed) {
            [[[UIAlertView alloc] initWithTitle:[AppotaPaymentSDKLanguage get:@"Thông báo"]
                                        message:[resultDict objectForKey:@"message"]
                                       delegate:nil
                              cancelButtonTitle:@"OK" otherButtonTitles:nil, nil] show];            
        }
    }
}

- (IBAction)showSMSWithAmount:(id)sender {
    AppotaPayment *appotaPayment = [AppotaPayment shareAPI];
    [appotaPayment makeSMSPaymentWithAmount:500 withState:@"" withTarget:@"" withNoticeUrl:@"" withCompletionHandler:^(NSDictionary *apiDict, AppotaPaymentState status, NSError *error) {
        [self handleSMSPaymentResultDict:apiDict withPaymentState:status];
    }];
}

- (IBAction)showSMSWithState:(id)sender {
    AppotaPayment *appotaPayment = [AppotaPayment shareAPI];
    [appotaPayment makeSMSPaymentWithState:@"" withTarget:@"" withNoticeUrl:@"" withDescription:@"500 d => 100 coin\n5k=>1000 coin\n15k=>10000 coin" withCompletionHandler:^(NSDictionary *apiDict, AppotaPaymentState status, NSError *error) {
        [self handleSMSPaymentResultDict:apiDict withPaymentState:status];
    }];
}

- (IBAction)showSMSWithListAmount:(id)sender {
    AppotaPayment *appotaPayment = [AppotaPayment shareAPI];
    [appotaPayment makeSMSPaymentWithListAmount:[NSArray arrayWithObjects:[NSNumber numberWithInt:500], nil] withState:@"" withTarget:@"" withNoticeUrl:@"" withDescription:@"500 d => 100 coin" withCompletionHandler:^(NSDictionary *apiDict, AppotaPaymentState status, NSError *error) {
        [self handleSMSPaymentResultDict:apiDict withPaymentState:status];        
    }];
}
@end
