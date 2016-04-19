//
//  AppotaAPIConstant.h
//  AppotaSDK
//
//  Created by Appota on 1/22/13.
//  Copyright (c) 2013 Appota. All rights reserved.
//

#ifndef AppotaSDK_AppotaAPIConstant_h
#define AppotaSDK_AppotaAPIConstant_h

#define APPOTA_SCHEMA @"appota"

#define APPOTA_OAUTH_REQUEST_TOKEN_URL @"https://id.appota.com/oauth/request_token"
#define APPOTA_APP_REQUEST_TOKEN_URL @"https://id.appota.com/app/request_token"
#define APPOTA_OAUTH_ACCESS_TOKEN_URL @"https://id.appota.com/oauth/access_token"
#define APPOTA_APP_ACCESS_TOKEN_URL @"https://id.appota.com/app/access_token"
#define APPOTA_APP_REFRESH_TOKEN_URL @"https://id.appota.com/oauth/refresh_token"

#define PAYMENT_TOPUP_BANK @"https://api.appota.com/payment/topup_bank?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"
#define PAYMENT_TOPUP_PAYPAL @"https://api.appota.com/payment/topup_paypal?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"
#define PAYMENT_TOPUP_SMS @"https://api.appota.com/payment/topup_sms?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"
#define PAYMENT_TOPUP_CARD @"https://api.appota.com/payment/topup_card?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"
#define PAYMENT_TOPUP @"https://api.appota.com/payment/topup?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"

#define PAYMENT_INAPP_BANK @"https://api.appota.com/payment/inapp_bank?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"
#define PAYMENT_INAPP_PAYPAL @"https://api.appota.com/payment/inapp_paypal?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"
#define PAYMENT_INAPP_SMS @"https://api.appota.com/payment/inapp_sms?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"
#define PAYMENT_INAPP_CARD @"https://api.appota.com/payment/inapp_card?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"
#define PAYMENT_INAPP @"https://api.appota.com/payment/inapp?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"
#define PAYMENT_DETAIL @"https://pay.appota.com/payment/detail?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"

#define USER_BASIC_INFO @"https://api.appota.com/user/info?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"
#define USER_FACEBOOK_LOGIN @"https://api.appota.com/user/facebook_login?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"

#define AVAIABLE_STORE_URL @"http://api.appota.com/client/checkavaionstore"

#define ITEM_INAPP_LIST @"https://api.appota.com/item/get_list?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"
#define ITEM_INAPP_CHECKBOUGHT_LIST @"https://api.appota.com/item/bought?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"
#define ITEM_INAPP_ISBOUGHT @"https://api.appota.com/item/is_bought?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"
#define ITEM_INAPP_BUY @"https://api.appota.com/item/buy?access_token=<ACCESS_TOKEN>&lang=<LANG_SETTING>"

#define TOP_UP_TYM_WEB @"https://pay.appota.com/payment?access_token="
#define TOP_UP_LIST_ITEMS_WEB @"https://pay.appota.com/items?action=listitem&access_token="
#define TOP_UP_BUY_ITEMS_WEB @"https://pay.appota.com/items?action=buyitem&access_token="

#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)

#endif
