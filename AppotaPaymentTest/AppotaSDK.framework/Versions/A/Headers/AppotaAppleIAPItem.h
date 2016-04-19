//
//  InAppPurchaseItem.h
//  AppotaSDK
//
//  Created by tuent on 10/23/13.
//
//

#import <Foundation/Foundation.h>

@interface AppotaAppleIAPItem : NSObject
{
    NSString *productId;
    NSString *description;
    float price;
}

#pragma mark - Getter and setter
- (id) initWithProductID:(NSString*) productId_
               withPrice:(float) price_
         withDescription:(NSString*) description_;

- (NSString *)productId;

- (void)setProductId:(NSString *)newValue;

- (NSString *)description;

- (void)setDescription:(NSString *)newValue;

- (float)price;

- (void)setPrice:(float)newValue;

@end
